#pragma warning(push)
#pragma warning(disable : 26495)

#include "Temp List.h"

#include <iostream>

/// To-Do: Create Get for each data member

TempList::TempList() : EarthCount(0),
					   AlienCount(0),
					   EarthSoldierCount(0),
					   AlienSoldierCount(0),
					   AlienMonsterCount(0),
					   AlienDroneCount(0)
{
	this->EarthSoldierList = new LinkedQueue<EarthSoldier *>;
	this->EarthTankList = new ArrayStack<EarthTank *>;
	this->EarthGunneryList = new PriorityQueue<EarthGunnery *>;
	this->AlienSoldierList = new LinkedQueue<AlienSoldier *>;
	this->AlienDroneList = new Deque<AlienDrone *>;
	this->AlienMonsterList = new Bag<AlienMonster *>;
	this->AlienMonsterAndDroneList = new PriorityQueue<AlienUnit *>;
	this->AlienMonsterAndSoldierList = new PriorityQueue<AlienUnit *>;
};

#pragma region TankAttack

bool TempList::AddTankAttack(AlienUnit *AttackedUnit, int Priority)
{
	if (this->AlienMonsterAndSoldierList->enqueue(AttackedUnit, Priority))
	{
		this->AlienCount++;

		if (Priority == 0)
			this->AlienSoldierCount++;
		else
			this->AlienMonsterCount++;

		return true;
	}
	else
		return false;
}

bool TempList::RemoveTankAttack(AlienUnit *&AttackedUnit, int &Priority)
{
	if (this->AlienMonsterAndSoldierList->dequeue(AttackedUnit, Priority))
	{
		this->AlienCount--;

		if (Priority == 0)
			this->AlienSoldierCount--;
		else
			this->AlienMonsterCount--;

		return true;
	}
	else
		return false;
}

void TempList::PrintTankAttack()
{
	this->AlienMonsterAndSoldierList->Print();
}

PriorityQueue<AlienUnit *> *TempList::GetTankAttack() const
{
	return this->AlienMonsterAndSoldierList;
}

#pragma endregion

#pragma region GunneryAttack

bool TempList::AddGunneryAttack(AlienUnit *AttackedUnit, int Priority)
{
	if (this->AlienMonsterAndDroneList->enqueue(AttackedUnit, Priority))
	{
		this->AlienCount++;

		if (Priority == 1)
			this->AlienDroneCount++;
		else
			this->AlienMonsterCount++;

		return true;
	}
	else
		return false;
}

bool TempList::RemoveGunneryAttack(AlienUnit *&AttackedUnit, int &Priority)
{
	if (this->AlienMonsterAndDroneList->dequeue(AttackedUnit, Priority))
	{
		this->AlienCount--;

		if (Priority == 1)
			this->AlienDroneCount--;
		else
			this->AlienMonsterCount--;

		return true;
	}
	else
		return false;
}

void TempList::PrintGunneryAttack()
{
	this->AlienMonsterAndDroneList->Print();
}

PriorityQueue<AlienUnit *> *TempList::GetGunneryAttack() const
{
	return this->AlienMonsterAndDroneList;
}

#pragma endregion

#pragma region EarthSoldier

bool TempList::AddEarthSoldier(EarthSoldier *Soldier)
{
	if (this->EarthSoldierList->enqueue(Soldier))
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
	if (this->EarthSoldierList->isEmpty())
		return false;

	if (this->EarthSoldierList->dequeue(Soldier))
	{
		this->EarthCount--;
		this->EarthSoldierCount--;
		return true;
	}
	else
		return false;
}

LinkedQueue<EarthSoldier *> *TempList::GetEarthSoldiers() const
{
	return this->EarthSoldierList;
}

#pragma endregion

bool TempList::AddTank(EarthTank *Tank)
{
	if (this->EarthTankList->push(Tank))
	{
		this->EarthCount++;

		return true;
	}
	else
		return false;
}

bool TempList::RemoveTank(EarthTank *&Tank)
{
	if (this->EarthTankList->isEmpty())
		return false;

	if (this->EarthTankList->pop(Tank))
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

	if (this->EarthGunneryList->enqueue(Gunnery, GunneryPriority))
	{
		this->EarthCount++;
		return true;
	}
	else
		return false;
}

