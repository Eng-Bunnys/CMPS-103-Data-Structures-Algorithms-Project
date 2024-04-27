#pragma warning(push)
#pragma warning(disable: 26495)

#include "Temp List.h"

TempList::TempList() : Count(0) {};

void TempList::AddEarthSoldier(EarthSoldier* Soldier) {
	this->EarthSoldierList.enqueue(Soldier);
	this->Count++;
}

void TempList::RemoveEarthSoldier(EarthSoldier*& Soldier) {
	if (this->EarthSoldierList.isEmpty())
		return;

	this->EarthSoldierList.dequeue(Soldier);
	this->Count--;
}

void TempList::AddTank(EarthTank* Tank) {
	this->EarthTankList.push(Tank);
	this->Count++;
}

void TempList::RemoveTank(EarthTank*& Tank) {
	if (this->EarthTankList.isEmpty())
		return;

	this->EarthTankList.pop(Tank);
	this->Count--;
}

void TempList::AddGunnery(EarthGunnery* Gunnery) {
	int GunneryPriority = 0;

	this->EarthGunneryList.enqueue(Gunnery, GunneryPriority);
	this->Count++;
}

void TempList::RemoveGunnery(EarthGunnery*& Gunnery) {
	if (this->EarthGunneryList.isEmpty())
		return;

	int GunneryPriority = 0;

	this->EarthGunneryList.dequeue(Gunnery, GunneryPriority);
	this->Count++;
}

void TempList::AddAlienSoldier(AlienSoldier* Soldier) {
	this->AlienSoldierList.enqueue(Soldier);
	this->Count++;
}

void TempList::RemoveAlienSoldier(AlienSoldier*& Soldier) {
	if (this->AlienSoldierList.isEmpty())
		return;

	this->AlienSoldierList.dequeue(Soldier);
	this->Count--;
}

void TempList::AddDrone(AlienDrone* Drone) {
	this->AlienDroneList.enqueue(Drone);
	this->Count++;
}

void TempList::RemoveDrone(AlienDrone*& Drone) {
	if (this->AlienDroneList.isEmpty())
		return;

	this->AlienDroneList.dequeue(Drone);
	this->Count--;
}

void TempList::AddMonster(AlienMonster* Monster) {
	this->AlienMonsterList.Add(Monster);
	this->Count++;
}

void TempList::RemoveMonster(AlienMonster*& Monster) {
	if (this->AlienMonsterList.isEmpty())
		return;

	this->AlienMonsterList.Remove(Monster);
	this->Count--;
}

int TempList::GetCount() const {
	return this->Count;
}

TempList::~TempList() {
	while (!this->EarthSoldierList.isEmpty()) {
		EarthSoldier* TempSoldier = nullptr;
		this->EarthSoldierList.dequeue(TempSoldier);
		delete TempSoldier;
	}

	while (!this->EarthTankList.isEmpty()) {
		EarthTank* TempTank = nullptr;
		this->EarthTankList.pop(TempTank);
		delete TempTank; 
	}

	while (!this->EarthGunneryList.isEmpty()) {
		EarthGunnery* TempGunnery = nullptr;
		int TempPriority = 0; 
		this->EarthGunneryList.dequeue(TempGunnery, TempPriority);
		delete TempGunnery; 
	}

	while (!this->AlienSoldierList.isEmpty()) {
		AlienSoldier* TempSoldier = nullptr;
		this->AlienSoldierList.dequeue(TempSoldier);
		delete TempSoldier;
	}

	while (!this->AlienDroneList.isEmpty()) {
		AlienDrone* TempDrone = nullptr;
		this->AlienDroneList.dequeue(TempDrone);
		delete TempDrone; 
	}

	while (!this->AlienMonsterList.isEmpty()) {
		AlienMonster* TempMonster = nullptr;
		this->AlienMonsterList.Remove(TempMonster);
		delete TempMonster; 
	}
}
