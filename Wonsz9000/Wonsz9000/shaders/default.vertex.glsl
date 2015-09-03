#version 410 core

layout(location = 0) in vec3 modelspace_pos;
layout(location = 1) in vec2 vertex_uv;

out vec2 fragment_uv;

uniform mat4 MVP;

void main()
{
    vec4 v = vec4(modelspace_pos, 1);
    gl_Position = MVP * v;
    
    fragment_uv = vertex_uv;
}
