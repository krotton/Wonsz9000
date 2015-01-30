// Scene - a 3D drawing manager.

#pragma once

#include "essentials.hpp"

#include "camera.hpp"
#include "entity.hpp"
#include "effect.hpp"


namespace wonsz9000
{
    // Manages 3D drawing.
	//
	// Warning: scene modification is not thread safe!
    class Scene
    {
    public:
		// Unique identifier type:
		using Uuid = sole::uuid;

		// Initialize the scene.
		Scene(Camera const& camera);

        // Draw the scene using the active OpenGL context (there is only one).
        void draw() const;

		// Update the OpenGL context after width or height has changed.
		void reshape(int const w, int const h) const;

		// Add an entity to the scene.
		// Returns a unique identifier that can be used to remove the entity later.
		Uuid add(Entity const& entity);

		// Register an effect with the scene.
		// Returns a unique identifier that can be used to remove the effect later.
		Uuid add(Effect const& effect);

	private:
		// References to active entities.
		std::map<Uuid, std::reference_wrapper<Entity const>> entities_;
		std::map<Uuid, std::reference_wrapper<Effect const>> effects_;

		// Current viewport width and height.
		mutable int vp_width_, vp_height_;

		// Active camera object.
		Camera const& camera_;
    };
}
