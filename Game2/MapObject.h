#pragma once
#define MAPMAX 38
#define FLBMAX 4
class MapObject
{
private:
	class Wall* map[MAPMAX];
	class Obstacle* floatingBall[FLBMAX];
	ObImage* backGroundImg;
	ObImage* wallImg[MAPMAX];
public:
	MapObject();
	~MapObject();
	void Init();
	void Update();
	void LateUpdate();
	void Render();

};

