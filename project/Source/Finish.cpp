#include "Finish.h"
#include "DxLib.h"
#include "PlayScene.h"
#include "Screen.h"
#include "Player.h"

Finish::Finish()
{
    hImage = LoadGraph("Data/Finish.png");
    fontHandle = CreateFontToHandle("しんばしゴチック", 25, 2, DX_FONTTYPE_EDGE);
}

Finish::~Finish()
{
    DeleteGraph(hImage);
    DeleteFontToHandle(fontHandle);
}

void Finish::Update()
{
}

void Finish::Draw()
{
    PlayScene* scene = dynamic_cast<PlayScene*>(SceneManager::CurrentScene());
    if (scene == nullptr || !scene->IsTimeUp())
    {
        return;   // タイムアップ前は描画しない
    } 
    Player* player = FindGameObject<Player>();
    DrawFormatStringToHandle(200, 130, GetColor(220, 220, 0), fontHandle, "SCORE:%d", player->GetScore());//スコア表示
    DrawExtendGraph(300, 200, 920, 520, hImage, TRUE);
}
