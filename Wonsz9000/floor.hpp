// Floor - a grassy base of the map.

#pragma once

#include "essentials.hpp"

#include "entity.hpp"


namespace wonsz9000
{
	class Floor : public Entity
	{
	public:
		// Create a floor with the specified center point and size.
		Floor(Location const center, double const w, double const h):
			Entity(center),
			tl_(center - Location{w/2.0, h/2.0, 0.0}),
			br_(center + Location{w/2.0, h/2.0, 0.0})
		{}

		// Render the floor - it's just a grassy plane.
		void render(Transform const& t) const override;

	private:
		// Locations of the top left and bottom right vertices.
		Location const tl_, br_;
	};
}
