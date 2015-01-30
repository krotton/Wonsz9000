// Snake - the Game's main entity - moves in a snakey way, eats meatballs and grows.

#pragma once

#include "essentials.hpp"

#include "entity.hpp"


namespace wonsz9000
{
	class Snake : public Entity
	{
	public:
		// Create a new, n-element snake at the specified position.
		Snake(Location const location, unsigned const segments = 1):
			Entity(location),
			segments_(segments)
		{}

		// Update the snake's position.
		void update() override;

		// Render the snake - it's a tube-like being with break points on curves,
		// textured using a generated snakey pattern.
		void render(Transform const& t) const override;

	private:
		unsigned segments_;
	};
}
