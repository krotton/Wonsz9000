// Snake entity implementation.

#include "essentials.hpp"

#include "snake.hpp"

using namespace wonsz9000;


void Snake::render() const
{
	glTranslatef(-0.8, 0.35, -5.0);
	glRotatef(100.0, 1.0, 0.0, 0.0);
	glutSolidTorus(0.275, 0.8, 10, 10);
}

void Snake::update()
{
}
