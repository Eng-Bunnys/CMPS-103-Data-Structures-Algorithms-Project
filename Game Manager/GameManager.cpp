#include "GameManager.h"

GameManager::GameManager() : TimeStep(0)
{
}

void GameManager::Start()
{
	std::cout << "Welcome player to the Alien Invasion simulation, choose a mode to run." << std::endl;
	std::cout << ">> " << ModeType;
}

GameManager::~GameManager()
{
}
