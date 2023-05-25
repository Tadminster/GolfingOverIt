#include "stdafx.h"
#include "Ball.h"


Ball::Ball()
{
    this->hasAxis = false;
    this->scale.x = 20.0f;
    this->scale.y = 20.0f;

    this->gravityDiretion = DOWN;
    this->gravityForce = 100.f;
    this->gravityWeight = 10.f;

    this->status_stop = false;
}

Ball::~Ball()
{
}

void Ball::Init(Vector2 spawn, bool isLeft)
{
    SetWorldPos(spawn);
    rotation.y = isLeft ? PI : 0.0f;
}

void Ball::Control()
{
    this->GetWorldPos();
}

void Ball::Update()
{
    this->checkStop();
    this->gravityForce += gravityWeight;

    Vector2 velocity = (this->direction * this->pressPower + this->gravityDiretion * this->gravityForce);
    // 이동
    this->MoveWorldPos(velocity * DELTA);
    ObCircle::Update();
}

//bool Ball::hasIntersect(GameObject* target)
//{
//    Vector2 temp_vector
//    (
//        target->GetWorldPos().x - this->GetWorldPos().x, 
//        target->GetWorldPos().y - this->GetWorldPos().y
//    );
//
//    float distance = sqrt(pow((temp_vector.x), 2) + pow((temp_vector.y), 2));
//    float radius_sum = target->scale.x / 2 + this->scale.x / 2;
//    float radius_diff = abs(target->scale.x - this->scale.x);
//
//    if (distance <= radius_sum)
//        return true;
//    
//    return false;
//}
//
//bool Ball::collision(GameObject* target)
//{
//    // 공이 대상과 충돌했으면 이동
//    if (this->hasIntersect(target))
//    {
//        // 이동 함수
//        this->direction = (this->GetWorldPos() - target->GetWorldPos());
//        //this->speed = 50.f;
// 
//        return true;
//    }
//
//    return false;
//}

void Ball::reflection_x()
{
    this->direction.y = -this->direction.y;
    this->gravityForce = -this->gravityForce;
}


void Ball::reflection_y()
{
    this->direction.x = -this->direction.x;
    this->gravityForce = -this->gravityForce;
}

void Ball::checkStop()
{
    static Vector2 beforePos;

    if (beforePos.x == this->GetWorldPos().x &&
        beforePos.y == this->GetWorldPos().y)
    {
        this->color = Color(0.f, 1.f, 0.f, 1.f);
        this->status_stop = true;
    }
    else
    {
        beforePos = this->GetWorldPos();
        this->color = Color(1.f, 0.f, 0.f, 1.f);
        this->status_stop = false;
    }
}