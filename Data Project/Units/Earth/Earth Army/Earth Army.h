#ifndef EarthArmy_H
#define EarthArmy_H

/// Structure Imports
#include "../../Structures/Stack/ArrayStack.h"
#include "../../Structures/Priority Queue/PriorityQueue.h"
#include "../../Structures/Queue/LinkedQueue.h"

/// Unit Imports
#include "../Earth Units/Earth Gunnery/Earth Gunnery.h"
#include "../Earth Units/Earth Tanks/Earth Tank.h"
#include "../Earth Units/Earth Soldier/Earth Soldier.h"
#include "../Earth Units/Earth Healer/Earth Healer.h"

class GameManager;
class AlienArmy;
class EarthArmy
{
private:
	/// General properties
	/** A pointer to the game manager instance */
	GameManager *Game;
	/** The next free ID */
	int NextID;

	/// Units
	/* A queue to store all of the Earth Gunnery */
	PriorityQueue<EarthGunnery *> *Gunnery;
	/* A stack to store all of the Earth Tanks */
	ArrayStack<EarthTank *> *Tanks;
	/* A queue to store all of the Earth Soldiers */
	LinkedQueue<EarthSoldier *> *Soldiers;
	/* A stack of the Earth Healers */
	ArrayStack<EarthHealer *> *Healers;

public:
	/*
	 * The Earth Army Constructor
	 *
	 * @param {GameManager*} Game - Pointer to an instance of the Game Manager
	 */
	EarthArmy(GameManager *Game);

#pragma region UnitGetters

	/*
	 * Returns the Earth Gunnery List
	 *
	 * @returns {PriorityQueue<EarthGunnery*>*}
	 */
	PriorityQueue<EarthGunnery *> *GetGunnery() const;

	/*
	 * Returns the Earth Tank List
	 *
	 * @returns {ArrayStack<EarthTank*>*}
	 */
	ArrayStack<EarthTank *> *GetTanks() const;

	/*
	 * Returns the Earth Soldier List
	 *
	 * @returns {LinkedQueue<EarthSoldier*>*}
	 */
	LinkedQueue<EarthSoldier *> *GetSoldiers() const;

	/*
	 * Returns the Earth Healers List
	 *
	 * @returns {ArrayStack<EarthHealer*>*}
	 */
	ArrayStack<EarthHealer *> *GetHealers() const;

#pragma endregion

#pragma region UnitSetters

	/*
	 * Adds a Gunnery to the Gunnery queue
	 *
	 * @param {double} Health - The Gunnery's health
	 * @param {int} Power - The Gunnery's power
	 * @param {int} AttackCapacity - The Gunnery's attack capacity
	 * @returns {bool} - If the add operation was successful
	 */
	bool AddGunnery(double Health, int Power, int AttackCapacity);

	/*
	 * Adds a Tank to the Tank stack
	 *
	 * @param {double} Health - The Tank's health
	 * @param {int} Power - The Tank's power
	 * @param {int} AttackCapacity - The Tank's attack capacity
	 * @returns {bool} - If the add operation was successful
	 */
	bool AddTank(double Health, int Power, int AttackCapacity);

	/*
	 * Adds a Soldier to the Soldier queue
	 *
	 * @param {double} Health - The Soldier's health
	 * @param {int} Power - The Soldier's power
	 * @param {int} AttackCapacity - The Soldier's attack capacity
	 * @returns {bool} - If the add operation was successful
	 */
	bool AddSoldier(double Health, int Power, int AttackCapacity);

	/*
	 * Adds a Healer to the Healer stack
	 *
	 * @param {double} Health - The Healer's health
	 * @param {int} Power - The Healer's power
	 * @param {int} AttackCapacity - The Healer's attack capacity
	 * @returns {bool} - If the add operation was successful
	 */
	bool AddHealer(double Health, int Power, int AttackCapacity);

#pragma endregion

#pragma region UnitRemovers

	/*
	 * Removes a Gunnery
	 *
	 * @param {EarthGunnery*&} RemovedGunnery - The removed gunnery
	 * @returns {bool} - Whether the remove operation was a success or not
	 */
	bool RemoveGunnery(EarthGunnery *&RemovedGunnery);

	/*
	 * Removes a Tank
	 *
	 * @param {EarthTank*&} RemovedTank - The removed tank
	 * @returns {bool} - Whether the remove operation was a success or not
	 */
	bool RemoveTank(EarthTank *&RemovedTank);

	/*
	 * Removes a Soldier
	 *
	 * @param {EarthSoldier*&} RemovedSoldier - The removed soldier
	 * @returns {bool} - Whether the remove operation was a success or not
	 */
	bool RemoveSoldier(EarthSoldier *&RemovedSoldier);

	/*
	 * Removes a Healer
	 *
	 * @param {EarthHealer*&} RemovedHealer - The removed healer
	 * @returns {bool} - Whether the remove operation was a success or not
	 */
	bool RemoveHealer(EarthHealer *&RemovedHealer);
#pragma endregion

	/// Unit Peeks

#pragma region UnitPeeks

	/*
	 * Peeks a Soldier
	 *
	 * @param {EarthSoldier*&} PeekedSoldier - The peeked soldier
	 * @returns {bool} - Whether the peek operation was a success or not
	 */
	bool PeekSoldier(EarthSoldier *&PeekedSoldier);

	/*
	 * Peeks a Tank
	 *
	 * @param {EarthTank*&} PeekedTank - The peeked Tank
	 * @returns {bool} - Whether the peek operation was a success or not
	 */
	bool PeekTank(EarthTank *&PeekedTank);

	/*
	 * Peeks a Gunnery
	 *
	 * @param {EarthGunnery*&} PeekedGunnery - The peeked Gunnery
	 * @returns {bool} - Whether the peek operation was a success or not
	 */
	bool PeekGunnery(EarthGunnery *&PeekedGunnery);

	/*
	 * Peeks a Healer
	 *
	 * @param {EarthHealer*&} PeekedHealer - The peeked Healer
	 * @returns {bool} - Whether the peek operation was a success or not
	 */
	bool PeekHealer(EarthHealer *&PeekedHealer);
#pragma endregion

#pragma region Misc

	/*
	 * Prints all the data for the Alive Earth Units
	 *
	 * @param {void}
	 * @returns {void}
	 */
	void Print() const;

	/*
	 * Checks if the Earth Army is empty
	 *
	 * @returns {bool} - True if the Earth Army is empty, false otherwise
	 */
	bool isEmpty() const;

	/*
	 * Checks if units can be added to the Earth Army
	 *
	 * @returns {bool} - True if units can be added, false otherwise
	 */
	bool CanAdd() const;

#pragma endregion

	/*
	 * Earth Army Destructor
	 */
	~EarthArmy();
};

#endif // !EarthArmy_H
