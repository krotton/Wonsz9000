// Wonsz9000 - scene management implementation

#include "scene.hpp"

Scene::Scene(std::shared_ptr<GLFWwindow> const glfw_window)
{
    if (glfw_window)
    {
        bind(glfw_window);
    }
}

Scene::~Scene()
{
    if (glfw_window)
    {
        // Deinit.
    }
}

void Scene::render() const
{
    if (!glfw_window)
    {
        return;
    }
    
    for (auto& r : renderables)
    {
        r.second.get()->render();
        r.second.get()->update();
    }
    
    glfwSwapBuffers(glfw_window.get());
}

Scene::renderable_id_t Scene::add(std::shared_ptr<Renderable> renderable)
{
    auto const id = max_renderable_id++;
    renderables[id] = renderable;
    
    return id;
}

void Scene::remove(Scene::renderable_id_t const id)
{
    if (!renderables.erase(id))
    {
        throw InvalidRenderableId();
    }
}

void Scene::bind(std::shared_ptr<GLFWwindow> const glfw_window) const
{
    this->glfw_window = glfw_window;
    
    glGenVertexArrays(1, &vao_id);
    glBindVertexArray(vao_id);
}
