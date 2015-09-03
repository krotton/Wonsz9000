#version 410 core

layout(location = 0) in vec3 modelspace_pos;
layout(location = 1) in vec3 vertex_color;

out vec3 fragment_color;

uniform mat4 MVP;

void main()
{
    vec4 v = vec4(modelspace_pos, 1);
    gl_Position = MVP * v;
    
    fragment_color = vertex_color;
}
