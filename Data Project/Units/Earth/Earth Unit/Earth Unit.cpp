#include "Earth Unit.h"

EarthUnit::EarthUnit(int ID, double Health, int Power, int AttackCapacity, int JoinTime)
	: Unit(ID, Health, Power, AttackCapacity, JoinTime)
{
	this->FirstAttackedTime = -1;
}