// Wonsz9000 - a renderable object's interface

#pragma once

class Renderable
{

public:
    // Performs all the Renderable's rendering:
    // enables and binds the buffers,
    // draws the objects
    // cleans up after drawing.
    void render() const;
    
    // Updates the renderable's state by one frame.
    virtual void update() {};

protected:
    // Binds buffers and prepares the OpenGL's machine for drawing.
    virtual void bind() const {}
    
    // Cleans up after drawing.
    virtual void cleanup() const {}
    
    // Performs actual drawing. Must be overriden by descendants.
    virtual void draw() const = 0;
};
