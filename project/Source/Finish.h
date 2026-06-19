#pragma once
#include "../Library/GameObject.h"

class Finish : public GameObject
{
public:
	Finish();
	~Finish();
	void Update() override;
	void Draw() override;
	int score;
private:
	int hImage;
};
