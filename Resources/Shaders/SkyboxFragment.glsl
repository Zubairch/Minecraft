#Fragment Shader

#version 330 core

out vec4 o_FragmentColor;

in vec3 o_TexCoords;

uniform samplerCube u_Skybox;

void main() {
        
    o_FragmentColor = texture(u_Skybox, o_TexCoords);
}