#pragma once
class Ob_movable : public ObRect
{
public:
	Ob_movable();

	int		OnMouse();
	void	Control();
	void	SetColor();
};

