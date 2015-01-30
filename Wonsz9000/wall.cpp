// Wall entity implementation.

#include "essentials.hpp"

#include "wall.hpp"

using namespace wonsz9000;


void Wall::render(Transform const& t) const
{
	t.push();

	t.scale(size_).translate(center_);

	glutSolidCube(1.0);

	t.pop();
}
