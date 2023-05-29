#pragma once
#define MAPMAX 38
#define FLBMAX 4
class Main : public Scene
{
private:
	class Title* title;
	class MapObject* mapObj;
	class Ending* ending;
	class Ball* golfBall;
	class Ball_guideLine* ball_guideLine[5];
	class ObRect* goal;
	ObImage* goal_skin;

	vector<class Ball_trail> trail;

	Vector2 mousepoint;
	Vector2 ballpoint;
	Vector2 point;
	Vector2 firepower;
	
	bool onClick = false;
	bool starting = false;
	bool isGameOver = false;
	float pow;

	bool ADMIN_MODE = false;
	bool gameStart = false;

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
