// Camera implementation.

#include "essentials.hpp"

#include "camera.hpp"

using namespace wonsz9000;


void Camera::apply() const
{
	bool const free = target_entity_ == nullptr;

	Location cam, target;

	if (free)
	{
		// In case of a free camera, just sit there in the specified
		// point and look at the specified point.
		cam = cam_loc_;
		target = target_loc_;
	}
	else
	{
		// In case of a following camera, recalculate the position
		// of the camera by translating the target location by the specified
		// distance vector.
		target = target_entity_->location();
		auto dist = dist_;

		// Following cameras must also follow rotation!
		// Notice: only rotation around Y!
		// Rodrigues formula: v_rot = vcos(a) + (k x v)sin(a) + k(k * v)(1 - cos(a))
		auto const rot = target_entity_->rotation();
		double const ca = cos(rot.y * 3.141592 / 180.0), sa = sin(rot.y * 3.141592 / 180.0);
		double const cross_x = -dist.y * 0.0 + dist.z * 1.0,
			cross_y = -dist.z * 0.0 + dist.x * 0.0,
			cross_z = -dist.x * 1.0 + dist.y * 0.0;
		double const dot = dist.x * 0.0 + dist.y * 1.0 + dist.z * 0.0;
		double const rx = dist.x * ca + cross_x * sa + dot * 0.0 * (1 - ca),
			ry = dist.y * ca + cross_y * sa + dot * 1.0 * (1 - ca),
			rz = dist.z * ca + cross_z * sa + dot * 0.0 * (1 - ca);

		cam = target + Vec3D{rx, ry, rz};
	}

	gluLookAt(cam.x, cam.y, cam.z,
		target.x, target.y, target.z,
		0.0, 1.0, 0.0);
}

void Camera::reshape(int const w, int const h) const
{
	if(h > 0 && w > 0)
	{
		glViewport(0, 0, w, h);

		glMatrixMode(GL_PROJECTION);

		glLoadIdentity();
		gluPerspective(fova_, (GLdouble)w/h, near_, far_);

		glMatrixMode(GL_MODELVIEW);
    }
}
