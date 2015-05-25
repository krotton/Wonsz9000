// Wonsz9000 - entry point.

int main(int argc, const char * argv[])
{
    if (!glfwInit())
    {
        std::cout << "[FATAL] Could not initialize GLFW!" << std::endl;
        return 1;
    }
    
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    GLFWwindow *window(glfwCreateWindow(1024, 768, "Wonsz9000", nullptr, nullptr));
    if (!window)
    {
        std::cout << "[FATAL] Could not create a window!" << std::endl;
        glfwTerminate();
        return 2;
    }
    
    glfwMakeContextCurrent(window);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    
    do {
        glfwSwapBuffers(window);
        glfwPollEvents();
    } while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
             !glfwWindowShouldClose(window));
    
    glfwDestroyWindow(window);
    
    return 0;
}
