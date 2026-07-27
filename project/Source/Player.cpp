#include "Player.h"
#include "PlayScene.h"
#include "Finish.h"
#include "GameSetting.h"

Player::Player()
{
    for (int i = 0; i < GameSetting::WinCount; i++)
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

    PlayScene* scene = dynamic_cast<PlayScene*>(SceneManager::CurrentScene());

    if (scene == nullptr || !scene->IsTimeUp())
    {
        // 左クリック判定
        if (leftClick)
        {
            for (auto window : windows)
            {
                if (window->IsCircleClicked(mouseX, mouseY))
                {
                    score += 100;//スコア加算
                    window->isDead = true;
                }
            }
        }
    }

    windows.erase(std::remove_if(windows.begin(), windows.end(), [](Window* window)
        {
            if (window->isDead)
            {
                delete window;
                return true;
            }
            return false;
        }),windows.end());

}
void Player::Draw()
{
    for (auto window : windows)
    {
        window->Draw();
    }
}
