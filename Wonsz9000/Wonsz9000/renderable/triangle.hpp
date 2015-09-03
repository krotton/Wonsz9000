// Wonsz9000 - a test renderable

#pragma once

#include "renderable.hpp"
#include "shader.hpp"

class Triangle: public Renderable
{
public:
    void bind() const;
    glm::mat4 const transformation() const;
    
protected:
    void draw() const;
    
private:
    static GLfloat const vertices[];
    static GLfloat const colors[];

    // Vertex and color buffers.
    mutable GLuint vb, cb;
};
