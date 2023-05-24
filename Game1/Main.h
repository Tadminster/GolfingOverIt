#pragma once
#define number_star 500

class Main : public Scene
{
private:
	// 지형
	class ObStar* bg_star[number_star];
	class Ob_floor* floor;
	
	// 사물
	class Ob_movable* rect_movable;
	class Ob_drag* rect_drag;

	// 플레이어
	class Player* player;
	class Gun_pistol* pistol;

	//class Ball* ball;
	//class Player* goalpost[2];

public:
	Main();
	~Main();
	virtual void Init() override;
	virtual void Release() override; //해제
	virtual void Update() override;
	virtual void LateUpdate() override;//갱신
	virtual void Render() override;
	virtual void ResizeScreen() override;
};
