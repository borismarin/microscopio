#include <stdlib.h>
#include <stdio.h>

#include "shader.h"
#include "util.h"

GLuint create_shader_program(const char *vertex, const char *fragment) {
    GLuint program = glCreateProgram();

    FILE *vs_file = fopen(vertex, "r");
    FILE *fs_file = fopen(fragment, "r");
    
    unsigned int vs_src_len;
    unsigned int fs_src_len;
    const char *vs_src = read_file(vs_file, &vs_src_len);
    const char *fs_src = read_file(fs_file, &fs_src_len);

    fclose(vs_file);
    fclose(fs_file);

    GLuint vs = create_shader(GL_VERTEX_SHADER, vs_src, vs_src_len);
    GLuint fs = create_shader(GL_FRAGMENT_SHADER, fs_src, fs_src_len);

    glAttachShader(program, vs);
    glAttachShader(program, fs);

    glLinkProgram(program);

    return program;
}

static GLuint create_shader(GLenum type, const char* source, int len) {
    GLuint shader = glCreateShader(type);

    glShaderSource(shader, 1, &source, &len);
    glCompileShader(shader);

    check_error(shader);

    return shader;
}

static void check_error(GLuint shader) {
    GLint compile_status;

    glGetShaderiv(shader, GL_COMPILE_STATUS, &compile_status);

    if(compile_status != GL_TRUE) {
        // Error!

        GLint info_log_length;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &info_log_length);

        char *info_log = (char*) malloc(sizeof(char) * info_log_length);
        glGetShaderInfoLog(shader, info_log_length, &info_log_length, info_log);

        printf("Could not compile shader!\n");
        printf("%s\n", info_log);
    }
}
