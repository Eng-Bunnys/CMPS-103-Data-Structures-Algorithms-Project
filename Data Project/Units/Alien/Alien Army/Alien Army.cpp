#include "Alien Army.h"

AlienArmy::AlienArmy(GameManager *Game)
{
	this->AlienSoldierQueue = LinkedQueue<AlienSoldier*>();
	this->Monsters = Bag<AlienMonsters*>();
	this->Drones = Deque<AlienDrones*>();
	this->NextID = 2000;
}

/// Soldiers

LinkedQueue<AlienSoldier *> AlienArmy::GetSoldiers() const
{
	return this->AlienSoldierQueue;
}

bool AlienArmy::AddSoldier(double Health, int Power, int AttackCapacity)
{
	AlienSoldier*NewSoldier = new AlienSoldier(++this->NextID, Health, Power, AttackCapacity, 0);

	if (this->AlienSoldierQueue.enqueue(NewSoldier))
		return true;
	else
		return false;
}

bool AlienArmy::RemoveSoldier(AlienSoldier*&RemovedSoldier)
{
	if (this->AlienSoldierQueue.dequeue(RemovedSoldier))
		return true;
	else
		return false;
}

/// Monsters

Bag<AlienMonsters *> AlienArmy::GetMonster() const
{
	return this->Monsters;
}

bool AlienArmy::AddMonster(double Health, int Power, int AttackCapacity)
{
	AlienMonsters *NewMonster = new AlienMonsters(++this->NextID, Health, Power, AttackCapacity, 0);

	if (Monsters.Add(NewMonster))
		return true;
	else
	{
		delete NewMonster;
		return false;
	}
}

bool AlienArmy::RemoveMonster(AlienMonsters *&RemovedMonster, const int& index)
{
	if (Monsters.Remove(RemovedMonster, index))
		return true;
	else
		return false;
}

/// Drones

Deque<AlienDrones *> AlienArmy::GetDrone() const
{
	return this->Drones;
}

bool AlienArmy::AddDrone(double Health, int Power, int AttackCapacity)
{
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
	}
	else
		std::cout << "0 AS []\n";

	if (!Monsters.isEmpty())
	{
		std::cout << Monsters.GetCount() << " AM ";
		Monsters.Print();
	}
	else
		std::cout << "0 Monsters []\n";

	if (!Drones.isEmpty())
	{
		std::cout << Drones.GetCount() << " AD ";
		Drones.Print();
	}
	else
		std::cout << "0 Drones []\n";
}

AlienArmy::~AlienArmy()
{
	AlienSoldier* TempSoldier;

	while (this->AlienSoldierQueue.dequeue(TempSoldier))
		delete TempSoldier;

	//AlienMonsters* TempMonster;
	//int i = 0;
	//while (this->Monsters.Remove(TempMonster, i++))
	//	delete TempMonster;

	AlienDrones* TempDrone;

	while (this->Drones.DequeueFront(TempDrone))
		delete TempDrone;
}
