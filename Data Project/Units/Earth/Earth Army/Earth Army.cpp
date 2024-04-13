#include "Earth Army.h"

earthArmy::earthArmy() {}

earthArmy::earthArmy(GameManager* gameManager) {}


// ========================= Soldiers functions =========================




// ========================= Tanks functions =========================
ArrayStack<earthTank*> earthArmy::getTanksList() {
	return earthTanks;
}

bool earthArmy::addTank(int Power, double Health, int AttackCapacity) {

	///TODO: Replace the 0 with get join time function in game manager
	if (nextTankID < 999) {
		earthTank* tank = new earthTank(++nextTankID, AttackCapacity, 0, Power, Health);
		earthTanks.push(tank);
		ETcount++;
		return true;
	}
	return false;
}


bool earthArmy::removeTank(earthTank*& tank) {
	if (isET_Empty()) return false;
	else {
		earthTanks.pop(tank);
		ETcount--;
		return true;
	}
	return false;
}


bool earthArmy::isET_Empty() {
	if (ETcount == 0)return true;
	return false;
}

///TODO : change this to array since I used linked lists as stack 
//void earthArmy::printTanks() {
//	if (earthTanks.isEmpty()) {
//		std::cout << "No earth soldiers\n";
//		return;
//	}
//	std::cout << ETcount << " ET [";
//	Node<earthTank*>* current = earthTanks.getTop();
//	while (current->GetNext()) {
//		std::cout << current->GetValue()->getID() << ", ";
//		current = current->GetNext();
//	}
//	std::cout << current->GetValue()->getID();
//	std::cout << "]" << std::endl;
//}