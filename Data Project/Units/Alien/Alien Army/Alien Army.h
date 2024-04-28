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

/**
 * Represents the Alien Army in the game.
 */
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
	Bag<AlienMonster *> Monsters;
	/* A Double Ended Queue to store all of the Alien Drones */
	Deque<AlienDrone *> Drones;

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
	 * @returns {LinkedQueue<AlienSoldier*>} - The Alien Soldier List
	 */
	LinkedQueue<AlienSoldier *> GetSoldiers() const;

	/*
	 * Returns the Alien Monsters List
	 *
	 * @returns {Bag<AlienMonsters*>} - The Alien Monsters List
	 */
	Bag<AlienMonster *> GetMonsters() const;

	/*
	 * Returns the Alien Drones List
	 *
	 * @returns {Deque<AlienDrones*>} - The Alien Drones List
	 */
	Deque<AlienDrone *> GetDrones() const;

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
	bool AddMonster(double Health, int Power, int AttackCapacity);

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
	 * @param {AlienSoldier*&} RemovedSoldier - The removed soldier
	 * @returns {bool} - Whether the remove operation was a success or not
	 */
	bool RemoveSoldier(AlienSoldier *&RemovedSoldier);

	/*
	 * Removes a Monster
	 *
	 * @param {AlienMonsters*&} RemovedMonster - The removed monster
	 * @returns {bool} - Whether the remove operation was a success or not
	 */
	bool RemoveMonster(AlienMonster *&RemovedMonster);

	/*
	 * Removes a Drone
	 *
	 * @param {AlienDrones*&} RemovedDrone - The removed drone
	 * @returns {bool} - Whether the remove operation was a success or not
	 */
	bool RemoveDrone(AlienDrone *&RemovedDrone);

	/// Prints & Misc

	/*
	 * Prints all the data for the Alive Alien Units
	 *
	 * @param {void}
	 * @returns {void}
	 */
	void Print() const;

	/*
	 * Checks if the Alien Army is empty
	 *
	 * @returns {bool} - True if the Alien Army is empty, false otherwise
	 */
	bool isEmpty() const;

	/*
	 * Checks if units can be added to the Alien Army
	 *
	 * @returns {bool} - True if units can be added, false otherwise
	 */
	bool CanAdd() const;

	/*
	 * Alien Army Destructor
	 */
	~AlienArmy();
};

#endif // !AlienArmy_H