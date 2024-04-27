#pragma once
#include "raylib.h"
#include "iostream"
#include "assert.h"

class Window {
private:

public:
	Window(int width, int height, int fps,std::string title);
	~Window()noexcept;
	bool GameShouldClose();

};