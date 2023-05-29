#pragma once
#define MAPMAX 38
#define FLBMAX 4
class MapObject
{
private:
	ObImage* backGroundImg[3];
	ObImage* wallImg[MAPMAX];
public:
	class Wall* map[MAPMAX];
	class Obstacle* floatingBall[FLBMAX];

	MapObject();
	~MapObject();
	void Init();
	void Update();
	void LateUpdate();
	void Render();

};

