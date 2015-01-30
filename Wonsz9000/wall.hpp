// Floor - a piece of hedge.

#pragma once

#include "essentials.hpp"

#include "location.hpp"

#include "entity.hpp"


namespace wonsz9000
{
	class Wall : public Entity
	{
	public:
		// Create a wall box with a center in the specified point
		// and with the given size.
		Wall(Location const center, Vec3D const size):
			Entity(center),
			size_(size)
		{}

		// Render the wall - it's just a hedgey box.
		void render(Transform const& t) const override;

	private:
		// Size of the box in units.
		Vec3D const size_;
	};
}
