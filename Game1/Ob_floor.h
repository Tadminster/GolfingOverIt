#pragma once
class Ob_floor : public ObRect
{
public:
	Ob_floor();

	bool Collision(class GameObject* target);
};

