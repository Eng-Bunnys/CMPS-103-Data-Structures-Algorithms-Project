#ifndef GameManager_H
#define GameManager_H

#include <iostream>
#include "../Enums/Enums.h"

class GameManager
{
private:
	/* The current Time Step */
	int TimeStep;
	/* The war winner */
	Army Winner;

public:
	GameManager();
	~GameManager();

	/* Runs the simulation */
	void Start();

	/// Getters
	int GetTimeStep() const;
	Army GetWinner() const;

	/// Modes
	/* Runs the interactive simulation */
	void StartInteractive();
	/* Runs the silent simulation */
	void StartSilent();

	/// Texts
	/* String to prompt the user to run in either interactive or silent mode */
	std::string ModeType = "To run \"Interactive Mode\", enter 1. To run \"Silent Mode\", enter 0.";
};

#endif // !GameManager_H