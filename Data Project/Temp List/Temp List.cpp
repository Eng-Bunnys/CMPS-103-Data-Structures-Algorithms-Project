#pragma warning(push)
#pragma warning(disable : 26495)

#include "Temp List.h"

TempList::TempList() : Count(0){};

void TempList::AddEarthSoldier(EarthSoldier *Soldier)
{
	this->EarthSoldierList.enqueue(Soldier);
	this->Count++;
	this->EarthCount++;
	this->EarthSoldierCount++;
}

bool TempList::RemoveEarthSoldier(EarthSoldier *&Soldier)
{
	if (this->EarthSoldierList.isEmpty())
		return false;

	this->EarthSoldierList.dequeue(Soldier);
	this->Count--;
	this->EarthCount--;
	this->EarthSoldierCount--;
	return true;
}

void TempList::AddTank(EarthTank *Tank)
{
	this->EarthTankList.push(Tank);
	this->Count++;
	this->EarthCount++;
}

void TempList::RemoveTank(EarthTank *&Tank)
{
	if (this->EarthTankList.isEmpty())
		return;

	this->EarthTankList.pop(Tank);
	this->Count--;
	this->EarthCount--;
}

void TempList::AddGunnery(EarthGunnery *Gunnery)
{
	int GunneryPriority = 0;

	this->EarthGunneryList.enqueue(Gunnery, GunneryPriority);
	this->Count++;
	this->EarthCount++;
}

void TempList::RemoveGunnery(EarthGunnery *&Gunnery)
{
	if (this->EarthGunneryList.isEmpty())
		return;

	int GunneryPriority = 0;

	this->EarthGunneryList.dequeue(Gunnery, GunneryPriority);
	this->Count--;
	this->EarthCount--;
}

void TempList::AddAlienSoldier(AlienSoldier *Soldier)
{
	this->AlienSoldierList.enqueue(Soldier);
	this->Count++;
	this->AlienCount++;
	this->AlienSoldierCount++;
}

bool TempList::RemoveAlienSoldier(AlienSoldier*& Soldier) {
	if (this->AlienSoldierList.isEmpty()) {
		Soldier = nullptr; 
		return false;
	}

	this->AlienSoldierList.dequeue(Soldier);
	this->Count--;
	this->AlienCount--;
	this->AlienSoldierCount--;
	return true;
}

void TempList::AddDrone(AlienDrone *Drone)
{
	this->AlienDroneList.enqueue(Drone);
	this->Count++;
	this->AlienCount++;
}

void TempList::RemoveDrone(AlienDrone *&Drone)
{
	if (this->AlienDroneList.isEmpty())
		return;

	this->AlienDroneList.dequeue(Drone);
	this->Count--;
	this->AlienCount--;
}

void TempList::AddMonster(AlienMonster *Monster)
{
	this->AlienMonsterList.Add(Monster);
	this->Count++;
	this->AlienCount++;
}

void TempList::RemoveMonster(AlienMonster *&Monster)
{
	if (this->AlienMonsterList.isEmpty())
		return;

	this->AlienMonsterList.Remove(Monster);
	this->Count--;
	this->AlienCount--;
}

int TempList::GetCount() const
{
	return this->Count;
}

int TempList::GetEarthCount() const
{
	return this->EarthCount;
}

int TempList::GetAlienCount() const
{
	return this->AlienCount;
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
