#include "stdafx.h"
#include "Obstacle.h"

Obstacle::Obstacle()
{
	scale.x = 50.0f;
	scale.y = 50.0f;
	fireDir = GetRight();
	flbpower = 100.0f;
	isMove = true;
	hasAxis = false;
}

Obstacle::~Obstacle()
{
}

void Obstacle::Update()
{
	if (not isMove) return;
	MoveWorldPos(GetRight() * flbpower * DELTA);
	ObCircle::Update();
}

void Obstacle::Render()
{
	if (not isMove) return;
	ObCircle::Render();
}
