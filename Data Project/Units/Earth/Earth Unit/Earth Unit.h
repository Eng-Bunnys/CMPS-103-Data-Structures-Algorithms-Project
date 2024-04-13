#ifndef EarthUnit_H
#define EarthUnit_H

#include "../../Unit.h"

class EarthUnit : public Unit
{
public:
	/**
	 * Constructor for EarthUnit class
	 * @param {int} ID - The ID of the EarthUnit
	 * @param {double} Health - The health of the EarthUnit
	 * @param {int} Power - The power of the EarthUnit
	 * @param {int} AttackCapacity - The attack capacity of the EarthUnit
	 * @param {int} JoinTime - The join time of the EarthUnit
	 */
	EarthUnit(int ID, double Health, int Power, int AttackCapacity, int JoinTime);
};

#endif // !EarthUnit_H