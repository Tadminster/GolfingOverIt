#pragma once
class Ball : public ObCircle
{
public:
	float           pressPower;                 // 차지
	Vector2			direction;

	Vector2         gravityDiretion;        // 중력 방향
	float           gravityForce;           // 중력 힘
	float           gravityWeight;          // 중력 가중치

	bool			status_stop;

public:
	Ball();
	virtual ~Ball();
	void Init(Vector2 spawn, bool isLeft);

	void Control();
	void Update() override;

	//bool hasIntersect(class GameObject* target);
	//bool collision(class GameObject* target);

	void reflection_y();
	void reflection_x();
	void checkStop();
};