bool TempList::RemoveGunnery(EarthGunnery *&Gunnery)
{
	if (this->EarthGunneryList->isEmpty())
		return false;

	int GunneryPriority = 0;

	if (this->EarthGunneryList->dequeue(Gunnery, GunneryPriority))
	{
		this->EarthCount--;
		return true;
	}
	else
		return false;
}

#pragma region AlienSoldier

bool TempList::AddAlienSoldier(AlienSoldier *Soldier)
{
	if (this->AlienSoldierList->enqueue(Soldier))
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
	if (this->AlienSoldierList->isEmpty())
	{
		Soldier = nullptr;
		return false;
	}

	if (this->AlienSoldierList->dequeue(Soldier))
	{
		this->AlienCount--;
		this->AlienSoldierCount--;
		return true;
	}
	else
		return false;
}

void TempList::PrintAlienSoldier()
{
	this->AlienSoldierList->Print();
}

LinkedQueue<AlienSoldier *> *TempList::GetAlienSoldiers() const
{
	return this->AlienSoldierList;
}

#pragma endregion

bool TempList::AddDrone(AlienDrone *Drone)
{
	if (this->AlienDroneList->enqueue(Drone))
	{
		this->AlienDroneCount++;
		this->AlienCount++;
		return true;
	}
	else
		return false;
}

bool TempList::RemoveDrone(AlienDrone *&Drone)
{
	if (this->AlienDroneList->isEmpty())
		return false;

	if (this->AlienDroneList->dequeue(Drone))
	{
		this->AlienCount--;
		this->AlienDroneCount--;
		return true;
	}
	else
		return false;
}

void TempList::PrintAlienDrones()
{
	this->AlienDroneList->Print();
}

bool TempList::AddMonster(AlienMonster *Monster)
{
	if (this->AlienMonsterList->Add(Monster))
	{
		this->AlienCount++;
		this->AlienMonsterCount++;

		return true;
	}
	else
		return false;
}

bool TempList::RemoveMonster(AlienMonster *&Monster)
{
	if (this->AlienMonsterList->isEmpty())
		return false;

	if (this->AlienMonsterList->Remove(Monster))
	{
		this->AlienCount--;
		this->AlienMonsterCount--;

		return true;
	}
	else
		return false;
}

void TempList::PrintAlienMonsters()
{
	this->AlienMonsterList->Print();
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

int TempList::GetAlienSoldierCount() const
{
	return this->AlienSoldierCount;
}

int TempList::GetAlienMonsterCount() const
{
	return this->AlienMonsterCount;
}

int TempList::GetAlienDroneCount() const
{
	return this->AlienDroneCount;
}

TempList::~TempList()
{
	while (!this->EarthSoldierList->isEmpty())
	{
		EarthSoldier *TempSoldier = nullptr;
		this->EarthSoldierList->dequeue(TempSoldier);
		delete TempSoldier;
	}

	while (!this->EarthTankList->isEmpty())
	{
		EarthTank *TempTank = nullptr;
		this->EarthTankList->pop(TempTank);
		delete TempTank;
	}

	while (!this->EarthGunneryList->isEmpty())
	{
		EarthGunnery *TempGunnery = nullptr;
		int TempPriority = 0;
		this->EarthGunneryList->dequeue(TempGunnery, TempPriority);
		delete TempGunnery;
	}

	while (!this->AlienSoldierList->isEmpty())
	{
		AlienSoldier *TempSoldier = nullptr;
		this->AlienSoldierList->dequeue(TempSoldier);
		delete TempSoldier;
	}

	while (!this->AlienDroneList->isEmpty())
	{
		AlienDrone *TempDrone = nullptr;
		this->AlienDroneList->dequeue(TempDrone);
		delete TempDrone;
	}

	while (!this->AlienMonsterList->isEmpty())
	{
		AlienMonster *TempMonster = nullptr;
		this->AlienMonsterList->Remove(TempMonster);
		delete TempMonster;
	}
}
