#include "GameController.h"
#include "Graphics.h"
#include "Level1.h"

void Level1::Load()
{
	xPosition = 0.0f;
	sprites = new SpriteSheet(L"image1.png", gfx);
}

void Level1::Unload()
{
	delete sprites;
}

void Level1::Update(double timeTotal, double timeDelta)
{

	xPosition += 20000000.0f * timeDelta;
	if (xPosition > 800) xPosition -= 800.0f;

}

void Level1::Render()
{
	gfx->ClearScreen(0.94f, 0.94f, 0.94f);
	gfx->DrawCircle(250.0f, 150.0f, 30.0f, 0.0f, 0.5f, 0.0f, 1.0f);
	gfx->DrawCircle(450.0f, 150.0f, 30.0f, 0.5f, 0.0f, 0.0f, 1.0f);
	
	sprites->Draw(xPosition, 100.0f, 0.3f, 1.0f);
	//sprites->Draw(300.0f, 200.0f, 0.2f, 0.2f);
	//sprites->Draw(400.0f, 150.0f, 0.25f, 0.2f);


}

