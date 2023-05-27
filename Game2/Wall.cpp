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
		static int x = 0;
		// 다운캐스팅
		class Ball* ball = dynamic_cast<Ball*>(target);

		// 만약 target이 Ball 클래스라면
		if (ball)
		{
			// 일반 벽에 부딪쳤을 때
			if (this->rotation.z == 0.0f)
			{
				ball->SetWorldPos(ball->GetWorldPos() + -ball->GetRight());
				ball->ReflectionX();
			}
			// 기울어진 벽에 부딪쳤을 때
			else
			{
				ball->SetWorldPos(ball->GetWorldPos() + UP);
				ball->ReflectionX();
				// 공이 멈추지 않았다면, 벽의 기울기만큼 이동 (미끄러짐)
				if (!ball->isStop)
				{
					cout << "충돌 발생 " << x++ << endl;
					ball->SetWorldPos(ball->GetWorldPos() + -this->GetRight());
				}

			}
			// 충돌이 잘 일어났으면 true 반환
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

