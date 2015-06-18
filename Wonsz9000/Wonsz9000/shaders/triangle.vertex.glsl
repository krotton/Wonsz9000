#version 410 core

layout(location = 0) in vec3 pos_modelspace;

void main()
{
    gl_Position.xyz = pos_modelspace;
    gl_Position.w = 1.0;
}
