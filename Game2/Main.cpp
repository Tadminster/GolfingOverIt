#include "stdafx.h"
#include "Ball.h"
#include "Main.h"

Main::Main()
{
	for (int i = 0; i < MAPMAX; i++)
		map[i] = new ObRect();

	Golfball = new Ball();
}

Main::~Main()
{
	for (int i = 0; i < MAPMAX; i++) 
		delete map[i];
	
	delete Golfball;
}
void Main::Init()
{
	Golfball->SetWorldPos(Vector2(0,0));

	map[0]->scale.x = 300.0f;
	map[0]->scale.y = 100.0f;
	map[0]->SetWorldPos(Vector2(-250.0f, -250));
	map[1]->scale.x = 320.0f;
	map[1]->scale.y = 150.0f;
	map[1]->SetWorldPos(Vector2(0.0f, -225));
	map[1]->rotation.z = 30.0f * ToRadian;
	map[2]->scale.x = 300.0f;
	map[2]->scale.y = 250.0f;
	map[2]->SetWorldPos(Vector2(250.0f, -200));
	map[3]->scale.x = 300.0f;
	map[3]->scale.y = 200.0f;
	map[3]->SetWorldPos(Vector2(350.0f, 5));
	map[3]->rotation.z = 60.0f * ToRadian;
	map[4]->scale.x = 200.0f;
	map[4]->scale.y = 50.0f;
	map[4]->SetWorldPos(Vector2(120.0f, 250));
	map[5]->scale.x = 100.0f;
	map[5]->scale.y = 25.0f;
	map[5]->SetWorldPos(Vector2(-100.0f, 300));
	map[6]->scale.x = 100.0f;
	map[6]->scale.y = 25.0f;
	map[6]->SetWorldPos(Vector2(-170.0f, 320));
	map[6]->rotation.z = 150.0f * ToRadian;
	map[7]->scale.x = 200.0f;
	map[7]->scale.y = 30.0f;
	map[7]->SetWorldPos(Vector2(-350.0f, 450));
	map[7]->rotation.z = 20.0f * ToRadian;

	map[8]->scale.x = 200.0f;
	map[8]->scale.y = 50.0f;
	map[8]->SetWorldPos(Vector2(-150.0f, 600));

	map[9]->scale.x = 200.0f;
	map[9]->scale.y = 50.0f;
	map[9]->SetWorldPos(Vector2(100.0f, 700));

	map[10]->scale.x = 100.0f;
	map[10]->scale.y = 20.0f;
	map[10]->rotation.z = 60.0f * ToRadian;
	map[10]->SetWorldPos(Vector2(300.0f, 850));

	map[11]->scale.x = 90.0f;
	map[11]->scale.y = 20.0f;
	map[11]->SetWorldPos(Vector2(360.0f, 890));

	map[12]->scale.x = 150.0f;
	map[12]->scale.y = 30.0f;
	map[12]->SetWorldPos(Vector2(120.0f, 950));

	map[13]->scale.x = 150.0f;
	map[13]->scale.y = 30.0f;
	map[13]->SetWorldPos(Vector2(-80.0f, 850));

	map[14]->scale.x = 250.0f;
	map[14]->scale.y = 50.0f;
	map[14]->SetWorldPos(Vector2(-300.0f, 1050));

	map[15]->scale.x = 150.0f;
	map[15]->scale.y = 50.0f;
	map[15]->SetWorldPos(Vector2(-400.0f, 1250));
}

void Main::Release()
{
}

void Main::Update()
{
	


	if (Golfball->stopcheck())
	{
		Golfball->color = Vector4(0, 1, 0, 1);
		if (Golfball->Intersect(INPUT->GetWorldMousePos()))
		{
			if (INPUT->KeyDown(VK_LBUTTON))
			{
				onClick = true;
				point = Golfball->GetWorldPos();
			}
		}
			if (onClick)
			{	
				firepower = point-INPUT->GetWorldMousePos();
				//Golfball->SetgravityForve(0.0f);

				if (INPUT->KeyUp(VK_LBUTTON))
				{	
					Golfball->fire(firepower);
					Golfball->Update();
					onClick = false;
				}
			}
	}
	else Golfball->color = Vector4(1, 0, 0, 1);
	
	for (int i = 0; i < MAPMAX; i++) 
	{
		map[i]->Update();
	}

	Golfball->Update();
}

void Main::LateUpdate()
{
	if (Golfball->GetWorldPos().y < -300.0f + 100.0f)
	{
		Golfball->SetWorldPosY(-300.0f + 100.0f);
		Golfball->ReflectionX();
		Golfball->Update();
	}

	if (Golfball->GetWorldPos().x < -400.0f + 20.0f)
	{
		Golfball->SetWorldPosX(-400.0f + 20.0f);
		Golfball->ReflectionY();
		Golfball->Update();
	}
	else if (Golfball->GetWorldPos().x > 400.0f - 20.0f)
	{
		Golfball->SetWorldPosX(400.0f -20.0f);
		Golfball->ReflectionY();
		Golfball->Update();
	}

	
}

void Main::Render()
{
	for (int i = 0; i < MAPMAX; i++) 
	{
		map[i]->Render();
	}

	Golfball->Render();
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