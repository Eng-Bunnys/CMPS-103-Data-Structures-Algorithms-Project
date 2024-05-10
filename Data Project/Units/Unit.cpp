#include "Unit.h"

#include <cmath>

int Unit::GetID() const
{
	return ID;
}

double Unit::GetHealth() const
{
	return this->Health;
}

void Unit::SetHealth(double NewHealth)
{
	this->Health = NewHealth > 100 ? 100 : NewHealth;
}

int Unit::GetFirstAttackDelay() const
{
	return this->FirstAttackedDelay;
}

int Unit::GetDestructionDelay() const
{
	return this->DestructionDelay;
}

int Unit::GetBattleTime() const
{
	return this->BattleTime;
}

int Unit::GetDeathCount()
{
	return NumberOfDeaths;
}

int Unit::GetPower() const
{
	return this->Power;
}

int Unit::GetAttackCapacity() const
{
	return this->AttackCapacity;
}

int Unit::GetJoinTime() const
{
	return this->JoinTime;
}

int Unit::GetFirstAttackedTime() const
{
	return this->FirstAttackedTime;
}

int Unit::GetTimeJoinedUML() const
{
	return timeJoinedUML;
}

bool Unit::GetUMLFlags() const
{
	return firstTimeInUML;
}

void Unit::SetDestructionTime(int DestructionTime)
{
	this->DestructionTime = DestructionTime;
	this->DestructionDelay = this->DestructionTime - this->FirstAttackedTime;
	this->BattleTime = this->DestructionTime - this->JoinTime;
	this->NumberOfDeaths++;
}

void Unit::SetFirstAttackedTime(int FirstAttackTime)
{
	this->FirstAttackedTime = FirstAttackTime;
	this->FirstAttackedDelay = this->FirstAttackedTime - this->JoinTime;
}

void Unit::SetTimeJoinedUML(int TimeJoinedUML)
{
	timeJoinedUML = TimeJoinedUML;
}

void Unit::SetUMLFlags(bool join) {
	firstTimeInUML = join;
}
double Unit::CalculateDamage(int AttackerPower, double AttackerHealth, double AttackedHealth)
{
	return (AttackerPower * (AttackedHealth / 100)) / sqrt(AttackedHealth);
}

// Setting the inital value of the number of deaths to 0
int Unit::NumberOfDeaths = 0;