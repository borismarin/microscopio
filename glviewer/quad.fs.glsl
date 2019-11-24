#version 430 core

layout(location = 0) in vec2 fs_TexCoord;

out vec4 out_Color;

uniform sampler2D _Channel0;

void main() {
    //out_Color = vec4(fs_TexCoord, 0.0, 1.0);
    //float val = 2.0 * texture2D(_Channel0, fs_TexCoord).r / 4294967295.0;
    //out_Color = vec4(vec3(val), 1.0);
    out_Color = vec4(texture2D(_Channel0, fs_TexCoord).rgb, 1.0);
}
