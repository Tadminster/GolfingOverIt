#include "stdafx.h"
#include "Main.h"

void Main::Init()
{
	coin = new ObImage(L"ruffy.jpg");
	coin->scale = Vector2(500.0f, 500.0f);

	ui = new ObRect;
	ui->scale = Vector2(200.0f, 100.0f);
	ui->SetWorldPos(Vector2(-app.GetHalfWidth(), app.GetHalfHeight()));
	ui->space = SPACE::SCREEN;
}

void Main::Release()
{
	SafeDelete(coin);
	SafeDelete(ui);
}

void Main::Update()
{
	if (INPUT->KeyPress(VK_LEFT))
	{
		CAM->position += LEFT * 200.0f * DELTA;
	}
	if (INPUT->KeyPress(VK_RIGHT))
	{
		CAM->position += RIGHT * 200.0f * DELTA;
	}
	if (INPUT->KeyPress(VK_UP))
	{
		CAM->position += UP * 200.0f * DELTA;
	}
	if (INPUT->KeyPress(VK_DOWN))
	{
		CAM->position += DOWN * 200.0f * DELTA;
	}

	ImGui::SliderFloat("Alpha", &coin->color.w, 0.0f, 1.0f);

	ImGui::Text("FPS : %d", TIMER->GetFramePerSecond());

	if (ImGui::Button("vSync"))
	{
		app.vSync = !app.vSync;
	}

	if (ImGui::Button("reversLR"))
	{
		coin->reverseLR = !coin->reverseLR;
	}

	ImGui::SliderFloat("rotationY", &coin->rotationY, 0.0f, PI);

	coin->Update();
	ui->Update();
}

void Main::LateUpdate()
{
	if (ui->IntersectScreenMouse(INPUT->GetScreenMousePos()))
	{
		ui->color = Color(1, 0, 0, 1);
	}
	else
	{
		ui->color = Color(0, 0, 0, 1);
	}
}

void Main::Render()
{
	coin->Render();
	ui->Render();

}

void Main::ResizeScreen()
{
}

int WINAPI wWinMain(HINSTANCE instance, HINSTANCE prevInstance, LPWSTR param, int command)
{
	app.SetAppName(L"Game2");
	app.SetInstance(instance);
	app.InitWidthHeight(1000.0f, 800.0f);
	WIN->Create();
	Main* main = new Main();
	int wParam = (int)WIN->Run(main);
	SafeDelete(main);
	WIN->Destroy();
	WIN->DeleteSingleton();
	
	return wParam;
}