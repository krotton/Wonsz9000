// Wonsz9000 - a test renderable

#pragma once

#include "renderable.hpp"

class Triangle: public Renderable
{
public:
    void bind() const;
    
protected:
    void draw() const;
    
private:
    static GLfloat const vertices[];
    mutable GLuint vb;
};
