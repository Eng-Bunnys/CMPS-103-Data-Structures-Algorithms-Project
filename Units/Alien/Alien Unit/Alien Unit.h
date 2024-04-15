#ifndef AlienUnit_H
#define AlienUnit_H

#include "../../Unit.h"

class EarthArmy;
class AlienUnit : public Unit
{
public:
    /**
     * Constructs an AlienUnit object.
     * @param ID The ID of the unit.
     * @param Health The health of the unit.
     * @param Power The power of the unit.
     * @param AttackCapacity The attack capacity of the unit.
     * @param JoinTime The time at which the unit joined.
     */
    AlienUnit(int ID, double Health, int Power, int AttackCapacity, int JoinTime);
    /// Phase 2
    // virtual void attack(...) = 0;
};

#endif // !AlienUnit_H
