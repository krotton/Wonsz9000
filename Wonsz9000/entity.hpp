// Entity - a game object that can be drawn and acted upon.

#pragma once

#include "essentials.hpp"

#include "glutils.hpp"
#include "location.hpp"


namespace wonsz9000
{
	class Entity
	{
	public:
		// Construct an entity providing the center and initial rotation.
		Entity(Location const center = {}, Rotation const rotation = {}):
			center_(center), rotation_(rotation)
		{}

		// Update the entity's state.
		// This method is guaranteed to be called once per frame.
		// The default implementation does nothing.
		virtual void update() {}

		// Render the entity using active OpenGL context.
		// An externally managed Transform<GL_MODELVIEW> object is passed
		// to simplify local transformations made by the entity.
		virtual void render(Transform const& t) const = 0;

		// Return the location of the center of the entity.
		inline Location location() const
		{
			return center_;
		}

		// Return the rotation vector of the entity.
		inline Rotation rotation() const
		{
			return rotation_;
		}

		// Translate the entity by a vector of units.
		void translate(Location const by)
		{
			center_ += by;
		}

		// Rotate the entity by a vector of angles.
		void rotate(Rotation const by)
		{
			rotation_ += by;
		}

	protected:
		// Location of the center of the entity.
		Location center_ = {0.0, 0.0, 0.0};

		// Current rotation vector
		// (at the beginning it's always assumed to be {0, 0, 0}).
		Rotation rotation_ = {0.0, 0.0, 0.0};
	};
}
