#ifndef AlienArmy_H
#define AlienArmy_H

/// Structure Imports
#include "../../../Structures/Deque/Deque.h"
#include "../../../Structures/Queue/LinkedQueue.h"
#include "../../../Structures/Bag/Bag.h"

/// Unit Imports
#include "../Alien Units/Alien Drones/Alien Drones.h"
#include "../Alien Units/Alien Monsters/Alien Monsters.h"
#include "../Alien Units/Alien Soldier/Alien Soldier.h"

class GameManager;
class EarthArmy;
class AlienArmy
{
private:
	/// General properties
	/** A pointer to the game manager instance */
	GameManager *Game;
	/** The next free ID */
	int NextID;

	/// Units

	/* A queue to store all of the Alien Soldiers */
	LinkedQueue<AlienSoldier *> AlienSoldierQueue;
	/* A Bag to store all of the Alien Monsters */
	Bag<AlienMonsters *> Monsters;
	/* A Double Ended Queue to store all of the Alien Drones */
	Deque<AlienDrones *> Drones;

public:
	/*
	 * The Alien Army Constructor
	 *
	 * @param {GameManager*} Game - Pointer to an instance of the Game Manager
	 */
	AlienArmy(GameManager *Game);

	/// Unit Getters

	/*
	 * Returns the Alien Soldier List
	 *
	 * @returns {LinkedQueue<AlienSoldier*>}
	 */
	LinkedQueue<AlienSoldier *> GetSoldiers() const;

	/*
	 * Returns the Alien Monsters List
	 *
	 * @returns {Bag<AlienMonsters*>}
	 */
	Bag<AlienMonsters *> GetMonsters() const;

	/*
	 * Returns the Alien Drones List
	 *
	 * @returns {Deque<AlienDrones*>}
	 */
	Deque<AlienDrones *> GetDrones() const;

	/// Unit Setters

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
	 * Adds a Monster to the bag of Monsters
	 *
	 * @param {double} Health - The Monster's health
	 * @param {int} Power - The Monster's power
	 * @param {int} AttackCapacity - The Monster's attack capacity
	 * @returns {bool} - If the add operation was successful
	 */
	bool AddMonster(double Health, int Power, int AttacCapacity);

	/*
	 * Adds a Drone to the Drone queue
	 *
	 * @param {double} Health - The Drone's health
	 * @param {int} Power - The Drone's power
	 * @param {int} AttackCapacity - The Drone's attack capacity
	 * @returns {bool} - If the add operation was successful
	 */
	bool AddDrone(double Health, int Power, int AttackCapacity);

	/// Unit Removers

	/*
	 * Removes a Soldier
	 *
	 * @param {ALienSoldier*&} RemovedSoldier - The removed soldier
	 * @returns {bool} - Whether the remove operation was a success or not
	 */
	bool RemoveSoldier(AlienSoldier*&RemovedSoldier);

	/*
	 * Removes a Monster
	 *
	 * @param {AlienMonsters*&} RemovedMonster - The removed monster
	 * @parma {const int&} index - The index to be removed
	 * @returns {bool} - Whether the remove operation was a success or not
	 */
	bool RemoveMonster(AlienMonsters *&RemovedMonster, const int& index);

	/*
	 * Removes a Drone
	 *
	 * @param {AlienDrones*&} RemovedDrone - The removed drone
	 * @returns {bool} - Whether the remove operation was a success or not
	 */
	bool RemoveDrone(AlienDrones *&RemovedDrone);

	/// Prints & Misc

	/*
	 * Prints all the data for the Alive Alien Units
	 *
	 * @param {void}
	 * @returns {void}
	 */
	void Print() const;

	bool isEmpty() const;

	bool CanAdd() const;

	/// To-Do: Phase 2
	// virtual void attack();

	/*
	 * Alien Army Destructor
	 */
	~AlienArmy();
};
#endif // !AlienArmy_H
