// Game - controls the game logics.

#pragma once

#include "essentials.hpp"

#include "camera.hpp"
#include "scene.hpp"
#include "hud.hpp"
#include "input.hpp"

#include "snake.hpp"
#include "map.hpp"
#include "meatball.hpp"

#include "lighting.hpp"
#include "fog.hpp"


namespace wonsz9000
{
    class Game
    {
    public:
		// Create a game object with a selected framerate (in frames per second).
		Game(unsigned const fps = 30);

        // Return a shared pointer to the game's scene object that can be used for drawing.
        inline std::shared_ptr<Scene const> scene() const
		{
			return scene_;
		}

		// Return a shared pointer to the game's HUD object that can be used for overlay drawing.
		inline std::shared_ptr<HUD const> hud() const
		{
			return hud_;
		}

        // Return a shared pointer to the game's input manager.
        inline std::shared_ptr<Input const> input() const
		{
			return input_;
		}

		// Is the game still running?
		inline bool running() const
		{
			return !finished_;
		}

		// Loop, updating the state.
		// Warning! There is a potential delay between updates to keep a framerate.
		void run();

		// Update the entities' state and game state.
		void update();

	private:
		// Turn the snake:
		void turn(bool const right);

		// Switch camera (back cam/top cam):
		void switch_camera();

		// Time for a single update (in milliseconds).
		unsigned const frame_time_;

		// Game entities:
		Map map_ = Map::random();
		Snake snake_{map_.random_location()};
		Meatball current_ball_{map_.random_location()};

		// Enabled effects:
		Lighting lighting_{{30.0, 0.0, 10.0}};
		Fog fog_;

		// Game score:
		unsigned score_ = 0;

		// Has the player already died?
		// (It's not yet a quit condition! User's confirmation is!)
		bool died_ = false;

		// Has the game already finished?
		bool finished_ = false;

		// Supported cameras:
		// Back cam - attached to the back of the snake's head.
		Camera back_cam_ = Camera::following(&snake_, {0.0, 3.0, 3.0});

		// Manager objects:
		std::shared_ptr<Scene> scene_ = std::shared_ptr<Scene>(new Scene{back_cam_});
		std::shared_ptr<HUD> hud_ = std::shared_ptr<HUD>(new HUD{});
		std::shared_ptr<Input> input_ = std::shared_ptr<Input>(new Input{});
    };
}
