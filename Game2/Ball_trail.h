#pragma once
class Ball_trail : public ObRect
{
public:
	float creationTime;
	float duration;

public:
	Ball_trail(Vector2 ballPos);
	bool timeOut() { return TIMER->GetWorldTime() >= creationTime + duration; }
};

