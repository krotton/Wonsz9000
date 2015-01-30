// Map - a labirynth consisting of the floor and walls. In short, it represents
// all the surroundings that can kill the snake.

#pragma once

#include "essentials.hpp"

#include "location.hpp"

#include "entity.hpp"
#include "floor.hpp"
#include "wall.hpp"


namespace wonsz9000
{
	class Map : public Entity
	{
		// How long is the map's arm (it's a square) in tiles?
		static unsigned const ARM_LENGTH = 25;

		// How big is a tile in units?
		static double const TILE_ARM;

	public:
		// Represents tile types. Currently the selection is quite small...
		enum class Tile : uint8_t
		{
			Empty,
			Wall
		};

		// Tile map - a 2-dimensional array of tiles.
		using TileMap = std::array<std::array<Tile, ARM_LENGTH>, ARM_LENGTH>;

		// Create a map from a 2D array of tiles.
		Map(TileMap const& tiles);

		// Render the map - that means render the floor and all the walls.
		void render(Transform const& t) const override;

		// Return a random non-occupied location on the floor.
		Location random_location() const;

		// Generate a random map.
		static Map random();

	private:
		// Floor.
		Floor const floor_{
			{0.0, 0.0, 0.0},		// center
			ARM_LENGTH * TILE_ARM,	// width
			ARM_LENGTH * TILE_ARM}; // height

		// Walls.
		std::vector<Wall const> walls_;

		// Spatial location of the top left corner of the map.
		Location const tl_;

		// Tile layout.
		TileMap const tile_map_;
	};
}
