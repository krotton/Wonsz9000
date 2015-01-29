// Entity - a game object that can be drawn and acted upon.

#pragma once

#include "essentials.hpp"


namespace wonsz9000
{
	class Entity
	{
	public:
		// Render the entity using active OpenGL context.
		// Must be implemented by all entity subtypes!
		virtual void render() const = 0;
	};
}
