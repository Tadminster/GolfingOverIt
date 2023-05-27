#include "stdafx.h"
#include "Ball.h"

Ball::Ball()
{
	scale.x = 20.0f;
	scale.y = 20.0f;
    fireDir = Vector2(0, 0);
    pressPower = 1.0f;
    hasAxis = true;
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
    if(dir.Length()*5 >500.0f) pressPower = 500.0f;  
    else  pressPower = dir.Length()*5 ;
    dir.Normalize();
    fireDir =dir;
}

bool Ball::stopcheck()
{

    if (velocity.Length() < 0.5f)  return isStop = true;
    else return isStop = false;
}


