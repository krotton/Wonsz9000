// Game logics.

#include "essentials.hpp"

#include "game.hpp"

using namespace wonsz9000;


void Game::update()
{
	snake_.update();
	current_ball_.update();
}
