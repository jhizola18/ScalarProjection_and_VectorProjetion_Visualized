#include "raylib.h"
#include "Window.h"
#include "ScalarProj.h"

int main()
{
	constexpr int Width = 800;
	constexpr int Height = 800;
	const int fps = 75;

	Window window = {Width, Height, 75, "Vector Projection/ Scalar Projection"};

	Vector2 Vec_a = { 400.0f, 400.0f };
	Vector2 Vec_b = GetMousePosition();
	ScalarProjection scalarproj = { Vec_a , Vec_b};
	while (!window.GameShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
		scalarproj.ScalarPorj_Implementation();
		EndDrawing();
	}



	return 0;
}


