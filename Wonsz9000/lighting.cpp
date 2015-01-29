// Scene lighting.

#include "essentials.hpp"

#include "lighting.hpp"

using namespace wonsz9000;


Lighting::Lighting(Location const location)
{
	static GLfloat const light_position[] = {location.x, location.y, location.z, 1.0};
	static GLfloat const ambient_params[] = {0.2, 0.2, 0.2, 1.0};

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient_params);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

void Lighting::apply() const
{
}
