#ifndef Unit_H
#define Unit_H

#include <iostream>
#include <fstream>
#include <string>

#include "Values.h"

class Unit
{
protected:
	/// Properties for all units
	/* Total number of deaths for the output file */
	static int NumberOfDeaths;
	/// Base properties for all units
	/* The unit's unique ID*/
	const int ID;
	/* The unit's attack capacity */
	int AttackCapacity;
	/* The unit's health */
	double Health;
	/* The unit's power */
	int Power;

	/// Time properties
	/* The timestep at which the unit joined the battle */
	int JoinTime;
	/* The total time the unit spends in battle */
	int BattleTime;
	/* The timestep when the unit gets destroyed / removed from battle */
	int DestructionTime;
	/* The timestep when the unit first got attacked */
	int FirstAttackedTime;

	/// Delay properties
	/* The time spent until a unit got hit by an enemy*/
	int FirstAttackedDelay;
	/* The time spent from the first attack from an enemy till removal / destruction */
	int DestructionDelay;

public:
	/**
	 * Constructor for Unit class
	 * @param {int} ID - The ID of the unit
	 * @param {double} Health - The health of the unit
	 * @param {int} Power - The power of the unit
	 * @param {int} AttackCapacity - The attack capacity of the unit
	 * @param {int} JoinTime - The join time of the unit
	 */
	Unit(int ID, double Health, int Power, int AttackCapacity, int JoinTime) : ID(ID), Health(Health), Power(Power), AttackCapacity(AttackCapacity), JoinTime(JoinTime) {}
	/// To-Do: Delete any Unit with ID -1 in GameManager / EarthArmy
	/// Getters & Setters

	/**
	 * Getter for retrieving the ID of the unit
	 * @returns {int} The ID of the unit
	 */
	int GetID() const;

	/**
	 * Getter for retrieving the health of the unit
	 * @returns {double} The health of the unit
	 */
	double GetHealth() const;

	/**
	 * Getter for retrieving the first attack delay of the unit
	 * @returns {int} The first attack delay of the unit
	 */
	int GetFirstAttackDelay() const;

	/**
	 * Getter for retrieving the destruction delay of the unit
	 * @returns {int} The destruction delay of the unit
	 */
	int GetDestructionDelay() const;

	/**
	 * Getter for retrieving the battle time of the unit
	 * @returns {int} The battle time of the unit
	 */
	int GetBattleTime() const;

	/**
	 * Static method for retrieving the death count of all units
	 * @returns {int} The total death count of all units
	 */
	static int GetDeathCount();

	/*
	 * Returns the unit's Power
	 */
	int GetPower() const;

	/*
	 * Returns the unit's Attack Capacity
	 */
	int GetAttackCapacity() const;

	/*
	 * Returns the unit's Join Time
	 */
	int GetJoinTime() const;

	/**
	 * Setter for updating the health of the unit
	 * @param {double} NewHealth - The new health value
	 */
	void SetHealth(double NewHealth);

	/**
	 * Setter for updating the destruction time of the unit
	 * @param {int} DestructionTime - The new destruction time value
	 */
	void SetDestructionTime(int DestructionTime);

	/**
	 * Setter for updating the first attacked time of the unit
	 * @param {int} FirstAttackedTime - The new first attacked time value
	 */
	void SetFirstAttackedTime(int FirstAttackedTime);
};

/// Operator overloading for the print functions

static std::ostream &operator<<(std::ostream &out, const Unit *unit)
{
	out << unit->GetID();
	return out;
}

#endif // !Unit_H