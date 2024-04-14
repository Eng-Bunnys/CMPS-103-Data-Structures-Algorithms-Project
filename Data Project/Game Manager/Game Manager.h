#ifndef GameManager_H
#define GameManager_H

#include <fstream>
#include <iostream>

/// Misc Imports

#include "./Game Manager Start/ManagerStart.h"

#include "../Generator/Generator.h"

/// Army Imports

#include "../../Units/Unit.h"
#include "../../Units/Earth/Earth Army/Earth Army.h"
#include "../../Units/Alien/Alien Army/Alien Army.h"

class GameManager
{
private:
    /* The current Time Step */
    int TimeStep = 0;
    /* The war winner */
    Army Winner;
    /* A pointer to the earth army instance */
    EarthArmy *Earth;
    AlienArmy* Aliens;
    /* A pointer to the generator instance */
    Generator *GeneratorInstance;

public:
    GameManager();

    /* Runs the simulation, consider it the start button for the application */
    void Start();

    /// Modes

    void RunInteractive();
    void RunSilent();
    void RunTestCode();

    /// File Methods

    bool ReadInput(std::string FileName, bool Grand);
    /// Phase 2
    // void ProduceOutput();

    /// Get & Set Methods

    int GetTimeStep() const;
    EarthArmy *GetEarthArmy() const;
    AlienArmy* GetAlienArmy() const;

    /// Prints & Other

    void IncrementStep();

    void PrintDead();
};

#endif // !GameManager_H