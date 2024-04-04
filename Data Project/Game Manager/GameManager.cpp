#include "GameManager.h"

GameManager::GameManager() : TimeStep(0)
{
}

void GameManager::Start()
{
	std::cout << "Welcome player to the Alien Invasion simulation, choose a mode to run." << std::endl;
	std::cout << ">> " << ModeType;
}

int GameManager::GetTimeStep() const
{
	return TimeStep;
}

Army GameManager::GetWinner() const
{
	return Winner;
}

void GameManager::incrementTimeStep()
{
	TimeStep++;
}

void GameManager::StartInteractive()
{
	int key;
	while (TimeStep <= 50)
	{
		std::cout << "Current Timestep " << TimeStep;
		// displaying details
		std::cout << "Press any key to move to next time step";
		std::cin >> key;
		TimeStep++;
	}
}

void GameManager::StartSilent()
{
	std::cout << "Silent Mode\n";
	std::cout << "Simulation Starts...\n";
	std::cout << "Simluation Ends , output file is created\n";
	// output creating function
}

GameManager::~GameManager()
{
}
