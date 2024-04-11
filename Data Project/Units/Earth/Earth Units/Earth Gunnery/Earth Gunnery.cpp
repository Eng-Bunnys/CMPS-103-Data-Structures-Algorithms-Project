#include "Earth Gunnery.h"

EarthGunnery::EarthGunnery(int ID, double Health, int Power, int AttackCapacity, int JoinTime)
	: EarthUnit(ID, Health, Power, AttackCapacity, JoinTime)
{
	this->HealthWeight = 0.4;
	this->PowerWeight = 0.6;
}

double EarthGunnery::GetPriority()
{
	return ((this->Health * this->HealthWeight) + ((this->Power * this->PowerWeight)));
}