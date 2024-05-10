#include "Game Manager.h"
#include "./Game Manager Start/ManagerStart.h"
#include "../../Utils/Utils.h"

/// Unit Imports
#include "../../Units/Earth/Earth Units/Earth Gunnery/Earth Gunnery.h"
#include "../../Units/Earth/Earth Units/Earth Soldier/Earth Soldier.h"
#include "../../Units/Earth/Earth Units/Earth Tanks/Earth Tank.h"

#include "../../Units/Alien/Alien Units/Alien Drones/Alien Drones.h"
#include "../../Units/Alien/Alien Units/Alien Monsters/Alien Monsters.h"
#include "../../Units/Alien/Alien Units/Alien Soldier/Alien Soldier.h"

GameManager::GameManager()
{
    this->Winner = Army::None;
    this->TimeStep = 0;

    this->Earth = new EarthArmy(this);
    this->Aliens = new AlienArmy(this);
    this->GeneratorInstance = new Generator(this);
    this->StartHandler = new ManagerStart(this);

    this->Killed = new KilledList();
    this->TempListInstance = new TempList();

    this->UML = new UnitMaintenanceList(this);
}

void GameManager::RunNextTimeStep(bool Print) {
    this->GeneratorInstance->Generate();
    ///To-Do: Fix the title print
    this->RunAttack(Print, Print);
    this->TimeStep++;
}

void GameManager::RunAttack(bool PrintAttack, bool TitlePrinted) {
    if (TitlePrinted)
        std::cout << "============== Units Fighting At Current Step ==============" << std::endl;

    this->EarthArmyAttack(this, PrintAttack);
}

void GameManager::Start()
{
    StartHandler->SetSettings();
}

void GameManager::RunInteractive()
{
    this->StartHandler->ClearConsole(true);

    std::cout << "Welcome to the Interactive Mode of " << this->StartHandler->GameName << "!\n";

    this->StartHandler->PressAnyContinue();

    while (this->GetWinner() == Army::None)
    {
        this->Print();

        std::cout << std::endl;

        this->RunNextTimeStep(true);

        this->StartHandler->PressAnyContinue();
    }
};

void GameManager::RunSilent()
{
    std::cout << "Welcome to the Silent Mode of " << this->StartHandler->GameName << "!\n";

    this->StartHandler->PressAnyContinue();

    while (this->GetWinner() == Army::None)
    {
        this->RunNextTimeStep(false);
    }
};


UnitMaintenanceList* GameManager::GetUML() {
    return this->UML;
}
