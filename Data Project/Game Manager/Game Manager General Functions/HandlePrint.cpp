#include "../Game Manager.h"

void GameManager::PrintTime() const
{
	std::cout << "Current Timestep: " << GetTimeStep() + 1 << std::endl;
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
	std::cout << this->Killed->GetCount() << " Dead Units ";
	this->Killed->Print();
}

void GameManager::Print() const
{
	PrintAvailableUnits();

	std::cout << std::endl;

	PrintDead();
}