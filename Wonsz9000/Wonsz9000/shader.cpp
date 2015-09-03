// Wonsz9000 - shader program helpers - implementation.

#include "shader.hpp"

GLuint compile_shader(GLuint, std::string const&);
std::string load_file(std::string const&);
GLuint link_program(std::vector<GLuint> const&);

std::string const ShaderProgram::SHADERS_ROOT_PATH = "shaders/";

ShaderProgram::ShaderProgram(std::initializer_list<std::pair<ShaderType, std::string>> const shaders)
{
    std::vector<GLuint> shader_ids;
    
    for (auto const& p : shaders)
    {
        auto const type = p.first;
        auto const filename = p.second;
        
        shader_ids.push_back(compile_shader(type, SHADERS_ROOT_PATH + filename));
    }
    
    program_id = link_program(shader_ids);
}

void ShaderProgram::activate()
{
    glUseProgram(program_id);
}

void ShaderProgram::deactivate()
{
    glUseProgram(0);
}

void ShaderProgram::provide_uniform(std::string const& name, glm::mat4 const& matrix)
{
    GLuint const matrix_id = glGetUniformLocation(program_id, name.c_str());
    glUniformMatrix4fv(matrix_id, 1, GL_FALSE, &matrix[0][0]);
}

GLuint compile_shader(GLuint type, std::string const& filename)
{
    auto const source = load_file(filename);
    char const* source_ptr = source.c_str();
    
    auto const shader_id = glCreateShader(type);
    glShaderSource(shader_id, 1, &source_ptr, nullptr);
    glCompileShader(shader_id);
    
    GLint result = GL_FALSE;
    
    glGetShaderiv(shader_id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE)
    {
        int info_log_length = 0;
        
        glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &info_log_length);
        std::vector<char> error_msg(info_log_length);
        
        glGetShaderInfoLog(shader_id, info_log_length, nullptr, &error_msg[0]);
        throw ShaderProgram::CompileError(filename, &error_msg[0]);
    }
    
    return shader_id;
}

std::string load_file(std::string const& filename)
{
    std::ifstream f(filename);
    std::string data{
        (std::istreambuf_iterator<char>(f)),
        (std::istreambuf_iterator<char>())
    };
    
    if (data.empty())
    {
        throw ShaderProgram::LoadError(filename);
    }
    
    return data;
}

GLuint link_program(std::vector<GLuint> const& shader_ids)
{
    GLuint program_id = glCreateProgram();
    
    for (auto const id : shader_ids)
    {
        glAttachShader(program_id, id);
    }
    
    glLinkProgram(program_id);
    
    GLint result = GL_FALSE;
    
    glGetProgramiv(program_id, GL_LINK_STATUS, &result);
    if (result == GL_FALSE)
    {
        int info_log_length = 0;
        
        glGetProgramiv(program_id, GL_INFO_LOG_LENGTH, &info_log_length);
        std::vector<char> error_msg(std::max(info_log_length, 1));
        
        glGetProgramInfoLog(program_id, info_log_length, nullptr, &error_msg[0]);
        throw ShaderProgram::LinkError(&error_msg[0]);
    }

    for (auto const id : shader_ids)
    {
        glDeleteShader(id);
    }
    
    return program_id;
}
