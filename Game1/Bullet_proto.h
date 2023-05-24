#pragma once

class Bullet_proto : public ObRect
{
protected:

public:
    int             Hp;                     // 체력
    Vector2         shooting_Dir;           // 방향
    float           speed;                  // 속도
    int             Damage;                 // 공격력
    float           range;                  // 사정거리
    float           traveledDistance;       // 이동거리
    float           pressPower;             // 차지

    Vector2         gravityDir;             // 중력 방향
    float           gravityForce;           // 중력 힘
    float           gravityWeight;          // 중력 가중치

public:
    Bullet_proto(Vector2 pos, Vector2 direction, float speed, float range);

    void Update() override;

    /* 탄이 이동한 거리가 range를 넘었는지 확인 */
    bool hasTraveledTooFar() const { return traveledDistance >= range; }
    bool hasIntersect(class GameObject* target);

    void reflection_y();
    void reflection_x();
};

