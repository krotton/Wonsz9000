// Wonsz9000 - scene management implementation

#include "scene.hpp"

void Scene::render() const
{
    glfwSwapBuffers(glfw_window.get());
}
