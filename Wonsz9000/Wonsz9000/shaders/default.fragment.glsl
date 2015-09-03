#version 410 core

in vec2 fragment_uv;

out vec3 color;

uniform sampler2D tex_sampler;

void main()
{
    color = texture(tex_sampler, fragment_uv).rgb;
}
