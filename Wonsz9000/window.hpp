// Window - manages the application window and input event handling.

#pragma once

#include "essentials.hpp"

#include "scene.hpp"
#include "hud.hpp"
#include "input.hpp"


namespace wonsz9000
{
    // Creates a window and manages the main program loop.
    class Window
    {
    public:
        // Create and display a new window.
        //
        // Arguments:
        //  - argc and argv are arguments passed to the program.
        //  - win_width and win_height determine the width and height of the created
        //  window (accordingly) in pixels.
        //  - win_title is the title displayed on the title bar and task bar.
        //
        // GLUT's API feels entitled to modify the argument list, so it cannot be
        // passed in as const (as it should be)...
        Window(int argc, char* argv[],
            int const win_width, int const win_height,
            std::string const win_title);

        // Register a scene object that will manage display.
        void scene(std::shared_ptr<Scene const> scene);

		// Register a HUD object that will manage 2D overlay display.
		void hud(std::shared_ptr<HUD const> hud);

        // Register an input manager object that will handle incoming input.
        void input(std::shared_ptr<Input const> input);

        // Loop until loop_func() becomes true (or indefinitely if it's not given).
		void run(std::function<bool()> const loop_func = {});
    };
}

