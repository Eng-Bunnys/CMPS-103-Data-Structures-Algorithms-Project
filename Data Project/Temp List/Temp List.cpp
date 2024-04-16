#include "Temp List.h"


TempList::TempList() : TempCount(0) {}

void TempList::AddESTemp(EarthSoldier* Soldier) {
	ES_TempList.enqueue(Soldier);
	TempCount++;
}

void TempList::RemoveESTemp(EarthSoldier*& Soldier) {
	if (ES_TempList.isEmpty()) {
		return;
	}
	else {
		ES_TempList.dequeue(Soldier);
		TempCount--;
	}

}

void TempList::AddETTemp(EarthTank* Tank) {
	ET_TempList.push(Tank);
	TempCount++;
}

void TempList::RemoveETTemp(EarthTank*& Tank) {
	if (ET_TempList.isEmpty()) {
		return;
	}
	else {
		ET_TempList.pop(Tank);
		TempCount--;
	}
}

void TempList::AddEGTemp(EarthGunnery* Gunnery, int p) {
	EG_TempList.enqueue(Gunnery, p);
}

void TempList::RemoveEGTemp(EarthGunnery*& Gunnery, int p) {
	if (EG_TempList.isEmpty()) {
		return;
	}
	else {
		EG_TempList.dequeue(Gunnery, p);
		TempCount--;
	}
}

void TempList::AddASTemp(AlienSoldier* Soldier) {
	AS_TempList.enqueue(Soldier);
	TempCount++;
}

void TempList::RemoveASTemp(AlienSoldier*& Soldier) {
	if (AS_TempList.isEmpty()) {
		return;
	}
	else {
		AS_TempList.dequeue(Soldier);
		TempCount--;
	}

}

void TempList::AddADTemp(AlienDrones* Drone) {
	AD_TempList.EnqueueBack(Drone);
}

void TempList::RemoveADTemp(AlienDrones*& Drone) {
	if (AD_TempList.isEmpty()) {
		return;
	}
	else {
		AD_TempList.DequeueFront(Drone);
		TempCount--;
	}
}

//void TempList::AddAMTemp(AlienMonsters* Monster) {
//	AM_TempList.Insert(Monster, ArrayInsertPositions::Back);
//}
//
//void TempList::RemoveAMTemp(AlienMonsters*& Monster) {
//	if (AM_TempList.isEmpty()) {
//		return;
//	}
//	else {
//		AM_TempList.Remove(Monster);
//		TempCount--;
//	}
//}

TempList::~TempList() {
	EarthGunnery* Temp;
	int FalsePriority;
	while (this->EG_TempList.dequeue(Temp, FalsePriority))
		delete Temp;
}