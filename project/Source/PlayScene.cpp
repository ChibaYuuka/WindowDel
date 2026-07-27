#include "PlayScene.h"
#include "DxLib.h"
#include "Player.h"
#include "Finish.h"



PlayScene::PlayScene()
{
	SetBackgroundColor(30, 60, 200);
    startTime = GetNowCount();
	Instantiate<Player>();
	Instantiate<Finish>();
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
	DrawFormatStringToHandle(100, 100,GetColor(255, 0, 0),fontHandle,"Time: %d", remain);
	//Finish* finish = FindGameObject<Finish>();
	//if (finish != nullptr && timeUp)
	//{
	//	finish->Draw();
	//}
}