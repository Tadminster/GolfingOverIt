#include "stdafx.h"
#include "Ob_floor.h"
#include "Ball.h"

Ob_floor::Ob_floor()
{
	this->scale = Vector2(6000.f, 20.f);
	this->SetWorldPos(Vector2(0.f, -app.GetHalfHeight()+15.f));
}

bool Ob_floor::Collision(class GameObject* target)
{
	if (this->Intersect(target))
	{
		class Ball* ball = dynamic_cast<Ball*>(target);

		if (ball)
		{
			ball->SetWorldPos(Vector2(ball->GetWorldPos().x, ball->GetWorldPos().y + 0.1f));
			ball->gravityForce *= 0.6f;
			ball->pressPower *= 0.6f;
			ball->reflection_y();
		}
	}

	return false;
}