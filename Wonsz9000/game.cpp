// Game logics.

#include "essentials.hpp"

#include "game.hpp"

using namespace wonsz9000;


Game::Game(unsigned const fps):
	frame_time_(1000/fps)
{
	// Register renderable entities.
	scene_->add(map_);
	scene_->add(snake_);
	scene_->add(current_ball_);

	// Register scene effects.
	scene_->add(fog_);
	scene_->add(lighting_);

	// Register input handlers.
	input_->add_special_handler({GLUT_KEY_LEFT, GLUT_KEY_RIGHT}, [this](int const key) {
		turn(key == GLUT_KEY_RIGHT);
	});

	input_->add_handler(13, [this](char const key) {
		switch_camera();
	});
}

void Game::update()
{
	snake_.update();
	current_ball_.update();
}

void Game::run()
{
	while (running())
	{
		auto const start_time = std::chrono::system_clock::now();

		// Update state.
		update();

		auto const elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(
			std::chrono::system_clock::now() - start_time);

		if (elapsed_time.count() < frame_time_)
		{
			// Wait till the end of current frame period.
			std::this_thread::sleep_for(std::chrono::milliseconds(frame_time_ - elapsed_time.count()));
		}
	}
}

void Game::turn(bool const right)
{
	double const angle = right? 90.0 : -90.0;
	snake_.rotate({0.0, angle, 0.0});
}

void Game::switch_camera()
{

}
