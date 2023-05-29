#include "stdafx.h"
#include "Ball.h"
#include "Ending.h"

Ending::Ending()
{
	bonoBono = new ObRect();
	bonoBono_skin = new ObImage(L"bono.png");
	bonoBono_skin->SetParentRT(*bonoBono);

	bonoBono_script = new ObImage(L"script.png");

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

	bonoBono_script->scale.x = 0.0f;
	bonoBono_script->scale.y = 0.0f;
	bonoBono_script->SetWorldPosX(210.f);
	bonoBono_script->SetWorldPosY(2190.f);

}

void Ending::Update(Ball* ball)
{
	if (this->stage[0])
	{
		if (bonoBono->GetWorldPos().x > 0.0f)
			bonoBono->MoveWorldPos(LEFT * 300.f * DELTA);
		else
		{
			this->stage[0] = false;
			this->stage[1] = true;
		}
	}
	if (this->stage[1])
	{
		if (bonoBono->GetWorldPos().x < 300.0f)
		{
			bonoBono->MoveWorldPos(RIGHT * 300.f * DELTA);
			ball->SetWorldPos(bonoBono->GetWorldPos());
			ball->Update();
		}
		else
		{
			bonoBono_script->scale.x = bonoBono_script->imageSize.x / 4.f;
			bonoBono_script->scale.y = bonoBono_script->imageSize.y / 4.f;
			creationTime = TIMER->GetWorldTime();
			duration = 3.f;

			this->stage[1] = false;
			this->stage[2] = true;
		}
	}
	if (this->stage[2])
	{
		//ImGui::Text("\n");
		//ImGui::Text("WORLD_TIME: %f\n", TIMER->GetWorldTime());
		//ImGui::Text("creationTime_TIME: %f\n", creationTime);
		//ImGui::Text("duration: %f\n", duration);
		//ImGui::Text("timeOut: %f\n", creationTime + duration);

		if (TIMER->GetWorldTime() >= creationTime + duration)
		{
			ball->stop = false;
			ball->fire(DOWN * Vector2(100.f, 100.f));
			this->stage[2] = false;
			this->stage[3] = true;
		}
	}
	if (this->stage[3])
	{
		if (ball->isStop && ball->GetWorldPos().y < -30)
		{
			bonoBono_script->scale.x = 0.0f;
			bonoBono_script->scale.y = 0.0f;

			ball->fire(LEFT * Vector2(1000.f, 1000.f));
			this->stage[3] = false;
		}
	}


	bonoBono->Update();
	bonoBono_skin->Update();
	bonoBono_script->Update();
}

void Ending::LateUpdate()
{

}

void Ending::Render()
{
	//bonoBono->Render();
	bonoBono_skin->Render();
	bonoBono_script->Render();
}
