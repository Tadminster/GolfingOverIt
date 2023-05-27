#pragma once
class Obstacle : public ObCircle
{
private:
	Vector2		fireDir;
	bool isMove;

public:
	float flbpower;
	Obstacle();
	virtual ~Obstacle();
	void Update() override;
	void Render() override;

	void ReflectionY()
	{
		//fireDir.x = -fireDir.x; 
		Vector2 dir =
			Vector2(cosf(rotation.z), sinf(rotation.z));
		rotation.z = atan2f(dir.y, -dir.x);
	}
};

