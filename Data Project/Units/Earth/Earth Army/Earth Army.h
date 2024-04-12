#ifndef EarthArmy_H
#define EarthArmy_H

#include "../../Game Manager/GameManager.h"
#include "../../Structures/Priority Queue/PriorityQueue.h"
#include "../Earth Units/Earth Gunnery/Earth Gunnery.h"

class GameManager;
class EarthArmy
{
private:
	/// General properties
	/* A pointer to the game manager instance */
	GameManager* Game;
	/* The next free ID */
	int NextID;

	/// Units
	PriorityQueue<EarthGunnery*> Gunnery;

public:
	EarthArmy(GameManager* Game);

	/// Getters

	PriorityQueue<EarthGunnery*> GetGunnery() const;

	/// Army functions
	void AddGunnery(double Health, int Power, int AttackCapacity);
	EarthGunnery* RemoveGunnery();

	/// To-Do Add print, isEmpty, etc.'

	//void Print() const;
	//bool IsEmpty() const;

	///To-Do: Phase 2
	// virtual void attack();

	~EarthArmy();
};

#endif // !EarthArmy_H