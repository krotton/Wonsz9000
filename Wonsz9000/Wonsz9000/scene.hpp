// Wonsz9000 - scene management

#pragma once

#include "renderable/renderable.hpp"

/**
 * Contains objects in 3D space and manages their lifecycle.
 */
class Scene
{
public: // types
    using renderable_id_t = uint;
    
public:
    // Initializes an empty scene attached to the given window's context.
    Scene(std::shared_ptr<GLFWwindow> const glfw_window = nullptr);
    
    // Destroys the scene, freeing all resources.
    virtual ~Scene();
    
    // Renders the scene in its current state.
    void render() const;
    
    // Attaches the given window's context. Until context is attached,
    // rendering is impossible.
    void bind(std::shared_ptr<GLFWwindow> const glfw_window) const;
    
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
    mutable GLuint vao_id;
    renderable_id_t max_renderable_id = 0;
    
    std::map<renderable_id_t, std::shared_ptr<Renderable>> renderables;
};
