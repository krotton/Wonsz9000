// Map - a labirynth consisting of the floor and walls. In short, it represents
// all the surroundings that can kill the snake.

#pragma once

#include "essentials.hpp"

#include "location.hpp"

#include "entity.hpp"


namespace wonsz9000
{
	class Map : public Entity
	{
	public:
		// Render the map - that means render the floor and all the walls.
		void render() const override;

		// Return a random non-occupied location on the floor.
		Location random_location() const;
	};
}
