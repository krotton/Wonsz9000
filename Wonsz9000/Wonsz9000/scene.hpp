// Wonsz9000 - scene management

#pragma once

/**
 * Contains objects in 3D space and manages their lifecycle.
 */
class Scene
{
    
public:
    // Initializes an empty scene attached to the given window's context.
    Scene(std::shared_ptr<GLFWwindow> glfw_window);
    
    // Destroys the scene, freeing all resources.
    virtual ~Scene();
    
    // Renders the scene in its current state.
    void render() const;
    
protected:
    std::shared_ptr<GLFWwindow> glfw_window;
};
