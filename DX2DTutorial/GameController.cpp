#include "GameController.h"


GameLevel* GameController::currentLevel;
bool GameController::Loading;
HPTimer* GameController::hpTimer;

void GameController::Init()
{
	Loading = true;
	currentLevel = 0;
	hpTimer = new HPTimer();
}

void GameController::LoadInitialLevel(GameLevel* lev) 
{
	Loading = true;
	currentLevel = lev;
	currentLevel->Load();
	Loading = false;
}

void GameController::SwitchLevel(GameLevel* lev) 
{
	Loading = true;
	currentLevel->Unload();
	delete currentLevel;

	lev->Load();
	currentLevel = lev;
	Loading = false;
}

void GameController::Render()
{
	if (Loading) return;
	currentLevel->Render();
}

void GameController::Update()
{
	if (Loading) return;
	hpTimer->Update();
	
	
	currentLevel->Update(hpTimer->GetTimeTotal(), hpTimer->GetTimeDelta());
}