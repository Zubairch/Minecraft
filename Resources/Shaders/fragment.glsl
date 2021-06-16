#Fragment Shader

#version 330 core

out vec4 o_FragmentColor;
in vec2 o_TexCoord;

uniform sampler2D u_Texture;

void main() {
    
    o_FragmentColor = texture(u_Texture, o_TexCoord);
}