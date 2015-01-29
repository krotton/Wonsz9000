// Window implementation.

#include "essentials.hpp"

#include "window.hpp"

using namespace wonsz9000;


// GLUT only supports context-less free functions as callbacks.
// Therefore the only active scene and input manager objects need to be kept
// as globals. (Sucks as hell.)
namespace globals
{
	// Active scene, HUD and input manager.
    std::shared_ptr<Scene const> active_scene = nullptr;
	std::shared_ptr<HUD const> active_hud = nullptr;
    std::shared_ptr<Input const> active_input = nullptr;

	// Exit predicate.
	std::function<bool()> exit_predicate;

	// Scene display function. Delegates to the active scene object.
    void display_func()
    {
        active_scene->draw();
    }

	// Scene reshape function. Delegates to the active scene object.
	void reshape_func(GLsizei w, GLsizei h)
	{
		active_scene->reshape(w, h);
	}

	// Overlay display function. Delegates to the active HUD object.
	void overlay_func()
	{
		active_hud->draw();
	}

	// Keyboard handling functions. Delegate to the active input manager.
    void input_ascii_func(unsigned char const c, int const x, int const y)
    {
        active_input->handle_down(c);
    }

    void input_special_func(int const k, int const x, int const y)
    {
        active_input->handle_down(k);
    }

    void input_ascii_up_func(unsigned char const c, int const x, int const y)
    {
        active_input->handle_up(c);
    }

    void input_special_up_func(int const k, int const x, int const y)
    {
        active_input->handle_up(k);
    }

	// Idle function - checks exit condition.
	void idle_func()
	{
		if (exit_predicate && exit_predicate())
		{
			std::exit(0);
		}
	}
};


Window::Window(int argc, char* argv[],
        int const win_width, int const win_height,
        std::string const win_title)
{
    glutInit(&argc, argv);

    // Use double buffering, RGBA color space and Z buffer.
    glutInitDisplayMode(GL_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

    glutInitWindowSize(win_width, win_height);
    glutCreateWindow(win_title.c_str());
}

void Window::scene(std::shared_ptr<Scene const> scene)
{
    globals::active_scene = std::move(scene);

    glutDisplayFunc(globals::display_func);
	glutReshapeFunc(globals::reshape_func);
}

void Window::input(std::shared_ptr<Input const> input)
{
    globals::active_input = std::move(input);

    glutKeyboardFunc(globals::input_ascii_func);
    glutKeyboardUpFunc(globals::input_ascii_up_func);
    glutSpecialFunc(globals::input_special_func);
    glutSpecialUpFunc(globals::input_special_up_func);
}

void Window::hud(std::shared_ptr<HUD const> hud)
{
	globals::active_hud = std::move(hud);

	glutOverlayDisplayFunc(globals::overlay_func);
}

void Window::run(std::function<bool()> const quit_predicate)
{
    globals::exit_predicate = quit_predicate;
	glutIdleFunc(globals::idle_func);

	glutMainLoop();
}
