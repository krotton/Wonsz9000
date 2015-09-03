// Wonsz9000 - a test renderable

#pragma once

#include "renderable.hpp"
#include "texture.hpp"

class Triangle: public Renderable
{
public:
    void bind() const;
    glm::mat4 const transformation() const;
    
protected:
    void draw() const;
    
private:
    static GLfloat const vertices[];
    static GLfloat const uvs[];
    
    mutable std::unique_ptr<Texture> texture;

    // Vertex and UV buffers.
    mutable GLuint vb, uvb;
};
