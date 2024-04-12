#include "ManagerStart.h"

void ManagerStart::ClearConsole() {
    char UserInput;

    std::cout << "To clear the console, enter [1]. To continue, press on any key.";
    std::cin.get(UserInput);

    if (UserInput == '1') {
        if (IS_WINDOWS)
            system("cls");
        else
            system("clear");
    }
    else return;
}

void ManagerStart::SetSettings() {
    std::cout << this->WelcomeMessage << std::endl;

    while (true) {
        std::cout << ScenarioSettings;

        int ChoiceScenario;
        std::cin >> ChoiceScenario;

        switch (ChoiceScenario) {
        case 1:
            GameScenario = Scenario::BothStrong;
            break;
        case 2:
            GameScenario = Scenario::BothWeak;
            break;
        case 3:
            GameScenario = Scenario::EarthStrongAlienWeak;
            break;
        case 4:
            GameScenario = Scenario::EarthWeakAlienStrong;
            break;
        case 0:
            GameScenario = Scenario::StructureTest;
            break;
        default:
            std::cout << "Invalid scenario choice, choose a valid scenario." << std::endl;

            ClearConsole();

            continue;
        }
        break;
    }

    while (true) {
        std::cout << this->SimulationType;

        int ChoiceSimulation;
        std::cin >> ChoiceSimulation;

        if (ChoiceSimulation == 1) {
            this->GameSimulation = Simulation::Grand;
            break;
        }
        else if (ChoiceSimulation == 2) {
            this->GameSimulation = Simulation::Simple;
            break;
        }
        else {
            std::cout << "Invalid simulation type choice, choose a valid simulation type." << std::endl;

            ClearConsole();

            continue;
        }
    }

    while (true) {
        std::cout << this->ModeType;

        int ChoiceMode;

        std::cin >> ChoiceMode;

        if (ChoiceMode == 1) {
            this->GameMode = Mode::Interactive;
            break;
        }
        else if (ChoiceMode == 2) {
            this->GameMode = Mode::Silent;
            break;
        }
        else {
            std::cout << "Invalid mode choice, choose a valid mode." << std::endl;

            ClearConsole();

            continue;
        }
    }
}