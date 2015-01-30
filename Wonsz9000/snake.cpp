// Snake entity implementation.

#include "essentials.hpp"

#include "snake.hpp"

using namespace wonsz9000;


void Snake::render(Transform const& t) const
{
	t.push();

	t.translate(center_).scale({1.0, 1.0, 4.0});

	glutSolidCube(1.0);

	t.pop();
}

void Snake::update()
{
}
