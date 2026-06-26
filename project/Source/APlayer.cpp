#include "Source/Player.h"
//#include "Source/Window.h"
//#include <assert.h>
//#include <algorithm>
#include "Source/PlayScene.h"
#include "D:\金3限\ウィンドウ\ウィンドウ消し\project\Source\Finish.h"

Player::Player()
{
    for (int i = 0; i < 15; i++)
    {
        windows.push_back(new Window());
    }
}

Player::~Player()
{
    for (auto window : windows)
    {
        delete window;
    }
}

void Player::Update()
{
    GetMousePoint(&mouseX, &mouseY);//マウス座標
    int mouseInput = GetMouseInput();
    bool leftClick = (mouseInput & MOUSE_INPUT_LEFT) && !(prevMouseInput & MOUSE_INPUT_LEFT);
    prevMouseInput = mouseInput;
    isHit = false;

    PlayScene* scene = dynamic_cast<PlayScene*>(SceneManager::CurrentScene());

    if (scene && scene->IsTimeUp())
    {
        //フォントサイズ変える
        DrawString(0, 0, "Game Over", GetColor(255, 0, 0));
        return;
    }

    // 左クリック判定
    if (leftClick)
    {

        //    // 円の中心からの距離を計算
        //    int dx = mouseX - circleX;
        //    int dy = mouseY - circleY;

        //    // 半径内か判定
        //    if (dx * dx + dy * dy <= radius * radius)
        //    {
        //        isHit = true;
        //    }
        //}
        //prevMouseInput = mouseInput;

        for (auto window : windows)
        {
            if (window->IsCircleClicked(mouseX, mouseY))
            {
                //score = +100;
                window->isDead = true;
                //isHit = true;
            }
            /*  window->Update();*/
        }
    }

    windows.erase(
        std::remove_if(
            windows.begin(),
            windows.end(),
            [](Window* window)
            {
                if (window->isDead)
                {
                    delete window;
                    return true;
                }

                return false;
            }),
        windows.end());

}
void Player::Draw()
{
    //DrawCircle(circleX, circleY, radius, GetColor(255, 255, 255), FALSE);

    //if (isHit)//デバック用
    //{
    //    DrawString(10, 10, "円の中！", GetColor(255, 0, 0));
    //    //DrawFormatString(10, 40, GetColor(255, 255, 255), "Mouse : %d %d", mouseX, mouseY);
    //}

    for (auto window : windows)
    {
        window->Draw();
    }
}
