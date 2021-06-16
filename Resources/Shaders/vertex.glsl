#Vertex Shader

#version 330 core
layout (location = 0) in vec3 a_Position;
layout (location = 1) in vec2 a_TexCoord;

out vec2 o_TexCoord;

uniform mat4 u_Model = mat4(1.0f);
uniform mat4 u_View = mat4(1.0f);
uniform mat4 u_Projection =  mat4(1.0f);

void main() {
    
    gl_Position = u_Projection * u_View * u_Model * vec4(a_Position, 1.0f);
    o_TexCoord = a_TexCoord;
}