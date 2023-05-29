#include "stdafx.h"
#include "Wall.h"
#include "Ball.h"
#include "Ball_guideLine.h"
#include "Ball_trail.h"
#include "Obstacle.h"
#include "Main.h"

Main::Main()
{
	for (int i = 0; i < MAPMAX; i++)
		map[i] = new Wall();
	for (int i = 0; i < FLBMAX; i++) {
		floatingBall[i] = new Obstacle();
	}
	for (int i = 0; i < MAPMAX; i++) {
		wallImg[i] = new ObImage(L"bono.bmp");
		wallImg[i]->SetParentRT(*map[i]);
	}

	golfBall = new Ball();
	for (int i = 0; i < 5; i++)
	{
		ball_guideLine[i] = new Ball_guideLine();
		ball_guideLine[i]->SetParentT(*golfBall);
		ball_guideLine[i]->color = Color(0.0f + i * 0.2f, 0.8f - i * 0.1f, 0.1f, 0.5f);
	}
	goal = new ObRect();
}

Main::~Main()
{
	for (int i = 0; i < MAPMAX; i++) 
		delete map[i];
	for (int i = 0; i < FLBMAX; i++)
		delete floatingBall[i];
	for (int i = 0; i < MAPMAX; i++)
		delete wallImg[i];
	for (auto& guideLine : ball_guideLine)
		delete guideLine;
	delete golfBall;
	delete goal;

}
void Main::Init()
{
	// 공
	golfBall->SetWorldPos(Vector2(-300,50));
	golfBall->fire(Vector2(-50.0f, 0.0f));

	// 공의 유도선
	for (int i = 0; i < 5; i++)
		ball_guideLine[i]->SetLocalPosX(30 + i * 40);

	// 맵의 오브젝트
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
		map[0]->SetWorldPos(Vector2(-250.0f, -275));
		map[1]->scale.x = 320.0f;
		map[1]->scale.y = 150.0f;
		map[1]->rotation.z = 10.0f * ToRadian;
		map[1]->SetWorldPos(Vector2(0.0f, -300));
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
	for (int i = 0; i < MAPMAX; i++) {
		wallImg[i]->scale.x = map[i]->scale.x;
		wallImg[i]->scale.y = map[i]->scale.y;
	}

	//골대
	goal->SetWorldPos(Vector2(0.0f, 2240.0f));
	goal->scale = Vector2(20.0f, 20.0f);
	goal->color = Vector4(0, 0, 0, 1);
}

void Main::Release()
{
}

