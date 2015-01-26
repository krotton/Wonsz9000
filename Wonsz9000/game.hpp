// Game - controls the game logics.

#pragma once

#include "essentials.hpp"

#include "scene.hpp"
#include "hud.hpp"
#include "input.hpp"


namespace wonsz9000
{
    class Game
    {
    public:
        // Return a shared pointer to the game's scene object that can be used for drawing.
        std::shared_ptr<Scene> scene() const
		{
			return {};
		}

		// Return a shared pointer to the game's HUD object that can be used for overlay drawing.
		std::shared_ptr<HUD> hud() const
		{
			return {};
		}

        // Return a shared pointer to the game's input manager.
        std::shared_ptr<Input> input() const
		{
			return {};
		}

		// Is the game still running?
		bool running() const
		{
			return true;
		}

		// Loop, updating the state.
		void run()
		{
		}
    };
}

