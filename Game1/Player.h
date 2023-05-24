#pragma once
class Player : public ObRect
{
public:
	// 플레이어 능력치
	int					speed;
	int					score;
	float				jump_power;
	float				jump_startPoint;
	float				charge_current;

	// 플레이어 상태
	int					hand;
	bool				jump_status;
	int					characterDirection; // 캐릭터 시선 방향


	// 무기
	class Gun_pistol*	pistol;

public:
	Player();
	virtual ~Player();
	void Init(Vector2 spawn, bool isLeft);
	void Control();
	void Control(Vector2 arrow);
	void Update() override;
	void Render() override;
};

