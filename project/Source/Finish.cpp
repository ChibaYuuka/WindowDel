#include "Finish.h"
#include "DxLib.h"
#include "PlayScene.h"
#include "Screen.h"
#include "Player.h"

Finish::Finish()
{
    hImage = LoadGraph("Data/Finish.png");
}

Finish::~Finish()
{
    DeleteGraph(hImage);
}

void Finish::Update()
{

}

void Finish::Draw()
{
    Player* player = FindGameObject<Player>();
    DrawFormatString(100, 120, GetColor(220, 220, 0), "SCORE:%d", player->GetScore());
    
    DrawExtendGraph(300, 200, 920, 520, hImage, TRUE);
    //	DrawGraph(0, 0, Result, FALSE);
    //  DrawFormatStringToHandle(100, 120, GetColor(220, 220, 0), hImage,"SCORE:%d",score);//スコア表示

    //リザルト画面表示
    //メモ　ウィンドウの数をプレイ画面で変更できるようにしたい。時間があれば
    //
}
