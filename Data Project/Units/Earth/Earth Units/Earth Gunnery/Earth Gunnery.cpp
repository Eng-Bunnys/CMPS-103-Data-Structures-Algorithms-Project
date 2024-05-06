#include "Earth Gunnery.h"

#include "../../Game Manager/Game Manager.h"

#include "../../Structures/Deque/Deque.h"
#include "../../Units/Alien/Alien Units/Alien Drones/Alien Drones.h"
#include "../../Units/Alien/Alien Units/Alien Monsters/Alien Monsters.h"

EarthGunnery::EarthGunnery(int ID, double Health, int Power, int AttackCapacity, int JoinTime)
	: EarthUnit(ID, Health, Power, AttackCapacity, JoinTime)
{
	this->HealthWeight = 0.4;
	this->PowerWeight = 0.6;
}

double EarthGunnery::GetPriority() const
{
	return ((this->Health * this->HealthWeight) + ((this->Power * this->PowerWeight)));
}

void EarthGunnery::Attack(GameManager* Game, bool Interactive) {

}