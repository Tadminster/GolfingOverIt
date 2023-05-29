#include "stdafx.h"
#include "Wall.h"
#include "Obstacle.h"
#include "MapObject.h"

MapObject::MapObject()
{
	backGroundImg = new ObImage(L"bg_3.png");
	for (int i = 0; i < MAPMAX; i++)
		map[i] = new Wall();
	for (int i = 0; i < FLBMAX; i++) {
		floatingBall[i] = new Obstacle();
	}
	for (int i = 0; i < 4; i++) {
		wallImg[i] = new ObImage(L"ground_1.png");
		wallImg[i]->SetParentRT(*map[i]);
	}
	for (int i = 4; i < 34; i++) {
		wallImg[i] = new ObImage(L"ground_1.png");
		wallImg[i]->SetParentRT(*map[i]);
	}
	wallImg[34] = new ObImage(L"bono.png");
	wallImg[34]->SetParentRT(*map[34]);

	for (int i = 35; i < 38; i++) {
		wallImg[i] = new ObImage(L"wallImgRock.jpg");
		wallImg[i]->SetParentRT(*map[i]);
	}
}

MapObject::~MapObject()
{
	delete backGroundImg;
	for (int i = 0; i < MAPMAX; i++)
		delete map[i];
	for (int i = 0; i < FLBMAX; i++)
		delete floatingBall[i];
	for (int i = 0; i < MAPMAX; i++)
		delete wallImg[i];
}

