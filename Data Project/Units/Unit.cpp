#include "Unit.h"

int Unit::GetID() const {
	return this->ID;
}

double Unit::GetHealth() const {
	return this->Health;
}

int Unit::GetFirstAttackDelay() const {
	return this->FirstAttackedDelay;
}

int Unit::GetDestructionDelay() const {
	return this->DestructionDelay;
}

int Unit::GetBattleTime() const {
	return this->BattleTime;
}

int Unit::GetDeathCount() {
	return NumberOfDeaths;
}

void Unit::SetDestructionTime(int DestructionTime) {
	this->DestructionTime = DestructionTime;
	this->DestructionDelay = this->DestructionTime - this->FirstAttackedTime;
	this->BattleTime = this->DestructionTime - this->JoinTime;
	this->NumberOfDeaths++;
}

void Unit::SetFirstAttackedTime(int FirstAttackTime) {
	this->FirstAttackedTime = FirstAttackTime;
	this->FirstAttackedDelay = this->FirstAttackedTime - this->JoinTime;
}

// Setting the inital value of the number of deaths to 0
int Unit::NumberOfDeaths = 0;