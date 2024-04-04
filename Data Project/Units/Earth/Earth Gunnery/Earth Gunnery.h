#ifndef EarthGunnery_H
#define EarthGunnery_H

#include "../EarthUnit.h"

class EarthGunnery : public EarthUnit
{
public:
	EarthGunnery(int ID, double Health, int Power, int AttackCapacity, int JoinTime)
		: EarthUnit(ID, Health, Power, AttackCapacity, JoinTime) {}

	double GetPriority() const {
		return this->Power * (this->Health / 100.0);, 
	}
};

#endif // !EarthGunnery_H