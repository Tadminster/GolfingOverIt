#pragma once
class Ball : public ObCircle
{
private:
	Vector2		fireDir;
	float		pressPower;
	Vector2		velocity;
	float		gravityForce;
	Vector2		gravityDir = DOWN;
	

	bool isStop;

public:
	Ball();
	virtual ~Ball();
	void Update() override;
	void Render() override;

	void fire(Vector2 dir);

	bool stopcheck( ) ;
	void SetgravityForve(float GF) { gravityForce = GF; };


	void ReflectionY()
	{
		fireDir.x = -fireDir.x;
		
		pressPower *= 0.5f;
		gravityForce *= 0.5f;
	}
	void ReflectionX()
	{
		fireDir.y = -fireDir.y;
		gravityForce = -gravityForce;
		
		pressPower *= 0.5f;
		gravityForce *= 0.5f;
	}
};

