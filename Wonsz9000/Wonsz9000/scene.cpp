// Wonsz9000 - scene management implementation

#include "scene.hpp"

Scene::Scene(std::shared_ptr<GLFWwindow> const glfw_window,
             unsigned const win_width,
             unsigned const win_height)
{
    if (glfw_window)
    {
        bind(glfw_window, win_width, win_height);
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
    
    shaders->activate();
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    for (auto& r : renderables)
    {
        auto const mvp_mat = projection_matrix() * camera_matrix() * r.second->transformation();
        shaders->provide_uniform("MVP", mvp_mat);
        
        r.second->render();
        r.second->update();
    }
    
    shaders->deactivate();
    
    glfwSwapBuffers(glfw_window.get());
}

Scene::renderable_id_t Scene::add(std::shared_ptr<Renderable> renderable)
{
    auto const id = max_renderable_id++;
    renderables[id] = renderable;
    
    if (glfw_window)
    {
        renderable->bind();
    }
    
    return id;
}

void Scene::remove(Scene::renderable_id_t const id)
{
    if (!renderables.erase(id))
    {
        throw InvalidRenderableId();
    }
}

void Scene::bind(std::shared_ptr<GLFWwindow> const glfw_window,
                 unsigned const win_width,
                 unsigned const win_height) const
{
    this->glfw_window = glfw_window;
    this->win_width = win_width;
    this->win_height = win_height;
    
    glGenVertexArrays(1, &vao_id);
    glBindVertexArray(vao_id);
    
    for (auto const& r: renderables)
    {
        r.second->bind();
    }
    
    shaders = std::unique_ptr<ShaderProgram>{new ShaderProgram({
        {ShaderProgram::Vertex, "default.vertex.glsl"},
        {ShaderProgram::Fragment, "default.fragment.glsl"}
    })};
}
