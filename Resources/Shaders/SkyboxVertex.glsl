#Vertex Shader

#version 330 core

layout (location = 0) in vec3 a_Position;

out vec3 o_TexCoords;

uniform mat4 u_ViewProjectionMatrix = mat4(1.0f);

void main() {

    o_TexCoords = a_Position;
    gl_Position = vec4(u_ViewProjectionMatrix * vec4(a_Position, 1.0)).xyww;
}  
