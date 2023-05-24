#pragma once
class Ball : public ObCircle
{
public:
	float speed;
	Vector2 direction;

public:
	Ball();
	virtual ~Ball();
	void Init(Vector2 spawn, bool isLeft);

	void Control();
	void Update() override;
	void Render() override;

	bool hasIntersect(class GameObject* target);
	bool collision(class GameObject* target);

    void reflection_y() { this->direction.x = -this->direction.x;}
	void reflection_x() { this->direction.y = -this->direction.y;}
};
