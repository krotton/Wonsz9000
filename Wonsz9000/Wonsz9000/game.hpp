// Wonsz9000 - the game's state holder and manager.

#pragma once

#include "scene.hpp"

/**
 * Holds and updates the game's state. Creates the scene, controls input.
 */
class Game
{
    
public:
    // Is the game still running?
    bool running() const
    {
        return !finished;
    }
    
    // Returns a shared pointer to the game's scene.
    std::shared_ptr<Scene const> scene() const
    {
        return scene_ptr;
    }
    
    // Force-halts the game.
    void halt();
    
private:
    bool finished = false;
    std::shared_ptr<Scene> scene_ptr;
};
