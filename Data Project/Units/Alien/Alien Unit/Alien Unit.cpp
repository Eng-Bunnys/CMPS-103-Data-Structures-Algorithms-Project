#include "Alien Unit.h"

AlienUnit::AlienUnit(int ID, double Health, int Power, int AttackCapacity, int JoinTime)
	: Unit(ID, Health, Power, AttackCapacity, JoinTime)
{
	this->FirstAttackedTime = -1;
};