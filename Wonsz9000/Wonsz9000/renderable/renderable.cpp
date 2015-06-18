// Wonsz9000 - common Renderables' functionality.

#include "renderable.hpp"

void Renderable::render() const
{
    bind();
    draw();
    cleanup();
}
