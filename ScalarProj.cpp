#include "ScalarProj.h"
#include <iostream>

bool vectorstate = false;

ScalarProjection::ScalarProjection(Vector2 veca, Vector2 vecb)
{
	VecA = veca;
	VecB = vecb;
	ScalarProj = 0.0f;
}

ScalarProjection::~ScalarProjection() noexcept
{
}

// Find a way to make the center of the screen the origin
void ScalarProjection::ScalarPorj_Implementation()
{
	float Len_Veca = sqrtf(VecA.x * VecA.x + VecA.y * VecA.y);
	
	Vector2 UnitVecA = {VecA.x/Len_Veca, VecA.y/(Len_Veca)};


	Vector2 VecA_B = Vector2Subtract(VecB, VecA);

	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{
		VecB = GetMousePosition();
		
	}

	if(IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
	{
		VecA = GetMousePosition();
	}

	float ScalarProj = Vector2DotProduct(UnitVecA, VecA_B);

	//Simulating if the player clicks W it represent as the object is facing forward & and if S is clicked the player is looking backward
	if (IsKeyDown(KEY_D))
	{
		ScalarProj = ScalarProj;
	}
	else if (IsKeyDown(KEY_A))
	{
		ScalarProj = -ScalarProj;
	}

	//Visualizing Vector Projection
	if (vectorstate == true)
	{
		Vector2 vectorProj = { UnitVecA.x * ScalarProj, UnitVecA.y * ScalarProj };
		DrawCircle(VecA.x + vectorProj.x,VecA.y + vectorProj.y, 20.0f, WHITE);

		DrawText(TextFormat("X Coordinate Vector Projection: %f", vectorProj.x), 450, 120, 17, BLUE);
		DrawText(TextFormat("Y Coordinate Vector Projection: %f", vectorProj.y), 450, 140, 17, RED);
		DrawText(TextFormat("Press E to return to Main Menu: "), 100, 120, 17, WHITE);
	}
	else {
		DrawText(TextFormat("Press E to return to Main Menu: "), 100, 120, 17, WHITE);
		DrawText(TextFormat("Scalar Projection: %f", ScalarProj), 450, 120, 17, WHITE);
	}
	
	
	//vector A
	DrawCircle(VecA.x,VecA.y, 10, RED);

	//Vector B
	DrawCircle(VecB.x, VecB.y, 10, BLUE);

	//Vector A_B
	DrawLine(VecA.x, VecA.y, VecB.x, VecB.y, WHITE);

	//main point here is get the starting point add the unit vector then scale it to scalar projection size;
	//Scalar Projection Line Visualize
	DrawLine(VecA.x, VecA.y, VecA.x + UnitVecA.x * ScalarProj, VecA.y + UnitVecA.y * ScalarProj, WHITE);
	
	
}

void ScalarProjection::Menu()
{
	DrawText("VECTOR PROJECTION & SCALAR PROJECTION", 170, 200, 20, WHITE);
	DrawText("1. Scalar Projection", 170, 220, 20, WHITE);
	DrawText("2. Vector Projection", 170, 240, 20, WHITE);
	DrawText("Press the Number of your option", 170, 260, 20, WHITE);
}





/*float Len_Veca = sqrtf(VecA.x * VecA.x + VecA.y * VecA.y);
Vector2 UnitVec_a = { (VecA.x / Len_Veca), (VecA.y / Len_Veca) };
Vector2 NewUnitVecA = { (UnitVec_a.x * StartPos.x) ,  (UnitVec_a.y * StartPos.y) };

ScalarProj = Vector2DotProduct(NewUnitVecA, VecB);
if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
{
	VecB = GetMousePosition();
	ScalarProj = Vector2DotProduct(NewUnitVecA, VecB);
}

if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
{
	VecA = GetMousePosition();
	Len_Veca = sqrtf(VecA.x * VecA.x + VecA.y * VecA.y);
	UnitVec_a = { (VecA.x / Len_Veca), (VecA.y / Len_Veca) };
	NewUnitVecA = { (UnitVec_a.x * StartPos.x) ,  (UnitVec_a.y * StartPos.y) };
}
*/