#ifndef AlienDrones_H
#define AlienDrones_H

#include "../../Alien Unit/Alien Unit.h"

class AlienDrone : public AlienUnit
{
public:
	/**
	 * Constructor for AlienDrones class
	 *
	 * @param {int} ID - The ID of the AlienDrones
	 * @param {double} Health - The health of the AlienDrones
	 * @param {int} Power - The power of the AlienDrones
	 * @param {int} AttackCapacity - The attack capacity of the AlienDrones
	 * @param {int} JoinTime - The join time of the AlienDrones
	 */
	AlienDrone(int ID, double Health, int Power, int AttackCapacity, int JoinTime);
};

#endif