#include "ManagerStart.h"
#include "../Game Manager.h"

void ManagerStart::PressAnyContinue() {
    std::cout << "Press any button to continue." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

ManagerStart::ManagerStart(GameManager* Game) {
    this->Game = Game;
}

void ManagerStart::ClearConsole(bool ForceClear)
{
    if (!ForceClear)
    {
        char UserInput;

        std::cout << "To clear the console, enter [1]. To continue, press on any key. ";
        std::cin >> UserInput;

        if (UserInput == '1')
        {
            if (IS_WINDOWS)
                system("cls");
            else
                system("clear");
        }
        else
            return;

        // Clear the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.clear();

        std::cout << "\nConsole cleared. Press any key to continue...";
        std::cin.ignore();
    }
    else
    {
        if (IS_WINDOWS)
            system("cls");
        else
            system("clear");
    }
}

void ManagerStart::SetSettings()
{
    std::cout << this->WelcomeMessage << std::endl;

    while (true)
    {
        std::cout << "\n"
                  << this->ScenarioSettings;

        int ChoiceScenario;
        std::cin >> ChoiceScenario;

        switch (ChoiceScenario)
        {
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

    while (true)
    {
        std::cout << "\n"
                  << this->SimulationType;

        int ChoiceSimulation;
        std::cin >> ChoiceSimulation;

        if (ChoiceSimulation == 1)
        {
            this->GameSimulation = Simulation::Grand;
            break;
        }
        else if (ChoiceSimulation == 2)
        {
            this->GameSimulation = Simulation::Simple;
            break;
        }
        else
        {
            std::cout << "Invalid simulation type choice, choose a valid simulation type." << std::endl;

            ClearConsole();

            continue;
        }
    }

    while (true)
    {
        std::cout << "\n"
                  << this->ModeType;

        int ChoiceMode;

        std::cin >> ChoiceMode;

        if (ChoiceMode == 1)
        {
            this->GameMode = Mode::Interactive;
            break;
        }
        else if (ChoiceMode == 2)
        {
            this->GameMode = Mode::Silent;
            break;
        }
        else
        {
            std::cout << "Invalid mode choice, choose a valid mode." << std::endl;

            ClearConsole();

            continue;
        }
    }

    std::cout << "\n\nVerify the following settings:\n"
              << "- Scenario: "
              << ScenarioToString(GameScenario) << "\n"
              << "- Simulation Type: "
              << SimulationToString(GameSimulation) << "\n"
              << "- Mode: " << ModeToString(GameMode) << "\n"
              << "Enter [No] to confirm or press any key to continue. ";

    std::string UserConfirmation;

    while (true)
    {
        std::getline(std::cin >> std::ws, UserConfirmation);

        std::transform(UserConfirmation.begin(), UserConfirmation.end(), UserConfirmation.begin(), ::tolower);

        if (UserConfirmation != "no")
            break;
        else
        {
            std::cout << "Restarting Selection..." << std::endl;
            ClearConsole(true);
            SetSettings();
            break;
        }
    }

    HandleStart();
}

void ManagerStart::HandleStart() {
    switch (GameScenario)
    {
    case BothStrong:
        this->FilePath += "BothStrong.txt";
        break;
    case BothWeak:
        this->FilePath += "BothWeak.txt";
        break;
    case EarthStrongAlienWeak:
        this->FilePath += "StrongEarth.txt";
        break;
    case EarthWeakAlienStrong:
        this->FilePath += "StrongAlien.txt";
        break;
    case StructureTest:
        this->FilePath += "StructureTest.txt";

        std::cout << "Reading Input File for Game Scenario..." << std::endl;

        if (!this->Game->ReadInput(this->FilePath, false)) {
             ///To-Do: Re-add this after fixing the Bag
            //  std::cout << "Failed to read input file." << std::endl;
            return;
        }

        this->Game->RunTestCode();
        break;
    }

    if (!this->Game->ReadInput(this->FilePath, this->GameSimulation)) {
            ///To-Do: Re-add this after fixing the Bag
            //  std::cout << "Failed to read input file." << std::endl;
        return;
    }

    switch (GameMode)
    {
    case Interactive:
        this->Game->RunInteractive();
        break;
    case Silent:
        this->Game->RunSilent();
        break;
    default:
        break;
    }
}