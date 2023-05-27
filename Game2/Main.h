#pragma once
#define MAPMAX 100
class Main : public Scene
{
private:
	class Wall* map[MAPMAX];
	class Ball* Golfball;

	Vector2 mousepoint;
	Vector2 ballpoint;
	Vector2 point;
	Vector2 firepower;
	
	bool isStop= false;
	bool onClick = false;
	bool starting = false;
	float pow;

	bool hi;
	bool hello;

	int donghwa;
	int chenhee;
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
