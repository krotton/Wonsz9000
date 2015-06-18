// Wonsz9000 - common Renderables' functionality.

#include "renderable.hpp"

void Renderable::render() const
{
    if (bound)
    {
        draw();
    }
}

void Renderable::bind() const
{
    bound = true;
}