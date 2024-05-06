#include "Earth Tank.h"
#include "../../Structures/Priority Queue/PriorityQueue.h"
#include "../../Game Manager/Game Manager.h"

EarthTank::EarthTank(int ID, double Health, int Power, int AttackCapacity, int JoinTime)
	: EarthUnit(ID, Health, Power, AttackCapacity, JoinTime) {}

void EarthTank::Attack(GameManager* Game, bool Interactive) {}