#include "Game Manager.h"
#include "./Game Manager Start/ManagerStart.h"

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
                this->Killed->AddUnit(ETank);
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

        if (RandomNumber >= 41 && RandomNumber <= 50)
        {
            AlienMonster* AMonster;
            for (int i = 0; i < 5; i++)
            {
                if (this->Aliens->RemoveMonster(AMonster))
                    (this->Aliens->GetMonsters()).Add(AMonster);
            }
        }

        if (RandomNumber > 50 && RandomNumber < 60)
        {
            AlienDrone* ADrone;

            for (int i = 0; i < 6; i++)
            {
                if (this->Aliens->RemoveDrone(ADrone))
                    this->Killed->AddUnit(ADrone);
            }
        }

        this->Print();

        this->StartHandler->HandleStart();
        this->TimeStep++;
    }
};