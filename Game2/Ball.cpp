#include "stdafx.h"
#include "Ball.h"

Ball::Ball()
{
	scale.x = 20.0f;
	scale.y = 20.0f;
    fireDir = Vector2(0, 0);
    pressPower = 1.0f;
    hasAxis = false;
}

Ball::~Ball()
{
}

void Ball::Update()
{
    
    gravityForce += 500.0f * DELTA;

     velocity = (fireDir * pressPower
        + gravityDir * gravityForce);
    MoveWorldPos(velocity * DELTA);

    rotation.z = atan2f(velocity.y, velocity.x);

    

    ObCircle::Update();
}

void Ball::Render()
{
    ObCircle::Render();
}



void Ball::fire(Vector2 dir)
{ 
    pressPower = min(dir.Length() * 2.0f, 550.f);
    dir.Normalize();
    fireDir =dir;
}

bool Ball::stopcheck()
{

    if (pressPower <= 0.1f)  return isStop = true;
    else return isStop = false;
}

void Ball::Reflection(Vector2 dis)
{
   // if(!isStop) cout << "충돌" << endl;
    Vector2 golddis = this->GetRight();
        fireDir = golddis + (2 * dis * dotProduct(-golddis, dis));
    pressPower *= 0.5f;
    gravityForce *= 0.5f;   
}


