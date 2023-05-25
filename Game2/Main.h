#pragma once
#define MAPMAX 100
class Main : public Scene
{
private:
	ObRect* map[MAPMAX];
	class Ball* Golfball;

	Vector2 mousepoint;
	Vector2 ballpoint;
	Vector2 point;
	Vector2 firepower;
	
	bool isStop= false;
	bool onClick = false;
	float pow;

public:
	Main();
	~Main();
	virtual void Init() override;
	virtual void Release() override; //����
	virtual void Update() override;
	virtual void LateUpdate() override;//����
	virtual void Render() override;
	virtual void ResizeScreen() override;
};
