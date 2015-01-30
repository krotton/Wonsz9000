// Snake entity implementation.

#include "essentials.hpp"

#include "snake.hpp"

using namespace wonsz9000;


void Snake::render(Transform<> const& t) const
{
	t.translate(center_).rotate(rotation_);

	glutSolidTorus(1.0, 3.5, 10, 10);
}

void Snake::update()
{
}
