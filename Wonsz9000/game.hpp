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
		// Create a game object with a selected framerate (in frames per second).
		Game(unsigned const fps = 30):
			frame_time_(1000/fps)
		{}

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
		// Warning! There is a potential delay between updates to keep a framerate.
		void run()
		{
			while (true)
			{
				auto const start_time = std::chrono::system_clock::now();

				// Update state.

				auto const elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(
					std::chrono::system_clock::now() - start_time);

				if (elapsed_time.count() < frame_time_)
				{
					// Wait till the end of current frame period.
					std::this_thread::sleep_for(std::chrono::milliseconds(frame_time_ - elapsed_time.count()));
				}
			}
		}

	private:
		// Time for a single update (in milliseconds).
		unsigned const frame_time_;
    };
}
