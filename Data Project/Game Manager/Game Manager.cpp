#include "Game Manager.h"
#include "./Game Manager Start/ManagerStart.h"

GameManager::GameManager()
{
    this->TimeStep = 0;

    this->Earth = new EarthArmy(this);
    this->Aliens = new AlienArmy(this);
    this->GeneratorInstance = new Generator(this);
    this->StartHandler = new ManagerStart(this);
}

void GameManager::RunNextTimeStep() {
    this->GeneratorInstance->Generate();
    this->TimeStep++;
}

void GameManager::Start()
{
    StartHandler->SetSettings();
}

void GameManager::RunInteractive() {
    this->StartHandler->ClearConsole(true);

    std::cout << "Welcome to the Interactive Mode of " << this->StartHandler->GameName << "!\n";

    this->StartHandler->PressAnyContinue();

    while (this->GetWinner() == Army::None) {
        this->Print();

        std::cout << std::endl;

        this->RunNextTimeStep();

        this->StartHandler->PressAnyContinue();
    }
};

void GameManager::RunSilent() {
    std::cout << "Welcome to the Silent Mode of " << this->StartHandler->GameName << "!\n";

    this->StartHandler->PressAnyContinue();

    while (this->GetWinner() == Army::None) {
        this->RunNextTimeStep();
    }
};

void GameManager::RunTestCode() {};