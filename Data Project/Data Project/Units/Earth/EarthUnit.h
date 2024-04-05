<<<<<<< HEAD
#ifndef EarthUnit_H
#define EarthUnit_H

#include "../Unit.h"

/* The unit's max health */
const int MaxHealth = 100;

class EarthUnit : public Unit
{
public:
	EarthUnit(int ID, double Health, int Power, int AttackCapacity, int JoinTime)
		: Unit(ID, AttackCapacity, Health, Power, JoinTime) {};
};

=======
#ifndef EarthUnit_H
#define EarthUnit_H

#include "../Unit.h"

/* The unit's max health */
const int MaxHealth = 100;

class EarthUnit : public Unit
{
public:
	EarthUnit(int ID, double Health, int Power, int AttackCapacity, int JoinTime)
		: Unit(ID, AttackCapacity, Health, Power, JoinTime) {};
};

>>>>>>> 43323f7e475729d08a3e8eeecce40346c939c016
#endif // !EarthUnit_H