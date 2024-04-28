#ifndef AlienMonsters_H
#define AlienMonsters_H

#include "../../Alien Unit/Alien Unit.h"

class AlienMonster : public AlienUnit
{
public:
    /**
     * Constructs an AlienMonster object
     *
     * @param ID The ID of the Monster
     * @param Health The health of the Monster
     * @param Power The power of the Monster
     * @param AttackCapacity The attack capacity of the Monster
     * @param JoinTime The time at which the Monster joined
     */
    AlienMonster(int ID, double Health, int Power, int AttackCapacity, int JoinTime);
};

#endif