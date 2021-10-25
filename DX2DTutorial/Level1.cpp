#include "GameController.h"
#include "Graphics.h"
#include "Level1.h"

void Level1::Load()
{
	y = ySpeed = 0.0f;
}

void Level1::Unload()
{

}

void Level1::Update()
{
	ySpeed += 1.0f;
	y += ySpeed;
	if (y > 590)
	{
		y = 590;
		ySpeed = -30.0f;
	}
}

void Level1::Render(Graphics* gfx)
{
	gfx->ClearScreen(0.94f, 0.94f, 0.94f);
	gfx->DrawCircle(375.0f, y, 10.0f, 0.0f, 0.5f, 0.0f, 1.0f);
}

