#include "stdafx.h"
#include "Gun_pistol.h"
#include "Bullet_proto.h"
#include "Player.h"

Gun_pistol::Gun_pistol() 
    : name("권총"), damage(15), ammo_max(9999), ammo_current(9999), ammo_speed(400.f),
    fire_rate(4.f), range(800.f) 
{
    this->SetLocalPosX(15.f);
    this->SetLocalPosY(5.f);
    this->scale.x = 25.f;
    this->scale.y = 6.f;
    
    line_sight = new ObLine();
    this->hasLineSight = true;
}

Gun_pistol::~Gun_pistol()
{
    delete line_sight;
}

void Gun_pistol::Update()
{
    ObRect::Update();
}

void Gun_pistol::Render()
{
    if (hasLineSight)
    {
        //right
        line_sight->SetWorldPos(GetWorldPos());
        line_sight->rotation.z = Utility::DirToRadian(GetRight());
        line_sight->scale.x = scale.x * 20.0f;
        line_sight->color = Color(1.0f, 1.0f, 0.0f, 1.0f);
        line_sight->Update();
        line_sight->Render();
    }

    ObRect::Render();
}

bool Gun_pistol::Fire(class Player* shooter)
{

    float currentTime = TIMER->GetWorldTime();
    float elapsedTime = currentTime - lastShotTime;

    if (this->ammo_current > 0 && elapsedTime >= this->timeSinceLastTime)
    {
        // 총구 위치 계산
        Vector2 muzzle = Vector2(this->GetWorldPos() + this->GetRight() * scale.x);
        // 탄각 계산(플레이어가 바라보는 방향)
        // float rotation_z{ atan2f(shooter->get_right().y, shooter->get_right().x) };

        // 탄생성
        const Bullet_proto bullet
        (
            muzzle,
            this->GetRight(),
            this->ammo_speed,
            this->range
        );
        //벡터에 탄 push
        bullets.push_back(bullet);
        //탄 수량 감소
        this->ammo_current = max(this->ammo_current - 1, 0);

        // 공속계산
        this->lastShotTime = currentTime;
        this->timeSinceLastTime = 1.0f / this->fire_rate;
    }

	return false;
}

void Gun_pistol::Update_Bullets()
{
    for (auto& ammo : this->bullets)
    {
        // 탄의 위치 이동
        // ammo.pos += Vector2(cosf(ammo.rotation.z), sinf(ammo.rotation.z)) * (ammo.speed);
        // ammo.pos += Vector2(0, ammo.gravity_sin);
        // ammo.gravity_sin += ammo.gravity_cos * DELTA;

        //ammo.gravityForce += 0.0f * DELTA;

        //Vector2 velocity = ( 
        //    ammo.shooting_Dir * ammo.pressPower
        //    + ammo.gravityDir * ammo.gravityForce);
        //ammo.MoveWorldPos(velocity * DELTA);

        // 탄이 맵 밖을 벗어났으면
        //int map_side{ 10 };
        //// x축
        //if (ammo.GetLocalPos().x < 0 + map_side)
        //{
        //    ammo.SetWorldPosX(0 + map_side);
        //    ammo.reflection_y();
        //    // ammo.rotation.z = atan2f(ammo.get_right().y, -ammo.get_right().x);
        //}
        //else if (ammo.GetLocalPos().x > 800 - map_side)
        //{
        //    ammo.SetWorldPosX(800 - map_side);
        //    ammo.reflection_y();
        //    // ammo.rotation.z = atan2f(ammo.get_right().y, -ammo.get_right().x);
        //}
        //// y축
        //if (ammo.GetLocalPos().y < 0 + map_side)
        //{
        //    ammo.SetWorldPosY(0 + map_side);
        //    ammo.reflection_x();
        //    // ammo.rotation.z = atan2f(-ammo.get_right().y, ammo.get_right().x);
        //}
        //else if (ammo.GetLocalPos().y > 800 - map_side)
        //{
        //    ammo.SetWorldPosY(800 - map_side - 5);
        //    ammo.reflection_x();
        //    // ammo.rotation.z = atan2f(-ammo.get_right().y, ammo.get_right().x);
        //}

        // 탄의 정보 업데이트
        ammo.Update();

        // 탄의 체력이 0이면 삭제
        // if (ammo.Hp == 0) ammo.traveledDistance = range;
    }


    // 탄이 사거리를 벗어났으면
    bullets.erase(
        std::remove_if
        (
            bullets.begin(),
            bullets.end(),
            [](const Bullet_proto& b) { return b.hasTraveledTooFar(); }
        ),
        bullets.end()
    );
}

void Gun_pistol::Render_Bullets()
{
    for (auto& ammo : this->bullets)
        ammo.Render();
}
