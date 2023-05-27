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
	class Ball* ball = dynamic_cast<Ball*>(target);
	if (this->Intersect(target))
	{
		
		switch ((this->IntersectS(target)))
		{
		case 1: //왼쪽
			ball->SetWorldPos(ball->GetWorldPos() + -ball->GetRight());
			ball->Reflection(-(this->GetRight())*1.3);
			break;
		case 2: //오른
			ball->SetWorldPos(ball->GetWorldPos() + -ball->GetRight());
			ball->Reflection((this->GetRight()) * 1.3);
			break;
		case 3: //위
			ball->SetWorldPos(ball->GetWorldPos() + -ball->GetRight());
			ball->Reflection((this->GetUp()) * 1.3);
			break;
		case 4: //아래
			ball->SetWorldPos(ball->GetWorldPos() + -ball->GetRight());
			ball->Reflection(-(this->GetUp()) * 1.3);
			break;
		default:
			break;
		}

	}


	/*if (this->Intersect(target))
	{
		class Ball* ball = dynamic_cast<Ball*>(target);

		if (ball)
		{
			ball->SetWorldPos(ball->GetWorldPos() + -ball->GetRight());
			ball->ReflectionX();
			return true;
		}
	}*/

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

