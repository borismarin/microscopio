#include <stdint.h>
#include <stdio.h>

#include <GL/glew.h>
#include <GL/freeglut.h>

#define AOL_USE_NIFPGA
#include <aoldaq/aoldaq.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "shader.h"
#include "vao.h"
#include "texture.h"

#define WIDTH 400
#define HEIGHT 400

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
static GLuint quad_tex[2];

static aoldaq_t *p_aoldaq;
static uint32_t *buf0;
static uint32_t *buf1;

uint32_t *generate_bitmap(uint32_t width, uint32_t height) {
    uint32_t *ptr = malloc(sizeof(uint32_t) * width * height);

    for(int j = 0; j < height; j++) {
        for(int i = 0; i < width; i++) {
            int ni = i / 20;
            int nj = j / 20;
            ptr[i + j * width] = (ni + nj) % 2 == 0 ? UINT32_MAX : 0;
        }
    }

    return ptr;
}

void update_frame() {
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(quad_shader);
    glBindVertexArray(quad_vao);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, quad_tex[0]);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, quad_tex[1]);

    GLuint location0 = glGetUniformLocation(quad_shader, "_Channel0");
    glUniform1i(location0, 0);
    GLuint location1 = glGetUniformLocation(quad_shader, "_Channel1");
    glUniform1i(location1, 1);

    glDrawArrays(GL_TRIANGLES, 0, 6);

    glutSwapBuffers();
}

void update_data() {
    uint32_t n0 = aoldaq_get_voxels(p_aoldaq, 0, buf0, WIDTH * HEIGHT);
    uint32_t n1 = aoldaq_get_voxels(p_aoldaq, 1, buf1, WIDTH * HEIGHT);

    glBindTexture(GL_TEXTURE_2D, quad_tex[0]);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, WIDTH, HEIGHT, 0, 
            GL_RED, GL_UNSIGNED_INT, buf0);

    glBindTexture(GL_TEXTURE_2D, quad_tex[1]);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, WIDTH, HEIGHT, 0, 
            GL_RED, GL_UNSIGNED_INT, buf1);

    /*printf("%g\n", 2.0 * p_ramp->voxels[0][0] / 4294967295.0);*/

    glutPostRedisplay();
}

void setup_gl_objects(uint32_t width, uint32_t height) {
    quad_shader = create_shader_program("quad.vs.glsl", "quad.fs.glsl");
    quad_vao = create_vao(&quad_positions[0][0], &quad_uvs[0][0], 6);
    quad_tex[0] = create_texture(width, height);
    quad_tex[1] = create_texture(width, height);
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
    uint32_t *bitmap_data = generate_bitmap(WIDTH, HEIGHT);

    aoldaq_scan_params_t scan_params = {
        AOLDAQ_IMAGING_MODE_RASTER,
        WIDTH * HEIGHT
    };

    aoldaq_args_t args = {
        .block_size = 200,
        .mode = AOLDAQ_MODE_REAL,
        .scan_params = scan_params,
        /*.bitmap_data = bitmap_data,*/
        /*.bitmap_width = WIDTH,*/
        /*.bitmap_height = HEIGHT,*/
        .nifpga_bitfile = "/gimme/chocolate",
        .nifpga_signature = "atotallycorrectsignature",
        .nifpga_resource = "RIO/de/janeiro",
        .n_channels = 2,
    };

    printf("Creating AOLDAQ instance...\n");
    p_aoldaq = aoldaq_create_instance(&args);

    if(!p_aoldaq) {
        printf("Failed to create aoldaq instance.\n");
        return -1;
    }

    buf0 = malloc(sizeof(uint32_t) * WIDTH * HEIGHT);
    buf1 = malloc(sizeof(uint32_t) * WIDTH * HEIGHT);

    glutInit(&argc, argv);
    setup_window(WIDTH, HEIGHT);

    aoldaq_start(p_aoldaq);
    glutMainLoop();
    aoldaq_stop(p_aoldaq);

    printf("Destroying AOLDAQ instance...\n");
    aoldaq_destroy_instance(p_aoldaq);

    free(buf0);
    free(buf1);

    return 0;
}
