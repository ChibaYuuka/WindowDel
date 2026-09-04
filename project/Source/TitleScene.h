#pragma once
#include "../Library/SceneBase.h"

class TitleScene : public SceneBase
{
public:
	TitleScene();
	~TitleScene();
	void Update() override;
	void Draw() override;
private:
	int hImage;
	int fontHandle;
	bool prevRight = false;
	bool prevLeft = false;
};
