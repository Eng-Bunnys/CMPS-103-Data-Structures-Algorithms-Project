#ifndef AlienSoldier_H
#define AlienSoldier_H

#include "../../Alien Unit/Alien Unit.h"

class AlienSoldier : public AlienUnit
{
public:
    /**
     * Constructor for AlienSoldier class
     *
     * @param ID The ID of the AlienSoldier
     * @param Health The health of the AlienSoldier
     * @param Power The power of the AlienSoldier
     * @param AttackCapacity The attack capacity of the AlienSoldier
     * @param JoinTime The join time of the AlienSoldier
     */
    AlienSoldier(int ID, double Health, int Power, int AttackCapacity, int JoinTime);
};

#endif // !ALienSoldier_H