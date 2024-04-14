#include "Generator.h"

bool Generator::AssignGeneral(int UnitCount, int Probability)
{
	if (UnitCount > 0 && Probability > 0)
	{
		this->GenerationProbability = Probability;
		this->GenerationCount = UnitCount;

		return true;
	}
	else
		return false;
}

bool Generator::AssignEarth(int EarthSoldier, int EarthTank, int EarthGunnery, double Health[], int Power[], int AttackCapacity[])
{
	if (!ValidatePercentage(EarthSoldier) ||
		!ValidatePercentage(EarthTank) ||
		!ValidatePercentage(EarthGunnery))
		return false;

	if (!ValidateParamRange(Health[0], Health[1]) ||
		!ValidateParamRange(Power[0], Power[1]) ||
		!ValidateParamRange(AttackCapacity[0], AttackCapacity[1]))
		return false;

	this->EarthArmyParameters.MinHealth = Health[0];
	this->EarthArmyParameters.MaxHealth = Health[1];

	this->EarthArmyParameters.MinPower = Power[0];
	this->EarthArmyParameters.MaxPower = Power[1];

	this->EarthArmyParameters.MinAttackCapacity = AttackCapacity[0];
	this->EarthArmyParameters.MaxAttackCapacity = AttackCapacity[1];

	this->EarthSoldierPercentage = EarthSoldier;
	this->EarthTankPercentage = EarthTank;
	this->EarthGunneryPercentage = EarthGunnery;

	return true;
}

bool Generator::AssignAlien(int AlienSoldier, int AlienMonster, int AlienDrone, double Health[], int Power[], int AttackCapacity[])
{
	if (!ValidatePercentage(AlienSoldier) ||
		!ValidatePercentage(AlienMonster) ||
		!ValidatePercentage(AlienDrone))
		return false;

	if (!ValidateParamRange(Health[0], Health[1]) ||
		!ValidateParamRange(Power[0], Power[1]) ||
		!ValidateParamRange(AttackCapacity[0], AttackCapacity[1]))
		return false;

	this->AlienArmyParameters.MinHealth = Health[0];
	this->AlienArmyParameters.MaxHealth = Health[1];

	this->AlienArmyParameters.MinPower = Power[0];
	this->AlienArmyParameters.MaxPower = Power[1];

	this->AlienArmyParameters.MinAttackCapacity = AttackCapacity[0];
	this->AlienArmyParameters.MaxAttackCapacity = AttackCapacity[1];

	this->AlienSoldierPercentage = AlienSoldier;
	this->AlienMonsterPercentage = AlienMonster;
	this->AlienDronePercentage = AlienDrone;

	return true;
}

bool Generator::Generate()
{
	return true;
}