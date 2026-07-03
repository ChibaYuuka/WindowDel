#include "TitleScene.h"
#include "Screen.h"

TitleScene::TitleScene()
{
	SetBackgroundColor(255, 255, 255);
	hImage = LoadGraph("Data/ウィンドウ消し.png");
}

TitleScene::~TitleScene()
{
	DeleteGraph(hImage);
}

void TitleScene::Update()
{
	if (CheckHitKey(KEY_INPUT_P)) {
		SceneManager::ChangeScene("PLAY");
	}
	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
		SceneManager::Exit();
	}
}


void TitleScene::Draw()
{
	DrawExtendGraph(Screen::WIDTH / 2 - 300, Screen::HEIGHT / 2 - 100, Screen::WIDTH / 2 + 300, Screen::HEIGHT / 2 + 100, hImage, true);
	extern const char* Version();
	DrawString(0, 20, Version(), GetColor(255,255,255));
	//DrawString(0, 0, "TITLE SCENE", GetColor(255,255,255));
	//DrawFormatString(100, 100, GetColor(255,255,255), "%4.1f", 1.0f / Time::DeltaTime());
	//DrawString(100, 400, "Push [P]Key To Play", GetColor(255, 255, 255));
}
