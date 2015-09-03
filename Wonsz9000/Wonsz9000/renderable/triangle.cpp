// Wonsz9000 - a test renderable - implementation

#include "triangle.hpp"

GLfloat const Triangle::vertices[] = {
    -1.0f, -1.0f, 0.0f,
     1.0f, -1.0f, 0.0f,
     0.0f,  1.0f, 0.0f
};

GLfloat const Triangle::uvs[] = {
    1.0f, 1.0f,
    0.0f, 1.0f,
    0.5f, 0.0f
};

void Triangle::bind() const
{
    Renderable::bind();
    
    glGenBuffers(1, &vb);
    glBindBuffer(GL_ARRAY_BUFFER, vb);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glGenBuffers(1, &uvb);
    glBindBuffer(GL_ARRAY_BUFFER, uvb);
    glBufferData(GL_ARRAY_BUFFER, sizeof(uvs), uvs, GL_STATIC_DRAW);
    
    texture = std::unique_ptr<Texture>{
        new Texture("textures/magda.png")
    };
}

void Triangle::draw() const
{
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vb);
    glVertexAttribPointer(0,
                          3,
                          GL_FLOAT,
                          GL_FALSE,
                          0,
                          (void*)0);
    
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, uvb);
    glVertexAttribPointer(1,
                          2,
                          GL_FLOAT,
                          GL_FALSE,
                          0,
                          (void*)0);
    
    texture->bind();
    
    glDrawArrays(GL_TRIANGLES, 0, 3);
    
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}

glm::mat4 const Triangle::transformation() const
{
    return glm::translate(glm::vec3(0.0, 0.0, 0.0));
}
