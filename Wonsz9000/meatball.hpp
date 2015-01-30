// Meatball - a collectible that makes the snake grow.

#pragma once

#include "essentials.hpp"

#include "location.hpp"

#include "entity.hpp"


namespace wonsz9000
{
	class Meatball : public Entity
	{
	public:
		// Initialize a meatball placed at the specified location in space (in the origin by default).
		Meatball(Location const location = {0.0, 0.0, 0.0});

		// Animate the meatball.
		void update() override;

		// Render the meatball - it's just an animated, glowing sphere.
		void render(Transform<> const& t) const override;

	private:
		// Current location.
		Location location_;
	};
}
