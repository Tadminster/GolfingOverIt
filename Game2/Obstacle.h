#pragma once
class Obstacle : public ObCircle
{
private:
	Vector2		fireDir;

public:
	Obstacle();
	virtual ~Obstacle();
	void Update() override;
	void Render() override;
	void fire(Vector2 dir);
};

