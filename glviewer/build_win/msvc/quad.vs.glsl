#version 430 core

layout(location = 0) in vec3 vs_Position;
layout(location = 1) in vec2 vs_TexCoord;

layout(location = 0) out vec2 fs_TexCoord;

void main() {
    gl_Position = vec4(vs_Position, 1.0);
    
    fs_TexCoord = vs_TexCoord;
}
