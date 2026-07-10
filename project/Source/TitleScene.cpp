#include "TitleScene.h"
#include "Screen.h"
#include "GameSetting.h"

TitleScene::TitleScene()
{
	SetBackgroundColor(255, 255, 255);
	hImage = LoadGraph("Data/ウィンドウ消し.png");
	fontHandle = CreateFontToHandle("しんばしゴチック", 25, 2, DX_FONTTYPE_EDGE);
}

TitleScene::~TitleScene()
{
	DeleteGraph(hImage);
	DeleteFontToHandle(fontHandle);
}

void TitleScene::Update()
{
	if (CheckHitKey(KEY_INPUT_P)) {
		SceneManager::ChangeScene("PLAY");
	}
	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
		SceneManager::Exit();
	}
	if (CheckHitKey(KEY_INPUT_RIGHT) && !prevRight) {
			GameSetting::WinCount++;
	}
	if (CheckHitKey(KEY_INPUT_LEFT) && !prevLeft) {
		if (GameSetting::WinCount > 1) {
			GameSetting::WinCount--;
		}
	}
	prevRight = CheckHitKey(KEY_INPUT_RIGHT);
	prevLeft = CheckHitKey(KEY_INPUT_LEFT);
}


void TitleScene::Draw()
{
	DrawExtendGraph(Screen::WIDTH / 2 - 300, Screen::HEIGHT / 2 - 100, Screen::WIDTH / 2 + 300, Screen::HEIGHT / 2 + 100, hImage, true);
	extern const char* Version();
	DrawString(0, 20, Version(), GetColor(255,255,255));
	DrawFormatStringToHandle(100, 100, GetColor(50, 30, 200),fontHandle, "WINDOW:%d", GameSetting::WinCount);
	DrawFormatStringToHandle(100, 130, GetColor(50, 30, 200), fontHandle, "左右キーでウィンドウ数変更");
	//DrawString(0, 0, "TITLE SCENE", GetColor(255,255,255));
	//DrawFormatString(100, 100, GetColor(255,255,255), "%4.1f", 1.0f / Time::DeltaTime());
	//DrawString(100, 400, "Push [P]Key To Play", GetColor(255, 255, 255));
}
