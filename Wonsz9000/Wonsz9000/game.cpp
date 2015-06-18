// Wonsz9000 - the game's state holder and manager - implementation.

#include "game.hpp"

#include "triangle.hpp"

Game::Game()
{
    scene_ptr = std::shared_ptr<Scene>(new Scene());
    
    auto triangle = std::make_shared<Triangle>();
    scene_ptr->add(triangle);
}

void Game::halt()
{
    finished = true;
}
