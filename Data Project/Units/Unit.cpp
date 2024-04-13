#include"Unit.h"

unit::unit(int ID) : id(ID) {}

unit::unit(int ID, int attCap, int jt, int p, double h) : id(ID) {

	health = h;
	power = p;
	attackCapacity = attCap;
	joinTime = jt;
}

void unit::setPower(int p) { power = p; }

void unit::setHealth(double h) { health = h > 100 ? 100 : h; }

void unit::setAttackCapacity(int cap) { attackCapacity = cap; }

void unit::setJoinTime(int jt) { joinTime = jt; }

void unit::setType(std::string t) { type = t; };

int unit::getPower() const { return power; };

double unit::getHealth() const { return health; };

int unit::getAttackCapacity() const { return attackCapacity; };

int unit::getJoinTime() const { return joinTime; };

std::string unit::getType() const { return type; };

const int unit::getID() const { return id; };

void unit::print() {
	std::cout << "Health of unit = " << getHealth();
	std::cout << "\nPower of unit = " << getPower();
	std::cout << "\nMaximum attack capacity of unit = " << getAttackCapacity();
	std::cout << "\nID of tank = " << getID();
	std::cout << "\nJoin time of unit = " << getJoinTime() << std::endl;
}




