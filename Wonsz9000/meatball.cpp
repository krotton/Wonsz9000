// Meatball entity implementation.

#include "essentials.hpp"

#include "meatball.hpp"

using namespace wonsz9000;


Meatball::Meatball(Location const location):
	location_(location)
{

}

void Meatball::render(Transform const& t) const
{
	t.push();

	t.translate(center_);
	glutSolidSphere(0.5, 30, 30);

	t.pop();
}

void Meatball::update()
{
}
