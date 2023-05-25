#pragma once
class Player : public ObCircle
{
	class Bullet* bullet[30];

	//시계프레임
	ObRect* gauge;
	ObRect* gauge2;
	float pressPower;
public:
	Player();
	virtual ~Player();
	void Init(Vector2 spawn,bool isLeft);
	void Control();
	void Update() override;
	void Render() override;
	float GetHp() { return gauge2->scale.x; }
	Bullet* GetBullet(int i) const { return bullet[i]; }
	void Damage(float dmg) { gauge2->scale.x -= dmg; }
	//const Bullet** GetBullet() { return bullet; }
};

