// Lighting - scene lighting effect.

#pragma once

#include "essentials.hpp"

#include "location.hpp"

#include "effect.hpp"


namespace wonsz9000
{
	class Lighting : public Effect
	{
	public:
		// Enable lighting and set OpenGL lighting parameters on creation.
		Lighting(Location const location);

		// Apply lighting to the scene.
		void apply() const override;
	};
}
