#include "Alien Army.h"

AlienArmy::AlienArmy(GameManager *Game)
{
	this->AlienSoldierQueue = LinkedQueue<AlienSoldier *>();
	this->Monsters = Bag<AlienMonster *>();
	this->Drones = Deque<AlienDrone *>();
	this->NextID = 2000;
}

/// Soldiers

LinkedQueue<AlienSoldier *> AlienArmy::GetSoldiers() const
{
	return this->AlienSoldierQueue;
}

bool AlienArmy::AddSoldier(double Health, int Power, int AttackCapacity)
{
	if (!CanAdd())
		return false;

	AlienSoldier *NewSoldier = new AlienSoldier(++this->NextID, Health, Power, AttackCapacity, 0);

	if (this->AlienSoldierQueue.enqueue(NewSoldier))
		return true;
	else
		return false;
}

bool AlienArmy::RemoveSoldier(AlienSoldier *&RemovedSoldier)
{
	if (this->AlienSoldierQueue.dequeue(RemovedSoldier))
		return true;
	else
		return false;
}

/// Monsters

Bag<AlienMonster *> AlienArmy::GetMonsters() const
{
	return this->Monsters;
}

bool AlienArmy::AddMonster(double Health, int Power, int AttackCapacity)
{
	if (!CanAdd())
		return false;

	AlienMonster *NewMonster = new AlienMonster(++this->NextID, Health, Power, AttackCapacity, 0);

	if (Monsters.Add(NewMonster))
		return true;
	else
	{
		delete NewMonster;
		return false;
	}
}

bool AlienArmy::RemoveMonster(AlienMonster *&RemovedMonster)
{
	Monsters.Remove(RemovedMonster);

	if (RemovedMonster)
		return true;
	else
		return false;
}

/// Drones

Deque<AlienDrone *> AlienArmy::GetDrones() const
{
	return this->Drones;
}

bool AlienArmy::AddDrone(double Health, int Power, int AttackCapacity)
{
	if (!CanAdd())
		return false;

	AlienDrone *NewDrone = new AlienDrone(++this->NextID, Health, Power, AttackCapacity, 0);

	if (Drones.EnqueueBack(NewDrone))
		return true;
	else
	{
		delete NewDrone;
		return false;
	}
}

bool AlienArmy::RemoveDrone(AlienDrone *&RemovedDrone)
{
	/*if (Drones.DequeueFront(RemovedDrone))
		return true;
	else
		return false;*/
	if (Drones.isEmpty())
		return false;
	if (Drones.GetCount() % 2 == 0)
	{
		Drones.DequeueFront(RemovedDrone);
	}
	else
	{
		Drones.DequeueBack(RemovedDrone);
	}
	return true;
}

/// Other

void AlienArmy::Print() const
{
	if (!this->AlienSoldierQueue.isEmpty())
	{
		std::cout << AlienSoldierQueue.GetCount() << " AS ";
		this->AlienSoldierQueue.Print();
		std::cout << std::endl;
	}
	else
		std::cout << "0 AS []" << std::endl;

	if (!Monsters.isEmpty())
	{
		std::cout << Monsters.GetCount() << " AM ";
		Monsters.Print();
		std::cout << std::endl;
	}
	else
		std::cout << "0 AM []" << std::endl;

	if (!Drones.isEmpty())
	{
		std::cout << Drones.GetCount() << " AD ";
		Drones.Print();
		std::cout << std::endl;
	}
	else
		std::cout << "0 AD []" << std::endl;
}

bool AlienArmy::isEmpty() const
{
	return (this->AlienSoldierQueue.isEmpty() && this->Drones.isEmpty() && this->Monsters.isEmpty());
}

bool AlienArmy::CanAdd() const
{
	return ((this->NextID + 1) >= AlienUnitMinID && (this->NextID + 1) <= AlienUnitMaxID);
}

AlienArmy::~AlienArmy()
{
	AlienSoldier *TempSoldier;

	while (this->AlienSoldierQueue.dequeue(TempSoldier))
		delete TempSoldier;

	AlienMonster *TempMonster;
	while (this->Monsters.Remove(TempMonster))
		delete TempMonster;

	AlienDrone *TempDrone;

	while (this->Drones.DequeueFront(TempDrone))
		delete TempDrone;
}
