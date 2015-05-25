// Wonsz9000 - Window implementation.

#include "window.hpp"

// Private helpers:
void initGLFW();
void setHints(std::map<int, int> const&);
void initInput(GLFWwindow * const);

Window::Window(
    std::string const title,
    uint const width,
    uint const height,
    std::map<int, int> const& hints)
{
    initGLFW();
    setHints(hints);
    
    glfw_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    glfwMakeContextCurrent(glfw_window);
    
    initInput(glfw_window);
}

Window::~Window()
{
    if (glfw_window)
    {
        glfwDestroyWindow(glfw_window);
    }
    
    glfwTerminate();
}

void Window::runWhile(std::function<bool()> const& predicate)
{
    do {
        glfwSwapBuffers(glfw_window);
        glfwPollEvents();
    } while (predicate && !glfwWindowShouldClose(glfw_window));
}

void initGLFW()
{
    if (!glfwInit())
    {
        throw new Window::SystemInitFailed;
    }
}

void setHints(std::map<int, int> const& hints)
{
    for (auto const& pair : hints)
    {
        glfwWindowHint(pair.first, pair.second);
    }
}

void initInput(GLFWwindow * const glfw_window)
{
    glfwSetInputMode(glfw_window, GLFW_STICKY_KEYS, GL_TRUE);
}
