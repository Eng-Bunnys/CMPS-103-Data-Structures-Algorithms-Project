#ifndef AlienArmy_H
#define AlienArmy_H

#include "../../Game Manager/GameManager.h"
#include "../../Earth/Earth Army/Earth Army.h"

class GameManager;
class EarthArmy;
class AlienArmy {
private: 
	GameManager* Game;
	int NextID;
public:
	AlienArmy(GameManager* Game);

	/// Getters

	/// Setters

	/// Prints & Misc

	bool IsEmpty();
	void Print();

	~AlienArmy();
};
#endif // !AlienArmy_H
