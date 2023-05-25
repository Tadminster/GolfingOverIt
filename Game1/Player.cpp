#include "stdafx.h"
#include "Bullet.h"
#include "Player.h"

Player::Player()
{
  
    hasAxis = true;

    gauge = new ObRect();
    gauge->SetParentT(*this);
    gauge->pivot = OFFSET_L;
    


    gauge2 = new ObRect();
    gauge2->SetParentT(*this);
    gauge2->pivot = OFFSET_L;
    
    gauge2->scale.x = 100.0f;
    //
    for (int i = 0; i < 30; i++)
    {
        bullet[i] = new Bullet();
    }

    scale.x = 600.0f * 0.1f;
    scale.y = 600.0f * 0.1f;

    gauge->scale.y = 30.0f;
    gauge2->scale.y = 30.0f;
   

    //cc->
    //cc->
}

Player::~Player()
{
}

void Player::Init(Vector2 spawn, bool isLeft)
{
    SetWorldPosX(spawn.x);
    SetWorldPosY(spawn.y);

    gauge2->SetLocalPosY(100.0f);
    gauge->SetLocalPosY(50.0f);

    rotation.y = isLeft ? PI : 0.0f;


}

void Player::Control()
{

    rotation.z = Utility::DirToRadian(INPUT->GetWorldMousePos() - GetWorldPos());

    //계속 누를때
    if (INPUT->KeyPress('W'))
    {
        //벡터의 크기는 초당 50
        MoveWorldPos(UP * DELTA * 200);
        //rotation.z += DELTA;
    }
    if (INPUT->KeyPress('S'))
    {
        MoveWorldPos(DOWN * DELTA * 200);
       // rotation.z -= DELTA;
    }
    if (INPUT->KeyPress('A'))
    {
        MoveWorldPos(LEFT * DELTA * 200);
    }
    if (INPUT->KeyPress('D'))
    {
        MoveWorldPos(RIGHT * DELTA * 200);
    }
    if (INPUT->KeyDown(VK_SPACE))
    {
        pressPower = 200.0f;
    }
    if (INPUT->KeyPress(VK_SPACE))
    {
        pressPower += 300.0f * DELTA;
        pressPower = min(pressPower, 1000.0f);
    }
    if (INPUT->KeyUp(VK_SPACE))
    {
        for (int i = 0; i < 30; i++)
        {
            if (not bullet[i]->GetIsFire())
            {
                bullet[i]->Fire(this, pressPower);
                break;
            }
        }
    }
    gauge->scale.x = pressPower * 0.1f;
}

void Player::Update()
{


    ObCircle::Update();
    for (int i = 0; i < 30; i++)
    {
        bullet[i]->Update();
    }
    gauge->Update();
    gauge2->Update();
  
}

void Player::Render()
{
    ObCircle::Render();
    gauge->Render();
    gauge2->Render();
    for (int i = 0; i < 30; i++)
    {
        bullet[i]->Render();
    }
}
