// Wonsz9000 - a 3D snake game.
// Author: Krotton
// Copyright 2015.

#include "essentials.hpp"

#include "window.hpp"
#include "game.hpp"

using namespace wonsz9000;


int main(int argc, char *argv[])
{
    // Create a window and a game object, bind the game scene and input manager
    // to the window and then loop until the game's finished.
    Window main_win{argc, argv,
        1024, 768,
        "Wonsz9000"};

    Game game;
    main_win.scene(game.scene());
	main_win.hud(game.hud());
    main_win.input(game.input());

	// Redraw and handle input as long as the game's running.
	main_win.run(std::bind(&Game::run, &game));

    return 0;
}
