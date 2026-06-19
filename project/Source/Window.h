#pragma once
#include "../Library/GameObject.h"


class Window : public GameObject {
public:
	Window();
	~Window();
	void Update() override;
	void Draw() override;

	bool IsCircleClicked(int mouseX, int mouseY);
	bool isDead = false;

private:
	int hImage;
	int x, y;		//	表示座標
	int w, h;		//	表示サイズ
	int circleX;
	int circleY;
	int radius = 10;
};