void MapObject::Init()
{
	
	{
		floatingBall[0]->flbpower = 200.0f;
		floatingBall[0]->SetWorldPos(Vector2(0.0f, 380.0f));

		floatingBall[1]->flbpower = 300.0f;
		floatingBall[1]->SetWorldPos(Vector2(-200.0f, 700.0f));

		floatingBall[2]->flbpower = 250.0f;
		floatingBall[2]->SetWorldPos(Vector2(-100.0f, 1150.0f));

		floatingBall[3]->flbpower = 400.0f;
		floatingBall[3]->SetWorldPos(Vector2(-300.0f, 1500.0f));

		map[0]->scale.x = 300.0f;
		map[0]->scale.y = 50.0f;
		map[0]->SetWorldPos(Vector2(-300.0f, -275));
		map[1]->scale.x = 320.0f;
		map[1]->scale.y = 150.0f;
		map[1]->rotation.z = 10.0f * ToRadian;
		map[1]->SetWorldPos(Vector2(-5.0f, -300));
		map[2]->scale.x = 300.0f;
		map[2]->scale.y = 250.0f;
		map[2]->SetWorldPos(Vector2(250.0f, -330));
		map[3]->scale.x = 300.0f;
		map[3]->scale.y = 200.0f;
		map[3]->rotation.z = 40.0f * ToRadian;
		map[3]->SetWorldPos(Vector2(300.0f, -200));

		//35
		map[35]->scale.x = 95.0f;
		map[35]->scale.y = 70.0f;
		map[35]->SetWorldPos(Vector2(400.0f, -60));

		map[4]->scale.x = 200.0f;
		map[4]->scale.y = 50.0f;
		map[4]->SetWorldPos(Vector2(120.0f, 100));

		map[5]->scale.x = 100.0f;
		map[5]->scale.y = 25.0f;
		map[5]->SetWorldPos(Vector2(-100.0f, 200));

		map[6]->scale.x = 100.0f;
		map[6]->scale.y = 25.0f;
		map[6]->SetWorldPos(Vector2(-170.0f, 220));
		map[6]->rotation.z = -30.0f * ToRadian;

		map[7]->scale.x = 200.0f;
		map[7]->scale.y = 30.0f;
		map[7]->SetWorldPos(Vector2(-350.0f, 350));
		map[7]->rotation.z = 20.0f * ToRadian;

		map[8]->scale.x = 200.0f;
		map[8]->scale.y = 50.0f;
		map[8]->SetWorldPos(Vector2(-150.0f, 500));

		map[9]->scale.x = 200.0f;
		map[9]->scale.y = 50.0f;
		map[9]->SetWorldPos(Vector2(100.0f, 600));

		map[10]->scale.x = 100.0f;
		map[10]->scale.y = 20.0f;
		map[10]->rotation.z = 60.0f * ToRadian;
		map[10]->SetWorldPos(Vector2(300.0f, 750));

		map[11]->scale.x = 90.0f;
		map[11]->scale.y = 20.0f;
		map[11]->SetWorldPos(Vector2(360.0f, 790));

		map[12]->scale.x = 150.0f;
		map[12]->scale.y = 30.0f;
		map[12]->SetWorldPos(Vector2(120.0f, 850));

		map[13]->scale.x = 150.0f;
		map[13]->scale.y = 30.0f;
		map[13]->SetWorldPos(Vector2(-120.0f, 850));

		map[14]->scale.x = 250.0f;
		map[14]->scale.y = 50.0f;
		map[14]->SetWorldPos(Vector2(-400.0f, 950));

		//21
		map[21]->scale.x = 100.0f;
		map[21]->scale.y = 50.0f;
		map[21]->SetWorldPos(Vector2(-100.0f, 1050));

		map[15]->scale.x = 150.0f;
		map[15]->scale.y = 50.0f;
		map[15]->SetWorldPos(Vector2(-400.0f, 1150));

		map[16]->scale.x = 100.0f;
		map[16]->scale.y = 100.0f;
		map[16]->SetWorldPos(Vector2(-100.0f, 1300));

		map[17]->scale.x = 50.0f;
		map[17]->scale.y = 10.0f;
		map[17]->rotation.z = 60.0f * ToRadian;
		map[17]->SetWorldPos(Vector2(50.0f, 1400));

		map[18]->scale.x = 70.0f;
		map[18]->scale.y = 10.0f;
		map[18]->SetWorldPos(Vector2(90.0f, 1420));

		map[19]->scale.x = 50.0f;
		map[19]->scale.y = 10.0f;
		map[19]->rotation.z = -60.0f * ToRadian;
		map[19]->SetWorldPos(Vector2(130.0f, 1400));

		map[20]->scale.x = 50.0f;
		map[20]->scale.y = 10.0f;
		map[20]->rotation.z = -60.0f * ToRadian;
		map[20]->SetWorldPos(Vector2(200.0f, 1500));

		//22
		map[22]->scale.x = 70.0f;
		map[22]->scale.y = 10.0f;
		map[22]->SetWorldPos(Vector2(240.0f, 1480));

		map[23]->scale.x = 100.0f;
		map[23]->scale.y = 40.0f;
		map[23]->SetWorldPos(Vector2(380.0f, 1600));

		map[24]->scale.x = 150.0f;
		map[24]->scale.y = 40.0f;
		map[24]->SetWorldPos(Vector2(200.0f, 1700));

		map[25]->scale.x = 30.0f;
		map[25]->scale.y = 200.0f;
		map[25]->SetWorldPos(Vector2(130.0f, 1780));

		map[27]->scale.x = 60.0f;
		map[27]->scale.y = 10.0f;
		map[27]->rotation.z = -50.0f * ToRadian;
		map[27]->SetWorldPos(Vector2(50.0f, 1710));

		map[26]->scale.x = 80.0f;
		map[26]->scale.y = 20.0f;
		map[26]->SetWorldPos(Vector2(0.0f, 1730));

		map[28]->scale.x = 60.0f;
		map[28]->scale.y = 10.0f;
		map[28]->rotation.z = -50.0f * ToRadian;
		map[28]->SetWorldPos(Vector2(-50.0f, 1750));

		map[29]->scale.x = 100.0f;
		map[29]->scale.y = 30.0f;
		map[29]->SetWorldPos(Vector2(-170.0f, 1630));

		map[30]->scale.x = 100.0f;
		map[30]->scale.y = 30.0f;
		map[30]->SetWorldPos(Vector2(-350.0f, 1780));

		map[31]->scale.x = 10.0f;
		map[31]->scale.y = 150.0f;
		map[31]->SetWorldPos(Vector2(-170.0f, 1930));

		map[32]->scale.x = 50.0f;
		map[32]->scale.y = 20.0f;
		map[32]->SetWorldPos(Vector2(-200.0f, 1900));

		map[33]->scale.x = 100.0f;
		map[33]->scale.y = 30.0f;
		map[33]->SetWorldPos(Vector2(-350.0f, 2030));

		//골대
		map[34]->scale.x = 50.0f;
		map[34]->scale.y = 50.0f;
		map[34]->SetWorldPos(Vector2(0.0f, 2200));

		map[36]->scale.x = 100.0f;
		map[36]->scale.y = 4600.0f;
		map[36]->pivot = OFFSET_B;
		map[36]->SetWorldPos(Vector2(-450.0f, 0.0f));

		map[37]->scale.x = 100.0f;
		map[37]->scale.y = 4600.0f;
		map[37]->pivot = OFFSET_B;
		map[37]->SetWorldPos(Vector2(450.0f, 0.0f));
	}
	for (int i = 0; i < 4; i++) {
		wallImg[i]->scale.x = map[i]->scale.x;
		wallImg[i]->scale.y = map[i]->scale.y;
	}
	for (int i = 4; i < MAPMAX; i++) {
		wallImg[i]->scale.x = map[i]->scale.x;
		wallImg[i]->scale.y = map[i]->scale.y;
	}
	backGroundImg->SetWorldPos(Vector2(0.0f, 900.0f));
	backGroundImg->scale.x = app.GetWidth();
	backGroundImg->scale.y = 2800;
	;
}

