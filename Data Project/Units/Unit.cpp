#include"unit.h"

unit::unit(int ID) : id(ID) {}

unit::unit(int ID, int attCap, int jt, int bTime, int p, double h) : id(ID) {

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

int unit::getBattleTime() { return battleTime; }

void unit::print() {
	std::cout << "\nID of tank = " << getID();
	std::cout << "\nMaximum attack capacity of unit = " << getAttackCapacity();
	std::cout << "\nJoin time of unit = " << getJoinTime() ;
	std::cout << "\n Battle time of uniy= " << getBattleTime();
	std::cout << "\nPower of unit = " << getPower();
	std::cout << "Health of unit = " << getHealth() << std::endl;

}



