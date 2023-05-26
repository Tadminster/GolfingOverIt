#pragma once
class Wall : public ObRect 
{

public:
	Wall();
	virtual ~Wall();

	bool Collision(class GameObject* target);
	bool OnMouse();
};

