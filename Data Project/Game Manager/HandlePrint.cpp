#include "Game Manager.h"

void GameManager::PrintTime() const
{
	std::cout << "Current Timestep: " << GetTimeStep() << std::endl;
}

void GameManager::PrintAvailableUnits() const
{
	PrintTime();

	std::cout << "============== Earth Army Alive Units ==============" << std::endl;
	this->Earth->Print();
	std::cout << std::endl;

	std::cout << "============== Alien Army Alive Units ==============" << std::endl;
	this->Aliens->Print();
}

void GameManager::PrintDead() const
{
	std::cout << "============== Dead Units ==============" << std::endl;
	std::cout << this->KilledList->GetCount() << " Dead Units ";
	this->KilledList->Print();
}

void GameManager::Print() const
{
	std::cout << "==========================================" << std::endl;

	PrintAvailableUnits();

	std::cout << "==========================================" << std::endl;

	PrintDead();

	std::cout << "==========================================" << std::endl;
}