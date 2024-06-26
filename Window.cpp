#include "Window.h"


Window::Window(int width, int height, int fps, std::string title)
{
	assert(WindowShouldClose());
	InitWindow(width, height,title.c_str());
	SetTargetFPS(fps);
}

Window::~Window() noexcept
{
	assert(!WindowShouldClose());
	CloseWindow();
}

bool Window::GameShouldClose()
{
	return WindowShouldClose();
}
