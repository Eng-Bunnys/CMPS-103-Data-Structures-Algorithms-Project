#include "Earth Tanks.h"

earthTank::earthTank(int ID, int attackCap, int joinedTime, int p, double h)
	:earthUnit(id, attackCapacity, joinTime, power, health) , id(ID){
	this->health = h;
}

int earthTank::getID() {
	return this->id;
}

double earthTank::getHealth() {
	return this->health;
}

