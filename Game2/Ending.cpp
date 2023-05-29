#include "stdafx.h"
#include "Ball.h"
#include "Ending.h"

Ending::Ending()
{
	bonoBono = new ObRect();
	bonoBono_skin = new ObImage(L"bono.png");
	bonoBono_skin->SetParentRT(*bonoBono);

	for (auto& stage : this->stage)
		stage = false;
}

Ending::~Ending()
{
	delete bonoBono_skin;
	delete bonoBono;
}

void Ending::Init()
{
	bonoBono->scale.x = 40;
	bonoBono->scale.y = 50;
	bonoBono->SetWorldPosX(300.f);
	bonoBono->SetWorldPosY(2250.f);

	bonoBono_skin->scale.x = bonoBono->scale.x;
	bonoBono_skin->scale.y = bonoBono->scale.y;
}

void Ending::Update(Ball* ball)
{
	if (this->stage[0])
	{
		if (bonoBono->GetWorldPos().x > 0.0f)
			bonoBono->MoveWorldPos(LEFT * 300.f * DELTA);
		else
		{
			ball->stop = false;
			this->stage[0] = false;
			this->stage[1] = true;
		}
	}
	else if (this->stage[1])
	{
		if (bonoBono->GetWorldPos().x < 300.0f)
		{
			bonoBono->MoveWorldPos(RIGHT * 300.f * DELTA);
			ball->SetWorldPos(bonoBono->GetWorldPos());
			ball->Update();
		}
		else
		{
			ball->fire(DOWN * Vector2(100.f, 100.f));
			this->stage[1] = false;
			this->stage[2] = true;
		}
	}
	else if (this->stage[2])
	{
		if (ball->GetWorldPos().y < -55.f)
		{
			ball->fire(RIGHT);
		}
		else
		{
			this->stage[2] = false;
		}
	}


	bonoBono->Update();
	bonoBono_skin->Update();
}

void Ending::LateUpdate()
{

}

void Ending::Render()
{
	//bonoBono->Render();
	bonoBono_skin->Render();
}
