#include "Game Manager.h"

int GameManager::GetTimeStep() const
{
    return this->TimeStep;
}

EarthArmy *GameManager::GetEarthArmy() const
{
    return this->Earth;
}

AlienArmy *GameManager::GetAlienArmy() const
{
    return this->Aliens;
}

Army GameManager::GetWinner()
{

    if (this->TimeStep < 40)
        return Army::None;
    else
    {
        if (this->Aliens->isEmpty())
        {
            this->Winner = Army::Earth;
            return Army::Earth;
        }
        else if (this->Earth->isEmpty())
        {
            this->Winner = Army::Alien;
            return Army::Alien;
        }
        else
            return Army::None;
    }
}