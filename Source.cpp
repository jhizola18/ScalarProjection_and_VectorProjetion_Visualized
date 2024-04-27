#include "raylib.h"
#include "Window.h"

int main()
{
	constexpr int Width = 800;
	constexpr int Height = 800;
	const int fps = 75;

	Window window = {Width, Height, 75, "Vector Projection/ Scalar Projection"};

	while (!window.GameShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);

		EndDrawing();
	}



	return 0;
}


