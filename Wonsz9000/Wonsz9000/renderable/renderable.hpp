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
    
    // Informs the renderable, that it has been bound to a context
    // and can draw safely.
    virtual void bind() const;

protected:
    // Performs actual drawing. Must be overriden by descendants.
    virtual void draw() const = 0;

private:
    // Is the renderable bound to a context and allowed to draw?
    mutable bool bound = false;
};