#pragma once
class Gun_pistol : public ObRect
{
public:
	// 조준선
	ObLine* line_sight;
	bool	hasLineSight;

public:
	// 스펙
	std::string		name;
	
	int				ammo_current;
	int				ammo_max;
	int				damage;
	float			range;
	float			ammo_speed;
	float			fire_rate;

	float			lastShotTime;
	float			timeSinceLastTime;

	std::vector<class Bullet_proto> bullets;

public:
	Gun_pistol();
	~Gun_pistol();
	void Update() override;
	void Render() override;

	virtual bool	Fire(class Player* shooter);
	virtual void	Update_Bullets();
	virtual void	Render_Bullets();

};

