#include "stdafx.h"
#include "Ball_trail.h"

Ball_trail::Ball_trail(Vector2 ballPos)
{
	this->SetWorldPos(ballPos);

	this->scale.x = 3.f;
	this->scale.y = 3.f;
	this->color = Color(1.f, 1.f, 1.f, 1.f);

	this->hasAxis = false;

	creationTime = TIMER->GetWorldTime();
	duration = 1.0f;
}
