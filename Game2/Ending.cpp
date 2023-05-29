#include "stdafx.h"
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

void Ending::Update()
{
	bonoBono->Update();
	bonoBono_skin->Update();
}

void Ending::LateUpdate()
{
	if (stage[0])
		bonoBono->MoveWorldPos(LEFT * 300.f * DELTA);
}

void Ending::Render()
{
	//bonoBono->Render();
	bonoBono_skin->Render();
}
