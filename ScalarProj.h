#pragma once
#include "raylib.h"
#include "raymath.h"
//unit vector a . vector b
class  ScalarProjection {
private:
	Vector2 VecA;
	Vector2 VecB;
	float ScalarProj;

public:
	ScalarProjection(Vector2 veca, Vector2 vecb);
	~ScalarProjection()noexcept;
	void ScalarPorj_Implementation();
};