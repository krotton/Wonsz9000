// Wonsz9000 - entry point.

int main(int argc, const char * argv[])
{
    if (!glfwInit())
    {
        std::cout << "[FATAL] Could not initialize GLFW!" << std::endl;
        return 1;
    }
    
    return 0;
}
