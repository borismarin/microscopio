#include "vao.h"

GLuint create_vao(float *vertices, float *uvs, unsigned int n) {
    GLuint vao;
    glGenVertexArrays(1, &vao);

    glBindVertexArray(vao);

    GLuint vbos[2];
    glGenBuffers(2, vbos);

    // buffer 0: positions
    glBindBuffer(GL_ARRAY_BUFFER, vbos[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 3 * n, vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(0);

    // buffer 1: tex coords
    glBindBuffer(GL_ARRAY_BUFFER, vbos[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 2 * n, uvs, GL_STATIC_DRAW);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(1);

    return vao;
}
