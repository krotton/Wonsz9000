// Lighting - scene lighting effect.

#pragma once

#include "essentials.hpp"

#include "location.hpp"

#include "effect.hpp"


namespace wonsz9000
{
	class Lighting : public Effect
	{
		// Ambient light color:
		static GLfloat const ambient_color[4];

	public:
		// Enable lighting and set OpenGL lighting parameters on creation.
		Lighting(Location const location);

		// Apply lighting to the scene.
		void apply() const override;
	};
}
