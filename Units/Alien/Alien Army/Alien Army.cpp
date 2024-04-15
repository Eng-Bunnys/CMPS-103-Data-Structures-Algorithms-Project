#include "Alien Army.h"

AlienArmy::AlienArmy(GameManager *Game)
{
	this->AlienSoldierQueue = LinkedQueue<AlienSoldier *>();
	this->Monsters = Bag<AlienMonsters *>();
	this->Drones = Deque<AlienDrones *>();
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

Bag<AlienMonsters *> AlienArmy::GetMonsters() const
{
	return this->Monsters;
}

bool AlienArmy::AddMonster(double Health, int Power, int AttackCapacity)
{
	if (!CanAdd())
		return false;

	AlienMonsters *NewMonster = new AlienMonsters(++this->NextID, Health, Power, AttackCapacity, 0);

	if (Monsters.Add(NewMonster))
		return true;
	else
	{
		delete NewMonster;
		return false;
	}
}

bool AlienArmy::RemoveMonster(AlienMonsters *&RemovedMonster, const int &index)
{
	AlienMonsters *Removed = Monsters.Remove(index);

	if (Removed)
		return true;
	else
		return false;
}

/// Drones

Deque<AlienDrones *> AlienArmy::GetDrones() const
{
	return this->Drones;
}

bool AlienArmy::AddDrone(double Health, int Power, int AttackCapacity)
{
	if (!CanAdd())
		return false;

	AlienDrones *NewDrone = new AlienDrones(++this->NextID, Health, Power, AttackCapacity, 0);

	if (Drones.EnqueueBack(NewDrone))
		return true;
	else
	{
		delete NewDrone;
		return false;
	}
}

bool AlienArmy::RemoveDrone(AlienDrones *&RemovedDrone)
{
	if (Drones.DequeueFront(RemovedDrone))
		return true;
	else
		return false;
}

/// Other

void AlienArmy::Print() const
{
	std::cout << "============== Alien Army Alive Units ==============" << std::endl;
	if (this && !this->AlienSoldierQueue.isEmpty())
	{
		std::cout << AlienSoldierQueue.GetCount() << " AS ";
		this->AlienSoldierQueue.Print();
		std::cout << std::endl;
	}
	else
		std::cout << "0 AS []\n\n";

	if (!Monsters.isEmpty())
	{
		std::cout << Monsters.GetCount() << " AM ";
		Monsters.Print();
		std::cout << std::endl;
	}
	else
		std::cout << "0 Monsters []\n\n";

	if (!Drones.isEmpty())
	{
		std::cout << Drones.GetCount() << " AD ";
		Drones.Print();
		std::cout << std::endl;
	}
	else
		std::cout << "0 Drones []\n\n";
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

	AlienMonsters *TempMonster;
	int i = 0;
	while ((TempMonster = Monsters.Remove(i++)) != nullptr)
		delete TempMonster;

	AlienDrones *TempDrone;

	while (this->Drones.DequeueFront(TempDrone))
		delete TempDrone;
}
