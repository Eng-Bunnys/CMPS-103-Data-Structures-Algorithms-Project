#pragma once
#include"../EarthUnit.h"


class EarthSoldiers :public EarthUnit
{
	const int ID;
	

public:
	EarthSoldiers(int Id, double Health, int Power, int AttackCapacity, int JoinTime)
		: EarthUnit(Id,Health, Power, AttackCapacity, JoinTime), ID(Id) {};

	int GetID() const {
		return ID;
	}


};



