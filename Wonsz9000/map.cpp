// Map entity implementation.

#include "essentials.hpp"

#include "map.hpp"

using namespace wonsz9000;


double const Map::TILE_ARM = 1.0;


Map::Map(TileMap const& tiles):
	Entity(),
	tl_(center_ - Vec3D{(ARM_LENGTH * TILE_ARM)/2.0, 0.0, -(ARM_LENGTH * TILE_ARM)/2.0}),
	tile_map_(tiles)
{
	// Wall segment size:
	Location const size{TILE_ARM, 3.0 * TILE_ARM, TILE_ARM};

	// Create wall entities for all wall tiles.
	for (unsigned row = 0; row < tiles.size(); ++row)
	{
		for (unsigned col = 0; col < tiles[0].size(); ++col)
		{
			auto const tile = tiles[row][col];

			if (tile == Tile::Wall)
			{
				auto const loc = tl_ + Vec3D{row * TILE_ARM, 0.0, -(col * TILE_ARM)};
				walls_.push_back(Wall{loc, size});
			}
		}
	}
}

void Map::render(Transform const& t) const
{
	t.push();

	floor_.render(Transform{});
	
	for (Wall const &wall : walls_)
	{
		wall.render(Transform{});
	}
	
	t.pop();
}

Location Map::random_location() const
{
	// Randomize a tile index until an empty one is hit.
	std::random_device rd;
	std::uniform_int_distribution<> uni(0, tile_map_.size() - 1);

	while (true)
	{
		unsigned const row = uni(rd), col = uni(rd);

		if (tile_map_[row][col] == Tile::Empty)
		{
			return tl_ + Vec3D{row * TILE_ARM, 0.0, -(col * TILE_ARM)};
		}
	}
}

Map Map::random()
{
	// Surround the map with a wall.
	TileMap tiles;
	auto const max = tiles.size() - 1;

	for (unsigned row = 0; row <= max; ++row)
	{
		for (unsigned col = 0; col <= max; ++col)
		{
			// If we're not in the first and not in the last row/col...
			if (row && col && row != max && col != max)
			{
				tiles[row][col] = Tile::Empty;
			}
			else
			{
				tiles[row][col] = Tile::Wall;
			}
		}
	}

	return Map{tiles};
}
