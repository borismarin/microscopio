from clang import cindex

index = cindex.Index.create()
tu = index.parse('./NiFpga.h')

def format_type(ty):
    if '*' in ty:
        return "%p"
    elif 'float' in ty or 'double' in ty:
        return "%f"
    else:
        return "%d"

def gen_func(func):
    sig = ""
    sig += func.result_type.spelling + ' '
    sig += func.spelling.replace('NiFpga', 'NiFpgaDll')
    sig += '('
    
    body = ""
    body += f'\tprintf("{ func.spelling }\\n");\n'

    for arg in func.get_arguments():
        sig += arg.type.spelling + ' '
        sig += arg.spelling + ', '

        body += f'\tprintf("\\t{ arg.spelling } = { format_type(arg.type.spelling) }\\n", { arg.spelling });\n'
    sig += ') {'
    body += '\treturn NiFpga_Status_Success;\n'
    body += '}'
    print(sig.replace(', )', ')'))
    print(body)
    print("")

functions = filter(lambda x: x.kind == cindex.CursorKind.FUNCTION_DECL, tu.cursor.get_children())

print('#include "NiFpga.h"\n')

for func in functions:
    gen_func(func)
