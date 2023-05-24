#include "stdafx.h"
#include "Ball.h"


Ball::Ball()
{
    hasAxis = false;
    scale.x = 20.0f;
    scale.y = 20.0f;
}

Ball::~Ball()
{
}

void Ball::Init(Vector2 spawn, bool isLeft)
{
    SetWorldPosX(spawn.x);
    SetWorldPosY(spawn.y);
    rotation.y = isLeft ? PI : 0.0f;
}

void Ball::Control()
{
    this->GetWorldPos();
}

void Ball::Update()
{
    this->MoveWorldPos(this->direction * this->speed * DELTA);
    this->speed *= 0.997f;
    ObCircle::Update();
}

void Ball::Render()
{
    ObCircle::Render();
}

bool Ball::hasIntersect(GameObject* target)
{
    Vector2 temp_vector
    (
        target->GetWorldPos().x - this->GetWorldPos().x, 
        target->GetWorldPos().y - this->GetWorldPos().y
    );

    float distance = sqrt(pow((temp_vector.x), 2) + pow((temp_vector.y), 2));
    float radius_sum = target->scale.x / 2 + this->scale.x / 2;
    float radius_diff = abs(target->scale.x - this->scale.x);

    if (distance <= radius_sum)
        return true;
    
    return false;
}

bool Ball::collision(GameObject* target)
{
    // 공이 대상과 충돌했으면 이동
    if (this->hasIntersect(target))
    {
        // 이동 함수
        this->direction = (this->GetWorldPos() - target->GetWorldPos());
        this->speed = 50.f;
 
        return true;
    }

    return false;
}