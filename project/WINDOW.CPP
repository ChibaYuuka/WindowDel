#include "Source/Window.h"
//#include "Source/Player.h"
#include <assert.h>
//#define _USE_MATH_DEFINES
//#include <math.h>
Window::Window()
{
	hImage = LoadGraph("data/WindowLine.png");
	assert(hImage > 0);
	x = GetRand(700);
	y = GetRand(470);
	w = 600;
	h = 350;
	circleX = x + w - 15;
	circleY = y + 13;
}

Window::~Window()
{
	DeleteGraph(hImage);
}

void Window::Update()
{

}

void Window::Draw()
{

	DrawExtendGraph(x, y, x + w, y + h, hImage, true);
	DrawCircle(circleX, circleY, radius, GetColor(255, 0, 0), TRUE);
}

bool Window::IsCircleClicked(int mouseX, int mouseY)
{
	int dx = mouseX - circleX;
	int dy = mouseY - circleY;

	return dx * dx + dy * dy <= radius * radius;
}
