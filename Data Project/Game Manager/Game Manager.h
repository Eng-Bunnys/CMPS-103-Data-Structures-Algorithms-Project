#ifndef GameManager_H
#define GameManager_H

#include <fstream>
#include <iostream>

/// Misc Imports

#include "../Generator/Generator.h"
#include "../Temp List/Temp List.h"
#include "../Killed List/Killed List.h"

/// Army Imports

#include "../../Units/Unit.h"
#include "../../Units/Earth/Earth Army/Earth Army.h"
#include "../../Units/Alien/Alien Army/Alien Army.h"

class ManagerStart;
class GameManager
{
private:
    /* The current Time Step */
    int TimeStep = 0;
    /* The war winner */
    Army Winner;
    /* A pointer to the earth army instance */
    EarthArmy *Earth;
    /* A pointer to the alien army instance */
    AlienArmy *Aliens;
    /* A pointer to the generator instance */
    Generator *GeneratorInstance;
    /* A pointer to the Start Handler instance */
    ManagerStart *StartHandler;
    /* The killed list */
    KilledList *Killed;
    /* A pointer to the temp list instance*/
    TempList *TempListInstance;

public:
    GameManager();

    /**
     * Runs the simulation, consider it the start button for the application
     *
     * This method initiates the simulation of the war between Earth and Alien armies
     * @returns {void}
     */
    void Start();

    /// Modes
    /*
     * Run the Game in interactive mode
     *
     * This method executes the simulation in interactive mode where user inputs are accepted
     * @returns {void}
     */
    void RunInteractive();

    /*
     * Run the Game in silent mode
     *
     * This method executes the simulation silently without any user interaction
     * @returns {void}
     */
    void RunSilent();

    /*
     * Run the Game in test code mode
     *
     * This method executes the simulation with predefined test cases
     * @returns {void}
     */
    void RunTestCode();

    /// File Methods

    /**
     * Read input from a file
     * This method reads input data from a file to initialize the armies
     *
     * @param {string} FileName - The name of the file to read input from
     * @param {bool} Grand - Flag indicating if the reading operation is grand
     * @returns {bool} - True if the input is successfully read, false otherwise
     */
    bool ReadInput(std::string FileName, bool Grand);

    /// Phase 2
    // void ProduceOutput();

    /// Get & Set Methods

    /**
     * Get the current time step
     *
     * This method returns the current time step of the simulation
     * @returns {int} - The current time step
     */
    int GetTimeStep() const;

    /**
     * Get the Earth Army instance
     *
     * This method returns a pointer to the Earth Army instance
     * @returns {EarthArmy*} - A pointer to the Earth Army instance
     */
    EarthArmy *GetEarthArmy() const;

    /**
     * Get the Alien Army instance
     *
     * This method returns a pointer to the Alien Army instance
     * @returns {AlienArmy*} - A pointer to the Alien Army instance
     */
    AlienArmy *GetAlienArmy() const;

    /*
     * Get the Temp List instance
     *
     * @returns {TempList*} - A pointer to the Temp List instance
     */
    TempList *GetTempList() const;

    /*
     * Get the Killed List instance
     *
     * @returns {KilledList*} - A pointer to the Killed List instance
     */
    KilledList *GetKilledList() const;
    /// Attack Logic
    ///To-Do: Add JSDocs
    
    void EarthArmyAttack(GameManager* Game, bool Print);


    /// Prints & Other

    /**
     * Get the winner of the war
     *
     * This method returns the winning army of the war
     * @returns {Army} - The winning army
     */
    Army GetWinner();

    /**
     * Run the simulation for the next time step
     *
     * This method advances the simulation to the next time step
     * @returns {void}
     */
    void RunNextTimeStep(bool Print);

    /*
    * Runs all of the attacks 
    * 
    * @param {bool} PrintAttack - If we want to print the current attacking
    * @returns {void}
    */
    void RunAttack(bool PrintAttack);

    /**
     * Print the list of dead units
     *
     * This method prints the list of units killed during the simulation
     * @returns {void}
     */
    void PrintDead() const;

    /**
     * Print the list of available units
     *
     * This method prints the list of units available in the armies
     * @returns {void}
     */
    void PrintAvailableUnits() const;

    /**
     * Print the current time step
     *
     * This method prints the current time step of the simulation
     * @returns {void}
     */
    void PrintTime() const;

    /**
     * Print the current state of the simulation
     *
     * This method prints the current state of the simulation, including armies and time step
     * @returns {void}
     */
    void Print() const;
};

#endif // !GameManager_H