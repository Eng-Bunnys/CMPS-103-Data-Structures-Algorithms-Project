#include "Game Manager.h"

void GameManager::PrintTime() const {
	std::cout << "Current Timestep: " << GetTimeStep() << std::endl;
}

void GameManager::PrintAvailableUnits() const {
	PrintTime();

	this->Earth->Print();

	std::cout << std::endl;

	this->Aliens->Print();
}

void GameManager::PrintDead() const {
	std::cout << "============== Killed/Destructed Units ==============" << std::endl;
	std::cout << this->KilledList->GetCount() << " units ";
	this->KilledList->Print();
}

void GameManager::Print() const {
	std::cout << "==========================================" << std::endl;

	this->PrintAvailableUnits();

	std::cout << "==========================================" << std::endl;

	this->PrintDead();

	std::cout << "==========================================" << std::endl;
}