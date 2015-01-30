// Floor entity implementation.

#include "essentials.hpp"

#include "floor.hpp"

using namespace wonsz9000;


void Floor::render(Transform const& t) const
{
	glBegin(GL_QUADS);
	
	glColor3d(1.0, 0.0, 0.0);
	glVertex3d(tl_.x, tl_.y, br_.z); // bottom left
	glColor3d(1.0, 0.0, 0.0);
	glVertex3d(br_.x, br_.y, br_.z); // bottom right
	glColor3d(1.0, 0.0, 0.0);
	glVertex3d(br_.x, br_.y, tl_.z); // top right
	glColor3d(1.0, 0.0, 0.0);
	glVertex3d(tl_.x, tl_.y, tl_.z); // top left

	glEnd();
}
