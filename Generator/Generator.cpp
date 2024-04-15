#include "Generator.h"
#include "../Game Manager/Game Manager.h"
#include "../../Utils/Utils.h"

Generator::Generator(GameManager *Game)
{
	this->Game = Game;
}

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

UnitStats Generator::GenerateStats(double MinHealth, double MaxHealth, int MinPower, int MaxPower, int MinAttackCapacity, int MaxAttackCapacity)
{
	UnitStats Generated;

	Generated.Health = Utils::GenerateRandomNumber(MinHealth, MaxHealth);
	Generated.Power = Utils::GenerateRandomNumber(MinPower, MaxPower);
	Generated.AttackCapacity = Utils::GenerateRandomNumber(MinAttackCapacity, MaxAttackCapacity);

	return Generated;
}

void Generator::GenerateEarth(int RandomNumber)
{
	if (RandomNumber <= this->GenerationProbability)
	{
		int Generated;

		int Sum = 0;

		for (int i = 0; i < this->GenerationCount; i++)
		{
			Generated = Utils::GenerateRandomNumber();

			if (Generated <= this->EarthSoldierPercentage)
			{
				UnitStats GeneratedSoldier = GenerateStats(this->EarthArmyParameters.MinHealth, this->EarthArmyParameters.MaxHealth, this->EarthArmyParameters.MinPower, this->EarthArmyParameters.MaxPower, this->EarthArmyParameters.MinAttackCapacity, this->EarthArmyParameters.MaxAttackCapacity);

				Sum += this->EarthSoldierPercentage;

				this->Game->GetEarthArmy()->AddSoldier(GeneratedSoldier.Health, GeneratedSoldier.Power, GeneratedSoldier.AttackCapacity);
			}

			else if (Generated <= Sum + this->EarthTankPercentage)
			{
				UnitStats GeneratedTank = GenerateStats(this->EarthArmyParameters.MinHealth, this->EarthArmyParameters.MaxHealth, this->EarthArmyParameters.MinPower, this->EarthArmyParameters.MaxPower, this->EarthArmyParameters.MinAttackCapacity, this->EarthArmyParameters.MaxAttackCapacity);

				Sum += this->EarthTankPercentage;

				this->Game->GetEarthArmy()->AddTank(GeneratedTank.Health, GeneratedTank.Power, GeneratedTank.AttackCapacity);
			}

			else if (Generated <= Sum + this->EarthGunneryPercentage)
			{
				UnitStats GeneratedGunnery = GenerateStats(this->EarthArmyParameters.MinHealth, this->EarthArmyParameters.MaxHealth, this->EarthArmyParameters.MinPower, this->EarthArmyParameters.MaxPower, this->EarthArmyParameters.MinAttackCapacity, this->EarthArmyParameters.MaxAttackCapacity);

				Sum += this->EarthGunneryPercentage;

				this->Game->GetEarthArmy()->AddTank(GeneratedGunnery.Health, GeneratedGunnery.Power, GeneratedGunnery.AttackCapacity);
			}
		}
	}
}

void Generator::GenerateAlien(int RandomNumber)
{
	if (RandomNumber <= this->GenerationProbability)
	{
		int Generated;

		int Sum = 0;

		for (int i = 0; i < this->GenerationCount; i++)
		{
			Generated = Utils::GenerateRandomNumber();

			if (Generated <= this->AlienSoldierPercentage)
			{
				UnitStats GeneratedSoldier = GenerateStats(this->AlienArmyParameters.MinHealth, this->AlienArmyParameters.MaxHealth, this->AlienArmyParameters.MinPower, this->AlienArmyParameters.MaxPower, this->AlienArmyParameters.MinAttackCapacity, this->AlienArmyParameters.MaxAttackCapacity);

				Sum += this->AlienSoldierPercentage;

				this->Game->GetAlienArmy()->AddSoldier(GeneratedSoldier.Health, GeneratedSoldier.Power, GeneratedSoldier.AttackCapacity);
			}

			else if (Generated <= Sum + this->AlienMonsterPercentage)
			{
				UnitStats GeneratedTank = GenerateStats(this->AlienArmyParameters.MinHealth, this->AlienArmyParameters.MaxHealth, this->AlienArmyParameters.MinPower, this->AlienArmyParameters.MaxPower, this->AlienArmyParameters.MinAttackCapacity, this->AlienArmyParameters.MaxAttackCapacity);

				Sum += this->AlienMonsterPercentage;

				this->Game->GetAlienArmy()->AddMonster(GeneratedTank.Health, GeneratedTank.Power, GeneratedTank.AttackCapacity);
			}

			else if (Generated <= Sum + this->AlienDronePercentage)
			{
				UnitStats GeneratedGunnery = GenerateStats(this->AlienArmyParameters.MinHealth, this->AlienArmyParameters.MaxHealth, this->AlienArmyParameters.MinPower, this->AlienArmyParameters.MaxPower, this->AlienArmyParameters.MinAttackCapacity, this->AlienArmyParameters.MaxAttackCapacity);

				Sum += this->AlienDronePercentage;

				this->Game->GetAlienArmy()->AddDrone(GeneratedGunnery.Health, GeneratedGunnery.Power, GeneratedGunnery.AttackCapacity);
			}
		}
	}
}

void Generator::Generate()
{
	int RandomNumberEarth = Utils::GenerateRandomNumber();
	int RandomNumberAlien = Utils::GenerateRandomNumber();

	GenerateEarth(RandomNumberEarth);
	GenerateAlien(RandomNumberAlien);
}