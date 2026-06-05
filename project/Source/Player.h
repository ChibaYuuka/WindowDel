#pragma once
#include "../Library/GameObject.h"
#include <vector>
#include "Window.h"

class Player : public GameObject {
public:
	Player();
	~Player();
	void Update() override;
	void Draw() override;

	int mouseX, mouseY; // マウス座標用変数
	int circleX = 100;
	int circleY = 100;
	int radius = 50;
	bool isHit = false;
	int prevMouseInput = 0;
	std::vector<Window*> windows;
private:

};
