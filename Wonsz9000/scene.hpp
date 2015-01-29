// Scene - a 3D drawing manager.

#pragma once

#include "essentials.hpp"

#include "effect.hpp"


namespace wonsz9000
{
    // Manages 3D drawing.
    class Scene
    {
    public:
		// Initialize the scene.
		// Accepts a list of static (non-removable) entities that are guaranteed
		// to remain alive until the end of the scene's existence.
		Scene(std::vector<std::reference_wrapper<Entity const>> const entities,
			std::vector<std::unique_ptr<Effect const>> const effects):
			static_entities_(entities),
			static_effects_(effects)
		{}

        // Draw the scene using the active OpenGL context (there is only one).
        void draw() const;

	private:
		// References to active entities.
		std::vector<std::reference_wrapper<Entity const>> const static_entities_;
		std::vector<std::unique_ptr<Effect const>> const static_effects_;
    };
}
