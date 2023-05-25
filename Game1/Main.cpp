#include "stdafx.h"
#include "Player.h"
#include "Ball.h"
#include "Gun_pistol.h"
#include "Ob_floor.h"
#include "Ob_movable.h"
#include "Ob_drag.h"
#include "Main.h"

Main::Main()
{
    // 배경
    for (int i = 0; i < number_star; i++)
    {
        bg_star[i] = new ObStar();
        bg_star[i]->SetWorldPos(Vector2(RANDOM->Int(-3000, 3000), RANDOM->Int(0, 2000)));
        bg_star[i]->scale = Vector2(RANDOM->Int(5, 30));
        bg_star[i]->color = Color(RANDOM->Float(), RANDOM->Float(), RANDOM->Float()) * RANDOM->Float();
    }
    floor = new Ob_floor();

    ball = new Ball();
    // 사물
    //rect_movable = new Ob_movable();
    //rect_drag = new Ob_drag();

    // 플레이어
	//player = new Player();

    // 총기류
    //pistol = new Gun_pistol();
    //pistol->SetParentRT(*player);

    //for (auto& goalpost : goalpost)
    //goalpost = new Player();

//ball = new Ball();
}

Main::~Main()
{
    //for (int i = 0; i < 2; i++)
        //delete player[i];

    //for (int i = 0; i < 2; i++)
        //delete goalpost[i];

    //delete ball;
    //delete player;
    //delete pistol;

    //delete rect_movable;
    delete floor;
}

void Main::Init()
{
	//player->Init(Vector2(-app.GetHalfWidth() + player->scale.x, -app.GetHalfHeight() + player->scale.y), false);
 //   goalpost[0]->Init(Vector2(-app.GetHalfWidth(), 0), false);
 //   goalpost[1]->Init(Vector2(app.GetHalfWidth(), 0), true);
 //   for (auto& goalpost : goalpost)
 //   {
 //       goalpost->hasAxis = false;
 //       goalpost->scale = Vector2(100.f, 100.f);
 //   }

	//ball->Init(Vector2(0, 0), true);
 //   ball->speed = 0;

}

void Main::Release()
{
   
}

void Main::Update()
{
    //ImGui::Text("ON_MOUSE: %d\n", rect_movable->OnMouse());


    ImGui::Text("CAMERA_X: %f\n", CAM->position.x);
    ImGui::Text("CAMERA_Y: %f\n", CAM->position.y); 
    //ImGui::Text("CAM_SPEED: %f\n", std::abs(player->GetWorldPos().x - CAM->position.x));

    ImGui::Text("\n\n");
    //ImGui::Text("PLAYER_X: %f\n", player->GetWorldPos().x);
    //ImGui::Text("PLAYER_Y: %f\n", player->GetWorldPos().y);

    ImGui::Text("\n\n");
    ImGui::Text("Keys\n");
    ImGui::Text("move: [A][S] \n");
    ImGui::Text("jump: [SPACE] \n");
    ImGui::Text("fire: [LBUTTON] \n");

    // 배경 업데이트
    for (int i = 0; i < number_star; i++)
        bg_star[i]->Update();

    floor->Collision(ball);

    ball->Update();
    floor->Update();

    // 사물 업데이트
    //rect_movable->Update();
    //rect_movable->Control();
    //rect_movable->SetColor();

    //rect_drag->Update();
    //rect_drag->OnClick();
    // 플레이어 업데이트
    //player->Update();   
    //player->Control();
    
    // 무기 업데이트
    //pistol->Update();

    // 카메라 업데이트
    /*if (player->GetWorldPos().x != CAM->position.x
        && CAM->position.x >= -2500
        && CAM->position.x <= 2500)
    {
        float DISTANCE_DIFFERENCE = std::abs(player->GetWorldPos().x - CAM->position.x);
        if (player->GetWorldPos().x < CAM->position.x)
            CAM->position += LEFT * (30.f + DISTANCE_DIFFERENCE) * DELTA;
        else if (player->GetWorldPos().x > CAM->position.x)
            CAM->position += RIGHT * (30.f + DISTANCE_DIFFERENCE) * DELTA;
    }
    else if (CAM->position.x < -2500)
        CAM->position.x = -2500;
    else if (CAM->position.x > 2500)
        CAM->position.x = 2500;*/
}

void Main::LateUpdate()
{
    //// 볼이 맵 밖을 벗어날 때 충돌처리
    //int map_side{ 10 }; //
    //// x축
    //if (ball->GetWorldPos().x < -app.GetHalfWidth() + map_side)
    //{
    //    ball->SetWorldPosX(-app.GetHalfWidth() + map_side);
    //    ball->reflection_y();
    //    // ball->rotation.z = atan2f(ball->get_right().y, -ball->get_right().x);
    //}
    //else if (ball->GetWorldPos().x > app.GetHalfWidth() - map_side)
    //{
    //    ball->SetWorldPosX(app.GetHalfWidth() - map_side);
    //    ball->reflection_y();
    //    // ball->rotation.z = atan2f(ball->get_right().y, -ball->get_right().x);
    //}
    //// y축
    //if (ball->GetWorldPos().y < -app.GetHalfHeight() + map_side)
    //{
    //    ball->SetWorldPosY(-app.GetHalfHeight() + map_side);
    //    ball->reflection_x();
    //    // ball->rotation.z = atan2f(-ball->get_right().y, ball->get_right().x);
    //}
    //else if (ball->GetWorldPos().y > app.GetHalfHeight() - map_side)
    //{
    //    ball->SetWorldPosY(app.GetHalfHeight() - map_side);
    //    ball->reflection_x();
    //    // ball->rotation.z = atan2f(-ball->get_right().y, ball->get_right().x);
    //}
}

void Main::Render()
{
    for (int i = 0; i < number_star; i++)
        bg_star[i]->Render();
    floor->Render();

    ball->Render();
    /*rect_movable->Render();
    rect_drag->Render();

	player->Render();*/

	//for (auto& player : player)
	//	player->Render();

 //   for (auto& goalpost : goalpost)
 //       goalpost->Render();

	//ball->Render();

}

void Main::ResizeScreen()
{
}

int WINAPI wWinMain(HINSTANCE instance, HINSTANCE prevInstance, LPWSTR param, int command)
{
    app.SetAppName(L"Game1");
    app.SetInstance(instance);
	app.InitWidthHeight(800.0f,600.0f);
    app.background = Color(0.1f, 0.1f, 0.1f);
	WIN->Create();
	Main* main = new Main();
	int wParam = (int)WIN->Run(main);
	SafeDelete(main);
	WIN->Destroy();
	WIN->DeleteSingleton();
	
	return wParam;
}