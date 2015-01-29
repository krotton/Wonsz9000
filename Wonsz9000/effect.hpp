// Effect - a global modification to a scene.

#pragma once

#include "essentials.hpp"


namespace wonsz9000
{
	class Effect
	{
	public:
		// Apply the effect to the active scene.
		virtual void apply() const = 0;
	};
}
