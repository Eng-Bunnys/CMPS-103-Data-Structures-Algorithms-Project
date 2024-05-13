#ifndef EarthHealer_H
#define EarthHealer_H

#include "../../Earth Unit/Earth Unit.h"

class UnitMaintenanceList;
class EarthHealer : public EarthUnit
{
private:
	UnitMaintenanceList *UML;

public:
	EarthHealer(int ID, double Health, int Power, int AttackCapacity, int JoinTime);

	virtual void Attack(GameManager *Game, bool Interactive = true);
};

#endif // !EarthHealer_H
