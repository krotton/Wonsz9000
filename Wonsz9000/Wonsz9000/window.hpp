// Wonsz9000 - the window class.

#pragma once

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
    
    // Runs the main loop as long as the given predicate is true.
    void runWhile(std::function<bool()> const& predicate);
    
public: // exceptions:
    // Thrown whenever GLFW fails to initialize.
    struct SystemInitFailed: public std::exception {};
    
    // Thrown whenever window creation fails.
    struct WindowCreationFailed: public std::exception {};
    
protected:
    // The GLFW window handle.
    GLFWwindow *glfw_window;
};
