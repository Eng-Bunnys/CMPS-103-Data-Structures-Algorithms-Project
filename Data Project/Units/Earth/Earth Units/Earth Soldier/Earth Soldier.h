#ifndef EarthSoldier_H
#define EarthSoldier_H

#include "../../Earth Unit/Earth Unit.h"

class EarthSoldier : public EarthUnit
{
public:
    /**
     * Constructor for EarthSoldier class
     * @param ID The ID of the EarthSoldier
     * @param Health The health of the EarthSoldier
     * @param Power The power of the EarthSoldier
     * @param AttackCapacity The attack capacity of the EarthSoldier
     * @param JoinTime The join time of the EarthSoldier
     */
    EarthSoldier(int ID, double Health, int Power, int AttackCapacity, int JoinTime);

    virtual void Attack(GameManager *Game, bool Interactive = true);
};

#endif // !EarthSoldier_H
