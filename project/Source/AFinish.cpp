#include "Source/Finish.h"
#include "DxLib.h"
#include "Source/PlayScene.h"
#include "Source/Screen.h"
//#include <Font.Dlg>

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
    //Font* font = FindGameObject<Font>();
    DrawExtendGraph(300, 200, 920, 520, hImage, TRUE);
    //	DrawGraph(0, 0, Result, FALSE);

    DrawFormatStringToHandle(100, 120, GetColor(220, 220, 0), "SCORE:%d", score);//スコア表示
    //DrawFormatStringToHandle(300, 710, GetColor(220, 220, 0), font->fontHandle_, "%5d", score->GetScore());
    //リザルト画面表示
    //メモ　ウィンドウの数をプレイ画面で変更できるようにしたい。時間があれば
    //
}
