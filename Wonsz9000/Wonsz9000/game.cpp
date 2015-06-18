// Wonsz9000 - the game's state holder and manager - implementation.

#include "game.hpp"

Game::Game()
{
    scene_ptr = std::shared_ptr<Scene>(new Scene());
}

void Game::halt()
{
    finished = true;
}
