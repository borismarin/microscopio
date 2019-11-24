#include <stdint.h>
#include <stdio.h>

#include <GL/glew.h>
#include <GL/freeglut.h>

#include <aoldaq/aoldaq.h>

#include "shader.h"
#include "vao.h"
#include "texture.h"

#define WIDTH 500
#define HEIGHT 500

static float quad_positions[6][3] = {
    { 1.0, 1.0, 0.0 },      // Top Right
    { -1.0, 1.0, 0.0 },     // Top Left
    { 1.0, -1.0, 0.0 },     // Bot Right
    { 1.0, -1.0, 0.0 },     // Bot Right
    { -1.0, 1.0, 0.0 },     // Top Left
    { -1.0, -1.0, 0.0 }     // Bot Left
};

static float quad_uvs[6][2] = {
    { 1.0, 1.0 },   // Top Right
    { 0.0, 1.0 },   // Top Left
    { 1.0, 0.0 },   // Bot Right
    { 1.0, 0.0 },   // Bot Right
    { 0.0, 1.0 },   // Top Left
    { 0.0, 0.0 }    // Bot Left
};

static GLuint quad_shader;
static GLuint quad_vao;
static GLuint quad_tex;

static aoldaq_t *p_aoldaq;
static ramp_t *p_ramp;

void update_frame() {
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(quad_shader);
    glBindVertexArray(quad_vao);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, quad_tex);

    GLuint location = glGetUniformLocation(quad_shader, "_Channel0");
    glUniform1i(location, 0);

    glDrawArrays(GL_TRIANGLES, 0, 6);

    glutSwapBuffers();
}

void update_data() {
    aoldaq_get_ramps(p_aoldaq, 1, p_ramp);

    glBindTexture(GL_TEXTURE_2D, quad_tex);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, WIDTH, HEIGHT, 0, 
            GL_RED, GL_UNSIGNED_INT, &p_ramp->voxels[0][0]);

    /*printf("%g\n", 2.0 * p_ramp->voxels[0][0] / 4294967295.0);*/

    glutPostRedisplay();
}

void setup_gl_objects(uint32_t width, uint32_t height) {
    quad_shader = create_shader_program("quad.vs.glsl", "quad.fs.glsl");
    quad_vao = create_vao(&quad_positions[0][0], &quad_uvs[0][0], 6);
    quad_tex = create_texture(width, height);
}

// Creates the window
void setup_window(uint32_t width, uint32_t height) {
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(width, height);
    glutInitContextVersion(4,3);
    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
    glutCreateWindow("AOLDAQ Live Viewer");

    glewExperimental = 1;
    glewInit();

    setup_gl_objects(width, height);

    glutDisplayFunc(&update_frame);
    glutIdleFunc(&update_data);
}

int main(int argc, char* argv[]) {
    aoldaq_scan_params_t scan_params = {
        AOLDAQ_IMAGING_MODE_RASTER,
        WIDTH * HEIGHT
    };

    aoldaq_args_t args = {
        200,
        scan_params
    };

    printf("Creating AOLDAQ instance...\n");
    p_aoldaq = aoldaq_create_instance(&args);

    p_ramp = (ramp_t *) malloc(sizeof(ramp_t));

    if(!p_aoldaq) {
        printf("Failed to create aoldaq instance.\n");
        return -1;
    }

    glutInit(&argc, argv);
    setup_window(WIDTH, HEIGHT);

    aoldaq_start(p_aoldaq);
    glutMainLoop();
    aoldaq_stop(p_aoldaq);

    printf("Destroying AOLDAQ instance...\n");
    aoldaq_destroy_instance(p_aoldaq);

    return 0;
}
