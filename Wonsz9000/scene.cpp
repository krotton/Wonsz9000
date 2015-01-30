// Scene rendering.

#include "essentials.hpp"

#include "scene.hpp"

using namespace wonsz9000;


Scene::Scene(Camera const& camera):
	camera_(camera)
{
	/* Set global OpenGL options:
	 * - Shade model: GL_SMOOTH,
	 * - Depth buffering: enabled, func: GL_LESS.
	 */
	glEnable(GL_DEPTH_TEST);
}

Scene::Uuid Scene::add(Entity const& entity)
{
	Uuid id;
	do
	{
		id = sole::uuid4();
	}
	while (entities_.count(id));
	entities_.insert(std::make_pair(id, std::ref(entity)));

	return id;
}

Scene::Uuid Scene::add(Effect const& effect)
{
	Uuid id;
	do
	{
		id = sole::uuid4();
	}
	while (effects_.count(id));
	effects_.insert(std::make_pair(id, std::ref(effect)));

	return id;
}

void Scene::draw() const
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	{
		Transform<> global_t;

		camera_.apply();

		for (auto const& pair : entities_)
		{
			Entity const& entity = pair.second;

			entity.render(Transform<>{});
		}
	}

	glFlush();
	glutSwapBuffers();
}

void Scene::reshape(int const width, int const height) const
{
	vp_width_ = width;
	vp_height_ = height;
	camera_.reshape(width, height);
}
