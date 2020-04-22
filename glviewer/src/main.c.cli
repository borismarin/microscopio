#include <stdint.h>
#include <stdio.h>

#include <GL/glew.h>
#include <GL/freeglut.h>

#include <aoldaq/aoldaq.h>

#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#define sleep(x) Sleep((x) * 1000)
#else
#include <unistd.h>
#endif

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "shader.h"
#include "vao.h"
#include "texture.h"

#define WIDTH 10
#define HEIGHT 5

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

void print_data(uint32_t *ptr, uint32_t width, uint32_t height) {
    for(int j = 0; j < height; j++) {
        printf("[ ");
        for(int i = 0; i < width; i++) {
            printf("%2d ", ptr[j*width + i]);
        }
        printf("]\n");
    }
}

uint32_t *generate_bitmap(uint32_t width, uint32_t height) {
    uint32_t *ptr = malloc(sizeof(uint32_t) * width * height);

    for(int j = 0; j < height; j++) {
        for(int i = 0; i < width; i++) {
            ptr[i + j * width] = i + j * width;
        }
    }

    return ptr;
}

void update_data() {
    uint32_t n = aoldaq_get_ramps(p_aoldaq, 1, p_ramp);

    glBindTexture(GL_TEXTURE_2D, quad_tex);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, WIDTH, HEIGHT, 0, 
            GL_RED, GL_UNSIGNED_INT, &p_ramp->voxels[0][0]);

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
    uint32_t *bitmap_data = generate_bitmap(WIDTH, HEIGHT);

    printf("Generated data:\n");
    print_data(bitmap_data, WIDTH, HEIGHT);

    aoldaq_scan_params_t scan_params = {
        AOLDAQ_IMAGING_MODE_RASTER,
        WIDTH * HEIGHT
    };

    aoldaq_args_t args = {
        .block_size = 5,
        .mode = AOLDAQ_MODE_BITMAP,
        .scan_params = scan_params,
        .bitmap_data = bitmap_data,
        .bitmap_width = WIDTH,
        .bitmap_height = HEIGHT,
    };

    printf("Creating AOLDAQ instance...\n");
    p_aoldaq = aoldaq_create_instance(&args);

    if(!p_aoldaq) {
        printf("Failed to create aoldaq instance.\n");
        return -1;
    }

    p_ramp = (ramp_t *) malloc(sizeof(ramp_t));

    aoldaq_start(p_aoldaq);
    sleep(5);

    for(int i = 0; i < 1; i++) {
        aoldaq_get_ramps(p_aoldaq, 1, p_ramp);
        printf("Received data iter %d:\n", i);
        print_data(p_ramp->voxels[0], WIDTH, HEIGHT);
    }
    aoldaq_stop(p_aoldaq);

    printf("Destroying AOLDAQ instance...\n");
    aoldaq_destroy_instance(p_aoldaq);

    return 0;
}
