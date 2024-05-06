#pragma warning(push)
#pragma warning(disable : 26495)

#include "Temp List.h"

/// To-Do: Complete count for the rest of the units, complete the rest of the functions

TempList::TempList() : EarthCount(0), AlienCount(0), EarthSoldierCount(0), AlienSoldierCount(0){};

bool TempList::AddEarthSoldier(EarthSoldier *Soldier)
{
	if (this->EarthSoldierList.enqueue(Soldier))
	{
		this->EarthCount++;
		this->EarthSoldierCount++;

		return true;
	}
	else
		return false;
}

bool TempList::RemoveEarthSoldier(EarthSoldier *&Soldier)
{
	if (this->EarthSoldierList.isEmpty())
		return false;

	if (this->EarthSoldierList.dequeue(Soldier))
	{
		this->EarthCount--;
		this->EarthSoldierCount--;
		return true;
	}
	else
		return false;
}

bool TempList::AddTank(EarthTank *Tank)
{
	if (this->EarthTankList.push(Tank))
	{
		this->EarthCount++;

		return true;
	}
	else
		return false;
}

bool TempList::RemoveTank(EarthTank *&Tank)
{
	if (this->EarthTankList.isEmpty())
		return false;

	if (this->EarthTankList.pop(Tank))
	{
		this->EarthCount--;
		return true;
	}
	else
		return false;
}

bool TempList::AddGunnery(EarthGunnery *Gunnery)
{
	int GunneryPriority = 0;

	if (this->EarthGunneryList.enqueue(Gunnery, GunneryPriority))
	{
		this->EarthCount++;
		return true;
	}
	else
		return false;
}

bool TempList::RemoveGunnery(EarthGunnery *&Gunnery)
{
	if (this->EarthGunneryList.isEmpty())
		return false;

	int GunneryPriority = 0;

	if (this->EarthGunneryList.dequeue(Gunnery, GunneryPriority))
	{
		this->EarthCount--;
		return true;
	}
	else
		return false;
}

bool TempList::AddAlienSoldier(AlienSoldier *Soldier)
{
	if (this->AlienSoldierList.enqueue(Soldier))
	{
		this->AlienCount++;
		this->AlienSoldierCount++;
		return true;
	}
	else
		return false;
}

bool TempList::RemoveAlienSoldier(AlienSoldier *&Soldier)
{
	if (this->AlienSoldierList.isEmpty())
	{
		Soldier = nullptr;
		return false;
	}

	if (this->AlienSoldierList.dequeue(Soldier))
	{
		this->AlienCount--;
		this->AlienSoldierCount--;
		return true;
	}
	else
		return false;
}

bool TempList::AddDrone(AlienDrone *Drone)
{
	if (this->AlienDroneList.enqueue(Drone))
	{
		this->AlienCount++;
		return true;
	}
	else
		return false;
}

bool TempList::RemoveDrone(AlienDrone *&Drone)
{
	if (this->AlienDroneList.isEmpty())
		return false;

	if (this->AlienDroneList.dequeue(Drone))
	{
		this->AlienCount--;
		return true;
	}
	else
		return false;
}

void TempList::AddMonster(AlienMonster *Monster)
{
	this->AlienMonsterList.Add(Monster);
	this->AlienCount++;
}

void TempList::RemoveMonster(AlienMonster *&Monster)
{
	if (this->AlienMonsterList.isEmpty())
		return;

	this->AlienMonsterList.Remove(Monster);
	this->AlienCount--;
}

int TempList::GetEarthCount() const
{
	return this->EarthCount;
}

int TempList::GetAlienCount() const
{
	return this->AlienCount;
}

int TempList::GetCount() const
{
	return this->AlienCount + this->EarthCount;
}

int TempList::GetAlienSoldierCount() const {
	return this->AlienSoldierCount;
}

TempList::~TempList()
{
	while (!this->EarthSoldierList.isEmpty())
	{
		EarthSoldier *TempSoldier = nullptr;
		this->EarthSoldierList.dequeue(TempSoldier);
		delete TempSoldier;
	}

	while (!this->EarthTankList.isEmpty())
	{
		EarthTank *TempTank = nullptr;
		this->EarthTankList.pop(TempTank);
		delete TempTank;
	}

	while (!this->EarthGunneryList.isEmpty())
	{
		EarthGunnery *TempGunnery = nullptr;
		int TempPriority = 0;
		this->EarthGunneryList.dequeue(TempGunnery, TempPriority);
		delete TempGunnery;
	}

	while (!this->AlienSoldierList.isEmpty())
	{
		AlienSoldier *TempSoldier = nullptr;
		this->AlienSoldierList.dequeue(TempSoldier);
		delete TempSoldier;
	}

	while (!this->AlienDroneList.isEmpty())
	{
		AlienDrone *TempDrone = nullptr;
		this->AlienDroneList.dequeue(TempDrone);
		delete TempDrone;
	}

	while (!this->AlienMonsterList.isEmpty())
	{
		AlienMonster *TempMonster = nullptr;
		this->AlienMonsterList.Remove(TempMonster);
		delete TempMonster;
	}
}
