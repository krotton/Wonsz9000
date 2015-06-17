// Wonsz9000 - the window class.

#pragma once

#include "scene.hpp"

/*
 * Represents the main window with the main OpenGL context bound.
 * All the rendering happens here.
 */
class Window {

public:
    // Creates and displays a new, fully initialized window with the given
    // title, dimensions and hints. Initializes GLFW.
    Window(
        std::string const title,
        uint const width,
        uint const height,
        std::map<int, int> const& hints = {{}});
    
    // Destroys the window and kills GLFW.
    virtual ~Window();
    
    // Attaches a scene to this window. If there is already a scene attached,
    // it is replaced by the new one.
    void attach(std::shared_ptr<Scene const> const scene);
    
    // Registers a handler function that will be called when closing
    // is requested by the user.
    void on_quit(std::function<void()> const& quit_handler);
    
    // Runs the main loop as long as the given predicate is true.
    void run_while(std::function<bool()> const& predicate);
    
public: // exceptions:
    // Thrown whenever GLFW fails to initialize.
    struct SystemInitFailed: public std::exception {};
    
    // Thrown whenever window creation fails.
    struct WindowCreationFailed: public std::exception {};
    
protected:
    // The GLFW window handle.
    std::shared_ptr<GLFWwindow> glfw_window;
    
    // The active scene.
    std::shared_ptr<Scene const> scene;
    
    // On quit callback.
    std::function<void()> quit_handler;
};
