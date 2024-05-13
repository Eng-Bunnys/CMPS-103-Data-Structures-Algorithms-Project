#include "Earth Healer.h"
#include "../../Unit Maintenance List/Unit Maintenance List.h"

EarthHealer::EarthHealer(int ID, double Health, int Power, int AttackCapacity, int JoinTime)
	: EarthUnit(ID, Health, Power, AttackCapacity, JoinTime),
	  UML(new UnitMaintenanceList())
{
}

void EarthHealer::Attack(GameManager* Game, bool Interactive)
{
}
