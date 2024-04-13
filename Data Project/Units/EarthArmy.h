/// Unit => EarthUnit => EarthArmy => Soldier, Tank, etc.
#ifndef EarthArmy_H
#define EarthArmy_H

#include "../../Game Manager/GameManager.h"
#include "./Earth Gunnery/Earth Gunnery.h"
#include"./Earth Soldier/Earth Soldiers.h"

#include "../../Structures/Priority Queue/linkedPriorityQueue.h"
#include"../../Structures/Queue/LinkedQueue.h"



class GameManager;
class EarthArmy {
private:
	/* A pointer to the game manager instance */
	GameManager* Game;
	/* The next free ID */
	int NextID;

	int NextSoldierID;

	/// Units
	PriorityQueue<EarthGunnery*>* EarthGunneries;

	LinkedQueue<EarthSoldiers*>* EarthSoldiers;

	/// To-Do: Add the rest of the units
public:
	EarthArmy(GameManager* Game) {
		this->EarthGunneries = new PriorityQueue<EarthGunnery*>;
		this->EarthSoldiers = new LinkedQueue<EarthSoldiers*>*;
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

	/// Soldier Methods
	LinkedQueue<EarthSoldiers*>* GetSoldier() const {
		return this->EarthSoldiers;
	}

	void AddSoldier(int Power, double Health, int AttackCapacity) {
		EarthSoldiers* NewSoldier = new EarthSoldiers(++NextSoldierID, Health, Power, AttackCapacity,2); // replace 2 with Game->GetTimeStep
		this->EarthSoldiers->enqueue(NewSoldier);
	}

	void RemoveSoldier(){
		if (!EarthSoldiers->isEmpty()) {
			EarthSoldiers* SoldierToRemove = nullptr;
			EarthSoldiers->dequeue(SoldierToRemove);
			delete SoldierToRemove;
		}
	}

	void PrintSoldiers() const{
		if (!EarthSoldiers->isEmpty()) {
			std::cout << "ES " << EarthSoldiers->getCount() << "[";
			LinkedQueue<EarthSoldiers*>* tempQueue = new LinkedQueue<EarthSoldiers*>();
			EarthSoldiers* soldier = nullptr;

			while (EarthSoldiers->dequeue(soldier)) {
				std::cout << soldier->GetID();
				tempQueue->enqueue(soldier);
				if (!EarthSoldiers->isEmpty()) {
					std::cout << ", ";
				}
			}

			while (tempQueue->dequeue(soldier)) {
				EarthSoldiers->enqueue(soldier);
			}

			std::cout << "]" << std::endl;
			delete tempQueue;
		}

	}

};

#endif // !EarthArmy_H
