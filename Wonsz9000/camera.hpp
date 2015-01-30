// Camera - transforms the modelview to simulate looking from a selected viewpoint.

#pragma once

#include "essentials.hpp"

#include "location.hpp"
#include "entity.hpp"


namespace wonsz9000
{
	class Camera
	{
	public:
		// Create a free camera located at the given point and looking towards the given point.
		// Perspective settings may also be specified:
		//  - the field of view angle (in Y direction) in degrees,
		//  - distance to the near clipping plane,
		//  - distance to the far clipping plane.
		static Camera free(Location const camera_location, Location const target_location,
				float const fov_angle = 90.0, float const near_clip = 1.0, float const far_clip = 100.0)
		{
			return Camera(camera_location, target_location,
				nullptr, {0.0, 0.0, 0.0},
				fov_angle, near_clip, far_clip);
		}

		// Create a camera attached to and following an entity.
		static Camera following(Entity const* entity, Distance const distance_to_entity = {0.0, 1.0, 1.0},
				float const fov_angle = 90.0, float const near_clip = 1.0, float const far_clip = 100.0)
		{
			return Camera{{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0},
				entity, distance_to_entity,
				fov_angle, near_clip, far_clip};
		}

		// Reshape perspective - apply the perspective settings
		// after the viewport has changed or perspective settings just need to be recalculated.
		// Width is current viewport width in pixels, height is viewport height.
		void reshape(int const width, int const height) const;

		// Apply the camera transformation to the active scene.
		void apply() const;

	private:
		// Construct a camera:
		Camera(Location const camera_location, Location const target_location,
				Entity const* target_entity, Distance const distance_to_entity,
				float const fov_angle = 90.0, float const near_clip = 1.0, float const far_clip = 100.0):
			cam_loc_(camera_location), target_loc_(target_location),
			target_entity_(target_entity), dist_(distance_to_entity),
			fova_(fov_angle), near_(near_clip), far_(far_clip)
		{}

		// Camera location in the 3D space.
		Location cam_loc_;

		// The location the camera's looking at.
		Location target_loc_;

		// A pointer to an entity the camera's looking at.
		// If it's not null, it has precedence over location!
		Entity const* target_entity_ = nullptr;

		// Distance to keep to the entity.
		Distance dist_;

		// Perspective settings:
		// Field of view angle (in Y direction).
		float fova_;

		// Near and far clipping planes' distance from camera.
		float near_, far_;
	};
}
