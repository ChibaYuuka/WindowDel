#pragma once
#include "../Library/SceneBase.h"

/// <summary>
/// ゲームプレイのシーンを制御する
/// </summary>
class PlayScene : public SceneBase
{
public:
	PlayScene();
	~PlayScene();
	void Update() override;
	void Draw() override;
	bool IsTimeUp();
private:
	int startTime = 0;
	int limit = 15;//15
	int remain = 15;//
	bool timeUp = false;
};
