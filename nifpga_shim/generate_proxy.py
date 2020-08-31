from clang import cindex

index = cindex.Index.create()
tu = index.parse('./NiFpga.h')

def gen_fptr_type(func):
    args_str = ', '.join([ arg.type.spelling for arg in func.get_arguments() ]) or 'void'
    return f'typedef { func.result_type.spelling } (*_real_{ func.spelling }_t)({ args_str });'

def gen_fptr_decl(func):
    return f'static _real_{ func.spelling }_t _real_{ func.spelling } = NULL;'

# TODO refactor this because I just copypasted from the shim
def gen_fptr_use(func, extra_code=''):
    sig = ""
    sig += func.result_type.spelling + ' '
    sig += func.spelling.replace('NiFpga', 'NiFpgaDll')
    sig += '('
    
    body = ''
    body += extra_code
    body += f'\tfprintf(outfile, "{ func.spelling }\\n");\n'

    for arg in func.get_arguments():
        sig += arg.type.spelling + ' '
        sig += arg.spelling + ', '

        body += f'\tfprintf(outfile, "\\t{ arg.spelling } = { format_type(arg.type.spelling) }\\n", { arg.spelling });\n'
    sig += ') {'
    arg_str = ', '.join([ arg.spelling for arg in func.get_arguments() ]);
    body += f'\treturn _real_{ func.spelling } ? _real_{ func.spelling }({ arg_str }) : NiFpga_Status_ResourceNotInitialized;\n'
    body += '}'

    ret = '';
    ret += (sig.replace(', )', ')'))
    ret += '\n'
    ret += body

    return ret

def gen_fptr_use2(func, extra_code=''):
    ret = ''
    arg_str = ', '.join([ f'{ a.type.spelling } { a.spelling }' for a in func.get_arguments() ])
    ret += f'{ func.result_type.spelling } { func.spelling.replace("NiFpga", "NiFpgaDll") } ({ arg_str }) {{\n'
    ret += extra_code
    ret += '\n'.join([])
    # TODO finish this

def format_type(ty):
    if '*' in ty:
        return "%p"
    elif 'float' in ty or 'double' in ty:
        return "%f"
    else:
        return "%d"

def gen_fptr_load_unix(func):
    sym_name = func.spelling.replace('NiFpga', 'NiFpgaDll')
    return f'_real_{ func.spelling } = (_real_{ func.spelling }_t) dlsym(handle, \"{ sym_name }\");'

def gen_fptr_load_win(func):
    sym_name = func.spelling.replace('NiFpga', 'NiFpgaDll')
    return f'_real_{ func.spelling } = (_real_{ func.spelling }_t) GetProcAddress(handle, \"{ sym_name }\");'

def gen_header():
    return """
#include <stdio.h>
#include <string.h>
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#else
#include <dlfcn.h>
#endif
#include "NiFpga.h"

static FILE *outfile;

#ifdef _WIN32
HMODULE handle;
#else
void *handle;
#endif

static void _proxy_load_fns();

static void _proxy_init() {
    char* tmp = getenv("TEMP");
    size_t tmp_len = strlen(tmp);
    char outfile_path[tmp_len + 25];
    sprintf(outfile_path, "%s/NiFpga_Proxy.log", tmp);

    outfile = fopen(outfile_path, "a");
    fprintf(outfile, "===== LOADING PROXY =====\\n");

#ifdef WIN32
    handle = LoadLibraryA("NiFpga.real.dll");
#else
    handle = dlopen("libNiFpga.real.so, RTLD_LAZY");
#endif

    _proxy_load_fns();
}

static void _proxy_deinit() {
    fclose(outfile);
#ifdef WIN32
    FreeLibrary(handle);
#else
    dlclose(handle);
#endif
}
"""

def gen_load_fns(fns):
    body = 'static void _proxy_load_fns() {\n'
    body += '\n'.join([ '\t' + gen_fptr_load_win(f) for f in fns ])
    body += '\n}\n'
    return body

functions = list(filter(lambda x: x.kind == cindex.CursorKind.FUNCTION_DECL, tu.cursor.get_children()))

# print('#include "NiFpga.h"\n')

print(gen_header())
print('\n'.join([ gen_fptr_type(f) for f in functions ]))
print('')
print('\n'.join([ gen_fptr_decl(f) for f in functions ]))
print('')
print('\n'.join([ gen_fptr_use(f) for f in functions if not f.spelling in ["NiFpga_Open", "NiFpga_Close"] ]))
print('')
print('\n'.join([ gen_fptr_use(f, '\t_proxy_init();\n') for f in functions if f.spelling == "NiFpga_Open" ]))
print('')
print('\n'.join([ gen_fptr_use(f, '\t_proxy_deinit();\n') for f in functions if f.spelling == "NiFpga_Close" ]))
print('')
# print(gen_fptr_load_win(functions[0]))
print(gen_load_fns(functions))
