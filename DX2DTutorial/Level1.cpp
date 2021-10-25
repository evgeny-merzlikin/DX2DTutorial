#include "GameController.h"
#include "Graphics.h"
#include "Level1.h"

void Level1::Load()
{
	y = ySpeed = 0.0f;
	sprites = new SpriteSheet(L"image1.png", gfx);
}

void Level1::Unload()
{
	delete sprites;
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

void Level1::Render()
{
	gfx->ClearScreen(0.94f, 0.94f, 0.94f);
	//gfx->DrawCircle(375.0f, y, 10.0f, 0.0f, 0.5f, 0.0f, 1.0f);
	sprites->Draw(500.0f, 100.0f, 0.3f, 1.0f);
	sprites->Draw(300.0f, 200.0f, 0.2f, 1.0f);
	sprites->Draw(400.0f, 150.0f, 0.25f, 1.0f);
}

