#version 430 core

layout(location = 0) in vec2 fs_TexCoord;

layout(location = 0) out vec4 out_Color;

uniform sampler2D _Channel0;
uniform sampler2D _Channel1;

void main() {
    //out_Color = vec4(fs_TexCoord, 0.0, 1.0);
    //float val = 2.0 * texture2D(_Channel0, fs_TexCoord).r / 4294967295.0;
    //out_Color = vec4(vec3(val), 1.0);
    float r = texture2D(_Channel0, fs_TexCoord).r;
    float b = texture2D(_Channel1, fs_TexCoord).r;
    //out_Color = vec4(texture2D(_Channel0, fs_TexCoord).rgb, 1.0);
    out_Color = vec4(r, 0.0, b, 1.0);
}
