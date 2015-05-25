// Wonsz9000 - entry point.

#include "window.hpp"

int main(int argc, const char * argv[]) try
{
    // Window hints.
    static std::map<int, int> window_hints = {
        {GLFW_CONTEXT_VERSION_MAJOR, 4},
        {GLFW_CONTEXT_VERSION_MINOR, 1},
        {GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE},
        {GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE},
        
        {GLFW_SAMPLES, 4},
    };
    
    Window window("Wonsz9000", 1024, 768, window_hints);
    
    bool quit = false;
    window.runWhile([&quit]() -> bool {
        return !quit;
    });
    
    return 0;
}
catch (Window::SystemInitFailed const&)
{
    std::cerr << "[FATAL] Could not initialize GLFW!" << std::endl;
}
catch (Window::WindowCreationFailed const&)
{
    std::cerr << "[FATAL] Could not create the window!" << std::endl;
}
catch (std::exception const& exc)
{
    std::cerr << "[FATAL] Unhandled exception: " << exc.what() << "!" << std::endl;
}
catch (...)
{
    std::cerr << "[FATAL] Unknown exception!";
}
