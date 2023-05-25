#include "stdafx.h"
#include "Wall.h"
#include "Ball.h"

Wall::Wall()
{
}

Wall::~Wall()
{
}

bool Wall::Collision(GameObject* target)
{
	if (this->Intersect(target))
	{
		class Ball* ball = dynamic_cast<Ball*>(target);

		if (ball)
		{
			ball->SetWorldPos(ball->GetWorldPos() + -ball->GetRight());
			ball->ReflectionX();
			return true;
		}
	}

	return false;
}

