// Fog - a simple distance fog effect.

#pragma once

#include "essentials.hpp"

#include "effect.hpp"


namespace wonsz9000
{
	class Fog : public Effect
	{
	public:
		// Apply a fog to the scene.
		void apply() const override;
	};
}
