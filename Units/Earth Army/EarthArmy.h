#ifndef EarthArmy_H
#define EarthArmy_H

#include "../../Game Manager/GameManager.h"

class GameManager;
class EarthArmy
{
private: 
	GameManager Manager;
public:
	EarthArmy(GameManager* Manager);

	~EarthArmy();
};

#endif // !EarthArmy_H