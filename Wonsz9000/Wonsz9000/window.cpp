// Wonsz9000 - Window implementation.

#include "window.hpp"

// Private helpers:
void init_glfw();
void set_hints(std::map<int, int> const&);
void init_input(GLFWwindow* const);

Window::Window(std::string const title,
               unsigned const width,
               unsigned const height,
               std::map<int, int> const& hints):
    win_width(width), win_height(height)
{
    init_glfw();
    set_hints(hints);
    
    glfw_window = std::shared_ptr<GLFWwindow>(
        glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr),
        glfwDestroyWindow
    );
    
    if (!glfw_window)
    {
        throw Window::WindowCreationFailed();
    }
    
    glfwMakeContextCurrent(glfw_window.get());
    
    init_input(glfw_window.get());
}

Window::~Window()
{
    glfwTerminate();
}

void Window::attach(std::shared_ptr<Scene const> scene)
{
    this->scene = scene;
    scene->bind(glfw_window, win_width, win_height);
}

void Window::on_quit(std::function<void()> const& quit_handler)
{
    this->quit_handler = quit_handler;
}

void Window::run_while(std::function<bool()> const& predicate)
{
    do
    {
        glfwPollEvents();
        
        if (scene)
        {
            scene->render();
        }
        
        if (glfwWindowShouldClose(glfw_window.get()) && quit_handler)
        {
            quit_handler();
        }
    } while (predicate());
}

void init_glfw()
{
    if (!glfwInit())
    {
        throw Window::SystemInitFailed();
    }
}

void set_hints(std::map<int, int> const& hints)
{
    for (auto const& pair : hints)
    {
        glfwWindowHint(pair.first, pair.second);
    }
}

void init_input(GLFWwindow * const glfw_window)
{
    glfwSetInputMode(glfw_window, GLFW_STICKY_KEYS, GL_TRUE);
}
