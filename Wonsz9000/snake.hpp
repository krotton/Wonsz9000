// Snake - the Game's main entity - moves in a snakey way, eats meatballs and grows.

#pragma once

#include "essentials.hpp"

#include "entity.hpp"


namespace wonsz9000
{
	class Snake : public Entity
	{
		// Speed in units/frame.
		static double const SPEED;

	public:
		// Create a new, single-element snake at the specified position.
		Snake(Location const location):
			Entity(location)
		{}

		// Update the snake's position.
		void update() override;

		// Render the snake - it's a tube-like being with break points on curves,
		// textured using a generated snakey pattern.
		void render(Transform const& t) const override;

		// Turn right or left.
		void turn(bool const right);

	private:
		unsigned segments_;

		// Motion direction: Forward, Right, Backward, Left.
		int dir_ = 0;
	};
}
