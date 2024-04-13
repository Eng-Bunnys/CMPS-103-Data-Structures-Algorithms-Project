#ifndef GameManager_H
#define GameManager_H

#include <iostream>
#include "../Enums/Enums.h"
#include "../../Platform.h"

class GameManager
{
private:
	/* The current Time Step */
	int TimeStep = 0;
	/* The war winner */
	Army Winner;
	/* A pointer to the earth army instance */
public:
	GameManager();

	/* Runs the simulation, consider it the start button for the application */
	void Start();

	///// Modes
	///* Runs the interactive simulation */
	//void StartInteractive();
	///* Runs the silent simulation */
	//void StartSilent();

	//void PrintAlive();
	//void PrintDead();

	/// Getters
	int GetTimeStep() const;
	//Army GetWinner() const;


	//// Calls increment timestep and runs the logic for fight
	//void RunStep();

	///// Other functions
	//void incrementTimeStep();

	///// Phase 2
	//// void battle();

	//~GameManager();
};

#endif // !GameManager_H