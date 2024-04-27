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

    this->KilledList = new LinkedQueue<Unit*>();
}

void GameManager::RunNextTimeStep()
{
    this->GeneratorInstance->Generate();
    this->TimeStep++;
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

        this->RunNextTimeStep();

        this->StartHandler->PressAnyContinue();
    }
};

void GameManager::RunSilent()
{
    std::cout << "Welcome to the Silent Mode of " << this->StartHandler->GameName << "!\n";

    this->StartHandler->PressAnyContinue();

    while (this->GetWinner() == Army::None)
    {
        this->RunNextTimeStep();
    }
};

void GameManager::RunTestCode()
{
    std::cout << "Running Structure Test!\n";

    this->StartHandler->PressAnyContinue();

    while (this->TimeStep != 50)
    {
        this->GeneratorInstance->Generate();

        int RandomNumber = Utils::GenerateRandomNumber();

        if (RandomNumber >= 1 && RandomNumber <= 10)
        {
            EarthSoldier* ESoldier;

            if (this->Earth->GetSoldiers().dequeue(ESoldier))
            {
                this->Earth->GetSoldiers().enqueue(ESoldier);
            }
        }

        if (RandomNumber >= 11 && RandomNumber <= 20)
        {
            EarthTank* ETank;

            if (this->Earth->GetTanks().pop(ETank))
            {
                this->KilledList->enqueue(ETank);
            }
        }

        if (RandomNumber >= 21 && RandomNumber <= 30)
        {
            EarthGunnery* EGunnery;

            if (this->Earth->RemoveGunnery(EGunnery))
            {
                double NewHealth = EGunnery->GetHealth() / 2;
                EGunnery->SetHealth(NewHealth);

                this->Earth->AddGunnery(EGunnery->GetHealth(), EGunnery->GetPower(), EGunnery->GetAttackCapacity());
            }
        }

        if (RandomNumber >= 31 && RandomNumber <= 40)
        {
            AlienSoldier* ASoldier;

            LinkedQueue<AlienSoldier*>* TempList = new LinkedQueue<AlienSoldier*>;

            for (int i = 0; i < 5; i++)
            {
                if (this->Aliens->GetSoldiers().dequeue(ASoldier))
                {
                    double NewHealth = ASoldier->GetHealth() - 30;
                    ASoldier->SetHealth(NewHealth);

                    TempList->enqueue(ASoldier);
                    TempList->dequeue(ASoldier);
                    this->Aliens->GetSoldiers().enqueue(ASoldier);
                }
            }

            delete TempList;
        }

        if (RandomNumber >= 41 && RandomNumber <= 50) {
            AlienMonster* AMonster;
            for (int i = 0; i < 5; i++) {
                if (this->Aliens->RemoveMonster(AMonster))
                    (this->Aliens->GetMonsters()).Add(AMonster);
            }
        }

        if (RandomNumber > 50 && RandomNumber < 60) {
            AlienDrone* ADrone;

            for (int i = 0; i < 6; i++) {
                if (this->Aliens->RemoveDrone(ADrone)) this->KilledList->enqueue(ADrone);
            }

        }

        this->Print();

        this->StartHandler->HandleStart();
        this->TimeStep++;
    }
};