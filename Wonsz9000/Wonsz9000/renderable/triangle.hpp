// Wonsz9000 - a test renderable

#pragma once

#include "renderable.hpp"
#include "shader.hpp"

class Triangle: public Renderable
{
public:
    void bind() const;
    
protected:
    void draw() const;
    
private:
    static GLfloat const vertices[];
    mutable std::unique_ptr<ShaderProgram> shader_program = nullptr;
    mutable GLuint vb;
};
