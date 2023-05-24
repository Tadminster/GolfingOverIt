#include "stdafx.h"
#include "Bullet_proto.h"

Bullet_proto::Bullet_proto(Vector2 pos, Vector2 direction, float speed, float range)
    : speed(speed), range(range), traveledDistance(0.f), Damage(5), 
     Hp(1), pressPower(500.f)
{
    // 탄의 생성위치
    this->SetWorldPos(pos);

    // 탄의 크기
    this->scale.x = 5.f;
    this->scale.y = 5.f;

    // 탄의 각도
    this->shooting_Dir = direction;

    // 중력
    this->gravityDir = DOWN;
    this->gravityForce = 0.0f;

    this->pivot = OFFSET_L;
    this->hasAxis = false;
}

void Bullet_proto::Update()
{
    this->gravityForce += 0.0f * DELTA;

    // V1_발사파워, 중력적용
    //Vector2 velocity = ( 
    //this->shooting_Dir * this->pressPower + this->gravityDir * this->gravityForce);

    // V2_탄속만 적용
    Vector2 velocity = (this->shooting_Dir * this->speed);

    this->MoveWorldPos(velocity * DELTA);

    ObRect::Update();

    // 탄이 이동한 거리 계산
    traveledDistance += std::sqrt(std::pow(speed * DELTA, 2) + std::pow(speed * DELTA, 2));
}

bool Bullet_proto::hasIntersect(class GameObject* target)
{
    
    
    Vector2 temp_vector
    (
        target->GetWorldPos().x - this->GetWorldPos().x, 
        target->GetWorldPos().y - this->GetWorldPos().y
    );
    float distance = sqrt(pow((temp_vector.x), 2) + pow((temp_vector.y), 2));
    float radius_sum = target->scale.x + this->scale.x;
    float radius_diff = abs(target->scale.x - this->scale.x);
    if (distance <= radius_sum)
    {
        return true;
    }
    return false;
}

void Bullet_proto::reflection_y()
{
    shooting_Dir.x = -shooting_Dir.x;

    /*Vector2 dir =
        Vector2(cosf(rotation.z), sinf(rotation.z));
    rotation.z = atan2f(dir.y, -dir.x);*/

    pressPower *= 0.7f;
    gravityForce *= 0.7f;
}

void Bullet_proto::reflection_x()
{
    shooting_Dir.y = -shooting_Dir.y;
    gravityForce = -gravityForce;

    //Vector2 dir =
    //	Vector2(cosf(rotation.z), sinf(rotation.z));
    //rotation.z = atan2f(-dir.y, dir.x);

    pressPower *= 0.7f;
    gravityForce *= 0.7f;
}
