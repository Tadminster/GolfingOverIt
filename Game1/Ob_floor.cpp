#include "stdafx.h"
#include "Ob_floor.h"

Ob_floor::Ob_floor()
{
	this->scale = Vector2(6000.f, 20.f);
	this->SetWorldPos(Vector2(0.f, -app.GetHalfHeight()+15.f));
}
