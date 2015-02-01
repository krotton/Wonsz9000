// Snake entity implementation.

#include "essentials.hpp"

#include "snake.hpp"

using namespace wonsz9000;


double const Snake::SPEED = 0.15;


void Snake::render(Transform const& t) const
{
	t.translate(center_).rotate(rotation_).scale({1.0, 1.0, 2.0});

	glutSolidCube(1.0);
}

void Snake::turn(bool const right)
{
	if (right)
	{
		dir_ = (dir_ + 1) % 4;
	}
	else
	{
		if (--dir_ < 0)
		{
			dir_ += 4;
		}
	}
}

void Snake::update()
{
	if (dir_ == 0)
	{
		// Forward...
		center_.z -= SPEED;
		rotation_.y = 0.0;
	}
	else if (dir_ == 1)
	{
		// Right...
		center_.x += SPEED;
		rotation_.y = 90.0;
	}
	else if (dir_ == 2)
	{
		// Backward...
		center_.z += SPEED;
		rotation_.y = 180.0;
	}
	else
	{
		// Left...
		center_.x -= SPEED;
		rotation_.y = 270.0;
	}
}
