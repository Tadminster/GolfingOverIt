#include "stdafx.h"
#include "Title.h"

Title::Title()
{
	title_bg = new ObImage(L"main_title.png");

	btn_start = new ObRect();
	skin_start = new ObImage(L"btn_start.png");
	skin_start->SetParentRT(*btn_start);

	btn_exit= new ObRect();
	skin_exit = new ObImage(L"btn_exit.png");
	skin_exit->SetParentRT(*btn_exit);
}

Title::~Title()
{
	delete title_bg;
	delete btn_start;
	delete btn_exit;
	delete skin_start;
	delete skin_exit;
}

void Title::Init()
{
	title_bg->SetWorldPos(Vector2(0.0f, 0.0f));
	title_bg->scale.x = title_bg->imageSize.x;
	title_bg->scale.y = title_bg->imageSize.y;

	btn_start->SetWorldPos(Vector2(0.0f, -50.0f));
	btn_start->scale.x = 130.f;
	btn_start->scale.y = 70.f;

	skin_start->scale.x = btn_start->scale.x;
	skin_start->scale.y = btn_start->scale.y;

	btn_exit->SetWorldPos(Vector2(0.0f, -150.0f));
	btn_exit->scale.x = 130.f;
	btn_exit->scale.y = 70.f;

	skin_exit->scale.x = btn_start->scale.x;
	skin_exit->scale.y = btn_start->scale.y;
}

void Title::Update()
{
	title_bg->Update();

	btn_start->Update();
	btn_exit->Update();

	skin_start->Update();
	skin_exit->Update();
}

void Title::LateUpdate()
{
	if (btn_start->Intersect(INPUT->GetWorldMousePos()))
	{
		skin_start->color.x = 0.1f;
		skin_start->scale.x = btn_start->scale.x * 1.15f;
		skin_start->scale.y = btn_start->scale.y * 1.15f;
	}
	else
	{
		skin_start->color.x = 0.5f;
		skin_start->scale.x = btn_start->scale.x;
		skin_start->scale.y = btn_start->scale.y;
	}

	if (btn_exit->Intersect(INPUT->GetWorldMousePos()))
	{
		skin_exit->color.x = 0.1f;
		skin_exit->scale.x = btn_exit->scale.x * 1.15f;
		skin_exit->scale.y = btn_exit->scale.y * 1.15f;
	}
	else
	{
		skin_exit->scale.x = btn_exit->scale.x;
		skin_exit->scale.y = btn_exit->scale.y;
		skin_exit->color.x = 0.5f;
	}
}

void Title::Render()
{
	title_bg->Render();

	//btn_start->Render();
	//btn_exit->Render();

	skin_start->Render();
	skin_exit->Render();
}

int Title::onClick()
{
	if (INPUT->KeyDown(VK_LBUTTON))
	{
		if (btn_start->Intersect(INPUT->GetWorldMousePos()))
		{
			return 1;
		}
		if (btn_exit->Intersect(INPUT->GetWorldMousePos()))
		{
			return 0;
		}

		return 9;
	}
}
