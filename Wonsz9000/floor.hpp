// Floor - a grassy base of the map.

#pragma once

#include "essentials.hpp"

#include "entity.hpp"


namespace wonsz9000
{
	class Floor : public Entity
	{
	public:
		// Render the floor - it's just a grassy plane.
		void render() const override;
	};
}
