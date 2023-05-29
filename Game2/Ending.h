#pragma once
class Ending
{
public:
	class ObRect* bonoBono;
	ObImage* bonoBono_skin;
	ObImage* bonoBono_script;

	float creationTime;
	float duration;

	bool stage[5];

public:
	Ending();
	~Ending();
	void Init();
	void Update(Ball* ball);
	void LateUpdate();
	void Render();
};