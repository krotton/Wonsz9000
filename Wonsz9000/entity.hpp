// Entity - a game object that can be drawn and acted upon.

#pragma once

#include "essentials.hpp"


namespace wonsz9000
{
	class Entity
	{
	public:
		// Update the entity's state.
		// This method is guaranteed to be called once per frame.
		// The default implementation does nothing.
		virtual void update() {}

		// Render the entity using active OpenGL context.
		virtual void render() const = 0;
	};
}
