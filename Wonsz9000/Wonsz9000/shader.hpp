// Wonsz9000 - shader program helpers

#pragma once

class ShaderProgram
{

public:
    // Shader type constants.
    enum ShaderType {
        Fragment = GL_FRAGMENT_SHADER,
        Vertex = GL_VERTEX_SHADER
    };
    
    // Compiles and links a shader program consisting of the given shaders.
    // Shaders are given as an initializer list of (type, filename) pairs.
    //
    // In case of a compilation error, a CompileError is thrown.
    ShaderProgram(std::initializer_list<std::pair<ShaderType, std::string>> const shaders);
    
    // Enables the program for the current context.
    void activate();
    
    // Disables the program for the current context.
    void deactivate();
    
    // Provides a uniform (global) to the program.
    void provide_uniform(std::string const& name, glm::mat4 const& matrix);
    
public: // exceptions
    struct Error: public std::exception
    {
        Error(std::string const& msg,
              std::string const& error_log):
            msg(msg),
            error_log(error_log)
        {}
        
        char const* what() const noexcept
        {
            return (msg + "\n" + error_log).c_str();
        }
        
    private:
        std::string msg, error_log;
    };
    
    // Thrown whenever a shader compilation error occurs.
    struct CompileError: public Error
    {
        CompileError(std::string const& filename, std::string const& error_log):
            Error("Shader compilation error (" + filename + "):", error_log)
        {}
    };
    
    // Thrown whenever a shader program linking error occurs.
    struct LinkError: public Error
    {
        LinkError(std::string const& error_log): Error("Shader linking error:", error_log) {}
    };
    
    // Thrown whenever an invalid shader path is provided.
    struct LoadError: public Error
    {
        LoadError(std::string const& filename):
            Error("Shader file: " + filename + " could not be loaded or is empty!", "")
        {}
    };
    
private:
    GLuint program_id = 0;
    
    static std::string const SHADERS_ROOT_PATH;
};
