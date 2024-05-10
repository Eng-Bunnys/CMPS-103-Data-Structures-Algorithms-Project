#pragma once
#include"../../Earth Unit/Earth Unit.h" // Include for Earth Unit
#include"../../Game Manager/Game Manager.h" // Include for Game Manager

class HealUnit : public EarthUnit
{
public:
	/**
	 * Constructor for the healUnit class.
	 * @param ID int - The ID of the heal unit.
	 * @param attackCap int - The attack capacity of the heal unit.
	 * @param joinedTime int - The time when the heal unit joined.
	 * @param power int - The power of the heal unit.
	 * @param health double - The health of the heal unit.
	 */
	HealUnit(int ID, int attackCap, int joinedTime, int power, double health);

	/**
	 * Method to perform attack by the heal unit.
	 * @param game GameManager* - Pointer to the game manager.
	 */
	void Attack(GameManager* game);
};