void Main::Update()
{
	// Debug 출력 창
	{
		ImGui::Text("CAMERA_X: %f\n", CAM->position.x);
		ImGui::Text("CAMERA_Y: %f\n", CAM->position.y);
		ImGui::Text("\n");

		ImGui::Text("BALL_X: %f\n", golfBall->GetWorldPos().x);
		ImGui::Text("BALL_Y: %f\n", golfBall->GetWorldPos().y);
		ImGui::Text("BALL_RIGHT: %f\n", golfBall->GetRight());
		ImGui::Text("\n");

		ImGui::Text("MOUSE_X: %f\n", INPUT->GetWorldMousePos().x);
		ImGui::Text("MOUSE_Y: %f\n", INPUT->GetWorldMousePos().y);
	}

	// 맵의 오브젝트
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
	}

	// 관리자 모드
	{
		if (INPUT->KeyPress('Z'))
		{
			golfBall->hasAxis = true;
			ADMIN_MODE = true;
		}
		if (INPUT->KeyPress('X'))
		{
			golfBall->hasAxis = false;
			ADMIN_MODE = false;
		}

		if (ADMIN_MODE)
		{			
			//공이동			
			if (INPUT->KeyPress('W'))
			{				
				golfBall->MoveWorldPos(UP * 500.0f * DELTA);
			}
			if (INPUT->KeyPress('S'))
			{
				golfBall->MoveWorldPos(DOWN * 500.0f * DELTA);
			}
			if (INPUT->KeyPress('A'))
			{
				golfBall->MoveWorldPos(LEFT * 500.0f * DELTA);
			}
			if (INPUT->KeyPress('D'))
			{
				golfBall->MoveWorldPos(RIGHT * 500.0f * DELTA);
			}
			golfBall->gravityForce = 0.0f;
			golfBall->pressPower = 0.0f;
			golfBall->Update();
		}		
	}

	// 카메라가 공에 따라가게
	CAM->position.y = golfBall->GetWorldPos().y + 100.0f;
	CAM->position.x = golfBall->GetWorldPos().x;
	CAM->position.x = Utility::Saturate(CAM->position.x, -400.0f, 400.0f);
	CAM->position.y = Utility::Saturate(CAM->position.y, -200.0f, 2000.0f);

	// 공의 클릭 관련
	{
		// 공이 멈췄을 때
		if (golfBall->stopcheck())
		{
			golfBall->color = Color(1.f, 1.f, 1.f, 1.f);	// 색상을 검정으로

			// 마우스가 공위에 있으면
			if (golfBall->Intersect(INPUT->GetWorldMousePos()))
			{
				// 좌클을 누르면
				if (INPUT->KeyDown(VK_LBUTTON))
				{
					onClick = true;						// 클릭 신호를 주고
					point = golfBall->GetWorldPos();	// 공의 위치를 저장
				}
			}
			// 공을 클릭했으면
			if (onClick)
			{
				// 유도선을 그려줌
				for (int i = 0; i < 5; i++)
				{
					Vector2 direction = INPUT->GetWorldMousePos() - point;						// 계산에 쓰일 벡터
					ball_guideLine[i]->rotation2.z = atan2f(direction.y, direction.x) + PI;		// 유도선 방향 계산
					ball_guideLine[i]->Update();												
				}
				// 클릭을 떼면 발사
				if (INPUT->KeyUp(VK_LBUTTON))
				{
					firepower = point - INPUT->GetWorldMousePos();
					golfBall->fire(firepower);
					golfBall->Update();
					onClick = false;
				}
			}
		}
		else
		{
			golfBall->color = Color(0.f, 0.f, 0.f, 1.f);
			golfBall->Update();
		}

		if (starting == 0) golfBall->Update();
	}


	// 궤적 관련
	{
		//ImGui::Text("TRAIL COUNT: %d\n", trail.size());
		// 궤적 생성
		if (!golfBall->isStop)
		{
			trail.push_back(Ball_trail(golfBall->GetWorldPos()));
			for (auto& trail : this->trail)
				trail.Update();
		}

		// 궤적의 지속시간이 경과되면 삭제
		trail.erase
		(
			std::remove_if
			(
				trail.begin(),
				trail.end(),
				[](Ball_trail& t) { return t.timeOut(); }
			),
			trail.end()
		);
	}



	for (int i = 0; i < MAPMAX; i++) {
		wallImg[i]->Update();
	}
	for (int i = 0; i < MAPMAX; i++)
	{
		map[i]->Update();
	}

	goal->Update();
}

void Main::LateUpdate()
{
	// 임시벽
	if (golfBall->GetWorldPos().y < -300.0f + 10.0f)
	{
		golfBall->SetWorldPosY(-300.0f + 10.0f);
		golfBall->ReflectionX();
		golfBall->Update();
	}

	if (golfBall->GetWorldPos().x < -400.0f + 10.0f)
	{
		golfBall->SetWorldPosX(-400.0f + 10.0f);
		golfBall->ReflectionY();
		golfBall->Update();
		starting = true;
	}
	else if (golfBall->GetWorldPos().x > 400.0f - 10.0f)
	{
		golfBall->SetWorldPosX(400.0f - 10.0f);
		golfBall->ReflectionY();
		golfBall->Update();
	}


	//벽충돌
	for (int i = 0; i < MAPMAX; i++)
	{
		map[i]->Collision(golfBall);
	}
	//방해물충돌
	for (int i = 0; i < FLBMAX; i++)
	{
		if (floatingBall[i]->Intersect(golfBall)) golfBall->ReflectionBall(floatingBall[i]);
	}
	//골대충돌
	if (goal->Intersect(golfBall)) isGameOver = true;
}

void Main::Render()
{
	for (int i = 0; i < MAPMAX; i++) wallImg[i]->Render();
	for (int i = 0; i < FLBMAX; i++) floatingBall[i]->Render();
	for (int i = 0; i < MAPMAX; i++)
	{
		golfBall->Render();

		if (onClick)
			for (int i = 0; i < 5; i++)
			{
				Vector2 distance = (golfBall->GetWorldPos() - INPUT->GetWorldMousePos());
				//ImGui::Text("d: %f\n", distance.Length());
				//ImGui::Text("d: %f\n", distance.Length() / 60.f);
				if (distance.Length() / 100.f > i)
				{
					ball_guideLine[i]->Render();
				}
			}
	}

	for (auto& trail : this->trail)
		trail.Render();

	goal->Render();
}

void Main::ResizeScreen()
{
	
}

int WINAPI wWinMain(HINSTANCE instance, HINSTANCE prevInstance, LPWSTR param, int command)
{
	app.SetAppName(L"Game2");
	app.SetInstance(instance);
	app.InitWidthHeight(800.0f, 600.0f);
	WIN->Create();
	Main* main = new Main();
	int wParam = (int)WIN->Run(main);
	SafeDelete(main);
	WIN->Destroy();
	WIN->DeleteSingleton();
	
	return wParam;
}