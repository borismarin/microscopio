#include "texture.h"

GLuint create_texture(unsigned int width, unsigned int height) {
    GLuint text;
    glGenTextures(1, &text);

    glBindTexture(GL_TEXTURE_2D, text);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, width, height, 0, GL_RED, GL_UNSIGNED_INT, 0);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    
    return text;
}
