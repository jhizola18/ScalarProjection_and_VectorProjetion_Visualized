#include "raylib.h"
#include "Window.h"
#include "ScalarProj.h"

enum STATE state = Menu;

int main()
{
	constexpr int Width = 800;
	constexpr int Height = 800;
	const int fps = 75;

	Window window = {Width, Height, 75, "Vector Projection/ Scalar Projection"};

	
	vectorstate = false;
	Vector2 Vec_a = { 400.0f, 400.0f };
	Vector2 Vec_b = GetMousePosition();
	ScalarProjection scalarproj = { Vec_a , Vec_b};
	while (!window.GameShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
		switch (state)
		{
		case Menu:
			scalarproj.Menu();
			if (IsKeyPressed(KEY_ONE))
			{
				state = Scalar;
			}
			if (IsKeyPressed(KEY_TWO))
			{
				state = Vector;
			}
			break;
		case Scalar:
			vectorstate = false;
			scalarproj.ScalarPorj_Implementation();
			if (IsKeyPressed(KEY_E))
			{
				state = Menu;
			}
			break;
		case Vector:
			vectorstate = true;
			scalarproj.ScalarPorj_Implementation();
			if (IsKeyPressed(KEY_E))
			{
				state = Menu;
			}
			break;
		}
		
		EndDrawing();
	}



	return 0;
}


