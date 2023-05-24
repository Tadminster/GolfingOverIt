#include "stdafx.h"
#include "Ob_drag.h"

Ob_drag::Ob_drag()
{
	this->scale = Vector2(200.f, 200.f);
	this->SetWorldPos(Vector2(0.f, 0.f));
	this->pivot = OFFSET_RT;
}

void Ob_drag::OnClick()
{

	static bool OnClick = false;
	static Vector2 ClickWorldPos;
	if (INPUT->KeyDown(VK_LBUTTON))
	{
		OnClick = true;
		ClickWorldPos = INPUT->GetWorldMousePos();
		this->SetWorldPos(ClickWorldPos);
	}

	if (INPUT->KeyUp(VK_LBUTTON))
	{
		OnClick = false;
	}

	if (OnClick)
		this->scale = ClickWorldPos - INPUT->GetWorldMousePos();
}