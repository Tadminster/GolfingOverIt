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
			if (ball->pressPower > 0.01f)
			{
				if (this->rotation.z == 0.0f)
				{
					ball->SetWorldPos(ball->GetWorldPos() + -ball->GetRight());
					ball->ReflectionX();
				}
				else if (this->rotation.z != 0.0f)
				{
					ball->SetWorldPos(ball->GetWorldPos() + this->GetRight());
				}
			}
			return true;
		}
	}

	return false;
}

bool Wall::OnMouse()
{
	if (INPUT->GetWorldMousePos().x > this->GetWorldPos().x - scale.x / 2.f &&
		INPUT->GetWorldMousePos().y > this->GetWorldPos().y - scale.y / 2.f &&
		INPUT->GetWorldMousePos().x < this->GetWorldPos().x + scale.x / 2.f &&
		INPUT->GetWorldMousePos().y < this->GetWorldPos().y + scale.y / 2.f)
	{
		ImGui::Text("ROTATION_Z: %f\n", this->rotation.z);

		return true;
	}
	return false;
}

