#pragma once
class Title
{
public:
	ObImage* title_bg;

	ObRect* btn_start;
	ObRect* btn_exit;
	ObImage* skin_start;
	ObImage* skin_exit;

public:
	Title();
	~Title();
	void Init();
	void Update();
	void LateUpdate();
	void Render();

	/* return 0 = 종료, 1 = 시작 */
	int onClick();
};

