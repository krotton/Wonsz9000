// Meatball - a collectible that makes the snake grow.

#pragma once

#include "essentials.hpp"

#include "entity.hpp"


namespace wonsz9000
{
	class Meatball : public Entity
	{
		// Render the meatball - it's just an animated, glowing sphere.
		void render() const;
	};
}
