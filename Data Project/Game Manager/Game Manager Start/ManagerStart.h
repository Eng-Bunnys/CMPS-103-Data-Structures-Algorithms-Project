#ifndef GameManagerStart_H
#define GameManagerStart_H

#include <cstdlib>
#include <iostream>
#include <string>

#include "../../Enums/Enums.h"
#include "../../Platform.h"

class ManagerStart
{
public:
	/* The chosen game mode */
	Mode GameMode;
	/* The chosen scenario */
	Scenario GameScenario;
	/* The chosen simulation type */
	Simulation GameSimulation;

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

	void ClearConsole();
};

#endif // !GameManagerStart_H
