// Snake - the Game's main entity - moves in a snakey way, eats meatballs and grows.

#pragma once

#include "essentials.hpp"

#include "entity.hpp"


namespace wonsz9000
{
	class Snake : public Entity
	{
		// Render the snake - it's a tube-like being with break points on curves,
		// textured using a generated snakey pattern.
		void render() const;
	};
}
