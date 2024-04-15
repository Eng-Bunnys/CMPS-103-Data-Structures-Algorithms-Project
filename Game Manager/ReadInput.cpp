#include "Game Manager.h"

bool GameManager::ReadInput(std::string FileName, bool Grand)
{
    std::string FullPath = FileName;

    if (FullPath.find("Scenarios/") != 0)
        FullPath = "Scenarios/" + FullPath;

    std::ifstream InputFile(FullPath, std::ios::in);

    if (!InputFile.is_open())
    {
        /// To-Do: Re-add when the Bag is fixed
        // std::cout << "Invalid File Path Specified." << std::endl;
        return false;
    }
    else
    {
        // Reading the number of army units to generate
        int UnitCount;

        InputFile >> UnitCount;

        if (Grand)
            UnitCount *= 10;

        // Reading the Soldier, Tank, and Gunnery %

        int EarthSoldier;
        int EarthTank;
        int EarthGunnery;

        InputFile >> EarthSoldier >> EarthTank >> EarthGunnery;

        // Reading the Soldier, Monster, and Drone &

        int AlienSoldier;
        int AlienMonster;
        int AlienDrone;

        InputFile >> AlienSoldier >> AlienMonster >> AlienDrone;

        // Reading the probability

        int Probability;

        InputFile >> Probability;

        // Checking the general parameters

        if (!this->GeneratorInstance->AssignGeneral(UnitCount, Probability))
        {
            InputFile.close();
            return false;
        }

        // Reading the Power, Health, and Attack Capacity ranges

        double EarthHealth[2];
        int EarthPower[2];
        int EarthAttackCapacity[2];

        (InputFile >> EarthPower[0]).ignore(1) >> EarthPower[1];
        (InputFile >> EarthHealth[0]).ignore(1) >> EarthHealth[1];
        (InputFile >> EarthAttackCapacity[0]).ignore(1) >> EarthAttackCapacity[1];

        // Checking the range parameters

        if (!this->GeneratorInstance->AssignEarth(EarthSoldier, EarthTank, EarthGunnery, EarthHealth, EarthPower, EarthAttackCapacity))
        {
            InputFile.close();
            return false;
        }

        double AlienHealth[2];
        int AlienPower[2];
        int AlienAttackCapacity[2];

        (InputFile >> AlienPower[0]).ignore(1) >> AlienPower[1];
        (InputFile >> AlienHealth[0]).ignore(1) >> AlienHealth[1];
        (InputFile >> AlienAttackCapacity[0]).ignore(1) >> AlienAttackCapacity[1];

        // Checking the range parameters

        if (!this->GeneratorInstance->AssignAlien(AlienSoldier, AlienMonster, AlienDrone, AlienHealth, AlienPower, AlienAttackCapacity))
        {
            InputFile.close();
            return false;
        }

        InputFile.close();
        return true;
    }
}