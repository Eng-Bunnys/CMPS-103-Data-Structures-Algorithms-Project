#include "GameManager.h"
#include "./Game Manager Start/ManagerStart.h"

ManagerStart StartHandler;

GameManager::GameManager() : TimeStep(0)
{
}

void GameManager::Start()
{
	StartHandler.SetSettings();
}

int GameManager::GetTimeStep() const {
	return this->TimeStep;
}