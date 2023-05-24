#include "stdafx.h"
#include "Ob_movable.h"

Ob_movable::Ob_movable()
{
	this->scale = Vector2(200.f, 200.f);
	this->SetWorldPos(Vector2(0.f, 0.f));
}

int Ob_movable::OnMouse()
{
	// 1분면(RU) ++ 
	if (INPUT->GetWorldMousePos().x > this->GetWorldPos().x &&
		INPUT->GetWorldMousePos().x < this->GetWorldPos().x + scale.x / 2.f &&
		INPUT->GetWorldMousePos().y > this->GetWorldPos().y &&
		INPUT->GetWorldMousePos().y < this->GetWorldPos().y + scale.y / 2.f)
	{
		return 1;
	}
	// 2분면(LU) -+ 
	if (INPUT->GetWorldMousePos().x < this->GetWorldPos().x &&
		INPUT->GetWorldMousePos().x > this->GetWorldPos().x - scale.x / 2.f &&
		INPUT->GetWorldMousePos().y > this->GetWorldPos().y &&
		INPUT->GetWorldMousePos().y < this->GetWorldPos().y + scale.y / 2.f)
	{
		return 2;
	}
	// 3분면(LD) -- 
	if (INPUT->GetWorldMousePos().x < this->GetWorldPos().x &&
		INPUT->GetWorldMousePos().x > this->GetWorldPos().x - scale.x / 2.f &&
		INPUT->GetWorldMousePos().y < this->GetWorldPos().y &&
		INPUT->GetWorldMousePos().y > this->GetWorldPos().y - scale.y / 2.f)
	{
		return 3;
	}
	// 4분면(RD) +- 
	if (INPUT->GetWorldMousePos().x > this->GetWorldPos().x &&
		INPUT->GetWorldMousePos().x < this->GetWorldPos().x + scale.x / 2.f &&
		INPUT->GetWorldMousePos().y < this->GetWorldPos().y &&
		INPUT->GetWorldMousePos().y > this->GetWorldPos().y - scale.y / 2.f)
	{
		return 4;
	}

	return 0;
}

void Ob_movable::Control()
{

	static bool OnClick = false;
	static Vector2 ClickWorldPos;
	if (INPUT->KeyDown(VK_LBUTTON) && OnMouse() != 0)
	{
		OnClick = true;
		ClickWorldPos = Vector2(this->GetWorldPos().x - INPUT->GetWorldMousePos().x,
								this->GetWorldPos().y - INPUT->GetWorldMousePos().y);
	}

	if (INPUT->KeyUp(VK_LBUTTON))
	{
		OnClick = false;
	}

	if (OnClick)
		this->SetWorldPos(INPUT->GetWorldMousePos()+ClickWorldPos);
}

void Ob_movable::SetColor()
{
	if (Ob_movable::OnMouse() == 0)
	{
		this->color = Color(0.f, 0.f, 0.f, 1.f);
		return;
	}

	Vector2 ClickWorldPos = Vector2((this->GetWorldPos().x - INPUT->GetWorldMousePos().x) / 100.f,
								(this->GetWorldPos().y - INPUT->GetWorldMousePos().y) / 100.f);
	float temp = (ClickWorldPos.x + ClickWorldPos.y) / 2.f;


	std::cout << temp << endl;

	if (Ob_movable::OnMouse() == 1)
	{
		this->color = Color(temp + 1.f, 0.5f, 0.5f, 1.f);
	}
	else if (Ob_movable::OnMouse() == 2)
	{

		this->color = Color(0.5f, temp + 0.5f, 0.5f, 1.f);
	}
	else if (Ob_movable::OnMouse() == 3)
	{
		this->color = Color(0.5f, 0.5f, temp, 1.f);
	}
	else if (Ob_movable::OnMouse() == 4)
	{
		this->color = Color(temp + 0.5f, temp + 0.5f, temp + 0.5f, 1.f);
	}
}
