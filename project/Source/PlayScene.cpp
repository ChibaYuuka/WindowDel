#include "PlayScene.h"
#include "DxLib.h"
//#include <math.h>
#include "Player.h"
#include "Finish.h"



PlayScene::PlayScene()
{
	SetBackgroundColor(30, 60, 200);
    startTime = GetNowCount();
	Instantiate<Player>();
	//Instantiate<Window>();
	fontHandle = CreateFontToHandle("‚µ‚ñ‚Î‚µƒSƒ`ƒbƒN", 25, 2, DX_FONTTYPE_EDGE);
}

PlayScene::~PlayScene()
{
	DeleteFontToHandle(fontHandle);
}

void PlayScene::Update()
{
	int timer = GetNowCount() - startTime;
	remain = limit - timer / 1000; // •b‚É‚·‚é‚È‚ç1000

	if (remain <= 0)
	{
		remain = 0;
		timeUp = true;
	}

    if (CheckHitKey(KEY_INPUT_T)) {
        SceneManager::ChangeScene("TITLE");
    }
    if (CheckHitKey(KEY_INPUT_ESCAPE)) {
        SceneManager::Exit();
    }
}
bool PlayScene::IsTimeUp()
{
	return timeUp;
}

void PlayScene::Draw()
{
	//DrawString(0, 0, "PLAY SCENE", GetColor(255, 255, 255));
	//DrawString(100, 400, "Push [T]Key To Title", GetColor(255, 255, 255));
	DrawFormatStringToHandle(100, 100,GetColor(255, 0, 0),fontHandle,"Time: %d", remain);
	Finish finish;
	if (timeUp) { finish.Draw(); }
}