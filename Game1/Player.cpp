#include "stdafx.h"
#include "Player.h"
#include "Gun_pistol.h"

Player::Player()
{
    this->hand = 1;
    this->speed = 350;
    this->jump_power = 130.f;
    this->jump_startPoint = this->GetWorldPos().y;
    this->jump_status = false;

    hasAxis = true;
    scale.x = 30.f;
    scale.y = 50.f;
    
    score = 0;

    pistol = new Gun_pistol();
    pistol->SetParentRT(*this);

    characterDirection = true;
}

Player::~Player()
{
    delete pistol;
}

void Player::Init(Vector2 spawn, bool isLeft)
{
    SetWorldPosX(spawn.x);
    SetWorldPosY(spawn.y);
    rotation.y = isLeft ? PI : 0.0f;
}

void Player::Control()
{
    // 점프 실행 중..
    if (jump_status && this->GetWorldPos().y < jump_startPoint + this->jump_power)
    {
        // 점프후 낙하
        this->MoveWorldPos(UP * DELTA * 700.f);
        if (this->GetWorldPos().y +5.f >= jump_startPoint + this->jump_power)
            jump_status = false;
    }


    // 이동
    //if (INPUT->KeyPress('W'))
    //    this->MoveWorldPos(UP * DELTA * this->speed);
    //if (INPUT->KeyPress('S'))
    //    this->MoveWorldPos(DOWN * DELTA * this->speed);
    if (INPUT->KeyPress('A'))
        this->MoveWorldPos(LEFT * DELTA * this->speed);
    if (INPUT->KeyPress('D'))
        this->MoveWorldPos(RIGHT * DELTA * this->speed);
    // 점프
    if (INPUT->KeyPress(VK_SPACE) && this->GetWorldPos().y <= FLOOR)
    {
        this->jump_startPoint = this->GetWorldPos().y;
        this->jump_status = true;
    }

    // 격발
    if (INPUT->KeyPress(VK_LBUTTON))
    {
        if (this->hand == 1)
            pistol->Fire(this);
    }

    // 무기 스왑
    if (INPUT->KeyDown('1'))
        this->hand == 1;
}

void Player::Control(Vector2 arrow)
{
    MoveWorldPos(arrow * DELTA * this->speed);
}

void Player::Update()
{
    // 중력
    if (this->GetWorldPos().y > -app.GetHalfHeight() + this->scale.y)
        this->MoveWorldPos(DOWN * DELTA * 250.f);

    // 마우스에 따른 시선처리
    if (INPUT->GetWorldMousePos().x < this->GetWorldPos().x)
        characterDirection = 1;     // LEFT
    else if (INPUT->GetWorldMousePos().x > this->GetWorldPos().x)
        characterDirection = 2;     // RIGHT
    rotation.y = characterDirection == 1 ? PI : 0.0f;

    // 조준선 마우스 방향으로 바라보게
    if (characterDirection == 1)        // LEFT
    {
        Vector2 mouse_point(INPUT->GetWorldMousePos() - this->pistol->GetWorldPos());
        pistol->rotation.z = atan2f(mouse_point.x, mouse_point.y) + PI / 2.f;
    }
    else if (characterDirection == 2)    // RIGHT
    {
        Vector2 mouse_point(INPUT->GetWorldMousePos() - this->pistol->GetWorldPos());
        pistol->rotation.z = atan2f(mouse_point.y, mouse_point.x);
    }

    // 플레이어 UPDATE
    ObRect::Update();
    // 무기와 탄 UPDATE
    this->pistol->Update();
    this->pistol->Update_Bullets();
}

void Player::Render()
{
    // 플레이어 RENDER
    ObRect::Render();
    // 무기와 탄 RENDER
    this->pistol->Render();
    this->pistol->Render_Bullets();
}

