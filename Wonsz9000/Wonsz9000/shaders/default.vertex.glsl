#version 410 core

in vec3 position_modelspace;
uniform mat4 MVP;

void main()
{
    vec4 v = vec4(position_modelspace, 1);
    gl_Position = MVP * v;
}
