#include <GL/glew.h>

GLuint create_shader_program(const char *vertex, const char *fragment);

static GLuint create_shader(GLenum type, const char* source, int len);
static void check_error(GLuint shader);
