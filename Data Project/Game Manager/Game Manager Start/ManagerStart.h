#ifndef GameManagerStart_H
#define GameManagerStart_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>

#include "../../Enums/Enums.h"
#include "../../Platform.h"

#include "../Game Manager.h"

class GameManager;
class ManagerStart
{
public:
    GameManager* Game;
    ManagerStart(GameManager* Game);
    /* The chosen game mode */
    Mode GameMode;
    /* The chosen scenario */
    Scenario GameScenario;
    /* The chosen simulation type */
    Simulation GameSimulation;
    /* The path to the txt */
    std::string FilePath;

    /* Project Name */
    std::string GameName = "Annihilate";

    /* Welcome message */
    std::string WelcomeMessage = "Welcome to " + GameName +
                                 " player, you will be prompted to choose the game settings!" +
                                 std::string("\nTo pick a setting you input the number next to the desiered setting or simply use the arrow keys.");

    /* String to prompt the user to run in either interactive or silent mode */
    std::string ModeType = "Choose a mode to run:\n- Interactive [1]\n- Silent [2]\nYour input: ";

    /* String to prompt the user to choose a scenario to run */
    std::string ScenarioSettings = "Choose a scenario to run:\n" + std::string("- Both Strong [1]\n") +
                                   std::string("- Both Weak [2]\n") +
                                   std::string("- Earth Strong, Alien Weak [3]\n") +
                                   std::string("- Earth Weak, Alien Strong [4]\n") +
                                   std::string("- Structure Test [0]\n") +
                                   std::string("Your input: ");

    /* String to let the user choose between grand or simple simulation */
    std::string SimulationType = "Choose the simulation type:\n- Grand [1]\n- Simple [2]\nYour input: ";

    void SetSettings();

    void HandleStart();

    void ClearConsole(bool ForceClear = false);

    void PressAnyContinue();

    std::string ScenarioToString(Scenario ChosenScenario)
    {
        switch (ChosenScenario)
        {
        case Scenario::BothStrong:
            return "Both Strong";
        case Scenario::BothWeak:
            return "Both Weak";
        case Scenario::EarthStrongAlienWeak:
            return "Earth Strong, Alien Weak";
        case Scenario::EarthWeakAlienStrong:
            return "Earth Weak, Alien Strong";
        case Scenario::StructureTest:
            return "Structure Test";
        default:
            return "Unknown Scenario";
        }
    }

    std::string SimulationToString(Simulation ChosenSimulation)
    {
        switch (ChosenSimulation)
        {
        case Simulation::Grand:
            return "Grand";
        case Simulation::Simple:
            return "Simple";
        default:
            return "Unknown Simulation";
        }
    }

    std::string ModeToString(Mode ChosenMode)
    {
        switch (ChosenMode)
        {
        case Mode::Interactive:
            return "Interactive";
        case Mode::Silent:
            return "Silent";
        default:
            return "Unknown Mode";
        }
    }
};

#endif // !GameManagerStart_H
