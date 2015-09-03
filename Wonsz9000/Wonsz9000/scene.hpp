// Wonsz9000 - scene management

#pragma once

#include "renderable/renderable.hpp"
#include "shader.hpp"

/**
 * Contains objects in 3D space and manages their lifecycle.
 */
class Scene
{
public: // types
    using renderable_id_t = uint;
    
public:
    // Initializes an empty scene attached to the given window's context.
    Scene(std::shared_ptr<GLFWwindow> const glfw_window = nullptr,
          unsigned const win_width = 0,
          unsigned const win_height = 0);
    
    // Destroys the scene, freeing all resources.
    virtual ~Scene();
    
    // Renders the scene in its current state.
    void render() const;
    
    // Attaches the given window's context. Until context is attached,
    // rendering is impossible.
    void bind(std::shared_ptr<GLFWwindow> const glfw_window,
              unsigned const win_width,
              unsigned const win_height) const;
    
    // Adds a new renderable to the scene.
    // Returns an identifier that can be used to remove the renderable later.
    renderable_id_t add(std::shared_ptr<Renderable> renderable);
    
    // Removes a renderable with the given id from the scene.
    // If the id doesn't match any renderable, an InvalidRenderableId exception is thrown.
    void remove(renderable_id_t const id);
    
public: // exceptions
    struct InvalidRenderableId: public std::exception {};
    
protected:
    mutable std::shared_ptr<GLFWwindow> glfw_window;
    mutable unsigned win_width, win_height;
    
    mutable GLuint vao_id;
    
    renderable_id_t max_renderable_id = 0;
    std::map<renderable_id_t, std::shared_ptr<Renderable>> renderables;
    
    mutable std::unique_ptr<ShaderProgram> shaders = nullptr;
    
    inline glm::mat4 const& camera_matrix() const
    {
        static glm::mat4 view_mat = glm::lookAt(glm::vec3(4, 3, 3),
                                                glm::vec3(0, 0, 0),
                                                glm::vec3(0, 1, 0));
        
        return view_mat;
    }
    
    inline glm::mat4 const& projection_matrix() const
    {
        static glm::mat4 proj_mat = glm::perspective(45.0f,
                                                     static_cast<float>(win_width) / static_cast<float>(win_height),
                                                     0.1f,
                                                     100.0f);
        
        return proj_mat;
    }
};
