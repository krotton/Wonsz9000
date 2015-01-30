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
		cam = target - dist_;
	}

	gluLookAt(cam.x, cam.y, cam.z,
		target.x, target.y, target.z,
		0.0, 1.0, 0.0);

	if (!free)
	{
		// Following cameras must also follow rotation!
		auto const rot = target_entity_->rotation();
		glRotated(rot.x, 1.0, 0.0, 0.0);
		glRotated(rot.y, 0.0, 1.0, 0.0);
		glRotated(rot.z, 0.0, 0.0, 1.0);
	}
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
