#ifndef EarthArmy_H
#define EarthArmy_H

#include "../../Game Manager/GameManager.h"
#include "./Earth Gunnery/Earth Gunnery.h"

#include "../../Structures/Priority Queue/linkedPriorityQueue.h"

class GameManager;
class EarthArmy {
private:
	/* A pointer to the game manager instance */
	GameManager* Game;
	/* The next free ID */
	int NextID;

	/// Units
	PriorityQueue<EarthGunnery*>* EarthGunneries;
	/// To-Do: Add the rest of the units
public:
	EarthArmy(GameManager* Game) {
		this->EarthGunneries = new PriorityQueue<EarthGunnery*>;
	}
	
	/// Gunnery Methods

	PriorityQueue<EarthGunnery*>* GetGunnery() const {
		return this->EarthGunneries;
	}

	void AddGunnery(int Power, double Health, int AttackCapacity) {
		/// To-Do: Replace 2 with Game->GetTimeStep() once it's done
		/// To-Do: Update the Next Free ID Logic (It's easy i'm just too tired rn) 
		EarthGunnery* NewGunnery = new EarthGunnery(++NextID, Health, Power, AttackCapacity, 2);
		this->EarthGunneries->enqueue(NewGunnery, NewGunnery->GetPriority());
	}

	/// To-Do: Empty & Print Functions
};

#endif // !EarthArmy_H