void MapObject::Update()
{
	for (int i = 0; i < 19; i++)
	{
		map[i]->OnMouse();
	}
	if (floatingBall[0]->GetWorldPos().x <= -200.0f) {
		floatingBall[0]->SetWorldPosX(-199.0f);
		floatingBall[0]->ReflectionY();
	}
	else if (floatingBall[0]->GetWorldPos().x >= 300.0f) {
		floatingBall[0]->SetWorldPosX(299.0f);
		floatingBall[0]->ReflectionY();
	}
	floatingBall[0]->Update();

	if (floatingBall[1]->GetWorldPos().x <= -300.0f) {
		floatingBall[1]->SetWorldPosX(-299.0f);
		floatingBall[1]->ReflectionY();
	}
	else if (floatingBall[1]->GetWorldPos().x >= 0.0f) {
		floatingBall[1]->SetWorldPosX(-1.0f);
		floatingBall[1]->ReflectionY();
	}
	floatingBall[1]->Update();

	if (floatingBall[2]->GetWorldPos().x <= -200.0f) {
		floatingBall[2]->SetWorldPosX(-199.0f);
		floatingBall[2]->ReflectionY();
	}
	else if (floatingBall[2]->GetWorldPos().x >= 200.0f) {
		floatingBall[2]->SetWorldPosX(199.0f);
		floatingBall[2]->ReflectionY();
	}
	floatingBall[2]->Update();

	if (floatingBall[3]->GetWorldPos().x <= -350.0f) {
		floatingBall[3]->SetWorldPosX(-349.0f);
		floatingBall[3]->ReflectionY();
	}
	else if (floatingBall[3]->GetWorldPos().x >= -50.0f) {
		floatingBall[3]->SetWorldPosX(-51.0f);
		floatingBall[3]->ReflectionY();
	}
	floatingBall[3]->Update();
	for (int i = 0; i < MAPMAX; i++) {
		wallImg[i]->Update();
	}
	for (int i = 0; i < MAPMAX; i++)
	{
		map[i]->Update();
	}
	backGroundImg->Update();
}

void MapObject::LateUpdate()
{

}

void MapObject::Render()
{
	backGroundImg->Render();
	for (int i = 0; i < MAPMAX; i++) wallImg[i]->Render();
	for (int i = 0; i < FLBMAX; i++) floatingBall[i]->Render();
}
