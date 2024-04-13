#ifndef EarthTank_H
#define EarthTank_H

#include "../../Earth Unit/Earth Unit.h"

class EarthTank : public EarthUnit
{
public:
    /**
     * Constructs an EarthTank object
     * @param ID The ID of the tank unit
     * @param Health The health of the tank unit
     * @param Power The power of the tank unit
     * @param AttackCapacity The attack capacity of the tank unit
     * @param JoinTime The time at which the tank unit joined
     */
    EarthTank(int ID, double Health, int Power, int AttackCapacity, int JoinTime);
};

#endif // !EarthTank_H
