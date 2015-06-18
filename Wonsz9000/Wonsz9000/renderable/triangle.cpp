// Wonsz9000 - a test renderable - implementation

#include "triangle.hpp"

GLfloat const Triangle::vertices[] = {
    -1.0f, -1.0f, 0.0f,
     1.0f, -1.0f, 0.0f,
     0.0f,  1.0f, 0.0f
};

void Triangle::bind() const
{
    Renderable::bind();
    
    glGenBuffers(1, &vb);
    glBindBuffer(GL_ARRAY_BUFFER, vb);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    shader_program = std::unique_ptr<ShaderProgram>(new ShaderProgram({
        {ShaderProgram::Vertex, "triangle.vertex.glsl"},
        {ShaderProgram::Fragment, "triangle.fragment.glsl"}
    }));
}

void Triangle::draw() const
{
    shader_program->activate();
    
    glEnableVertexAttribArray(0);
    
    glBindBuffer(GL_ARRAY_BUFFER, vb);
    glVertexAttribPointer(
        0,
        3,
        GL_FLOAT,
        GL_FALSE,
        0,
        (void*)0
    );
    
    glDrawArrays(GL_TRIANGLES, 0, 3);
    
    glDisableVertexAttribArray(0);
    
    shader_program->deactivate();
}
