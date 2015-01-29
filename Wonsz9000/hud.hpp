// HUD interface - a 2D overlay drawing manager.

#pragma once

#include "essentials.hpp"


namespace wonsz9000
{
    // Manages 2D overlay drawing.
    class HUD
    {
    public:
		// Update the displayed score value.
		inline void set_score(unsigned const current_score)
		{
			score_ = current_score;
		}

		// Show "dead" screen.
		void show_dead()
		{
		}

        // Draw the overlay using the active OpenGL context (there is only one).
        void draw() const
		{
		}

	private:
		unsigned score_;
    };
}
