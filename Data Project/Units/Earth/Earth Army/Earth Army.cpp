#include "Earth Army.h"

EarthArmy::EarthArmy(GameManager *Game)
{
	this->Gunnery = PriorityQueue<EarthGunnery *>();
	this->NextID = 1;
}

/// Soldiers

LinkedQueue<EarthSoldier *> EarthArmy::GetSoldiers() const
{
	return this->Soldiers;
}

bool EarthArmy::AddSoldier(double Health, int Power, int AttackCapacity)
{
	EarthSoldier *NewSoldier = new EarthSoldier(++this->NextID, Health, Power, AttackCapacity, 0);

	if (this->Soldiers.enqueue(NewSoldier))
		return true;
	else
		return false;
}

bool EarthArmy::RemoveSoldier(EarthSoldier *&RemovedSoldier)
{
	if (this->Soldiers.dequeue(RemovedSoldier))
		return true;
	else
		return false;
}

/// Gunnery

PriorityQueue<EarthGunnery *> EarthArmy::GetGunnery() const
{
	return this->Gunnery;
}

bool EarthArmy::AddGunnery(double Health, int Power, int AttackCapacity)
{
	/// To-Do: Complete game manager and add a GetTimeStep function & replace it in the last parameter
	/// To-Do: Check if the ID is negative 1, if so then don't add
	EarthGunnery *NewGunnery = new EarthGunnery(++this->NextID, Health, Power, AttackCapacity, 0);
	if (this->Gunnery.enqueue(NewGunnery, NewGunnery->GetPriority()))
		return true;
	else
		return false;
}

bool EarthArmy::RemoveGunnery(EarthGunnery *&RemovedGunnery)
{
	int Priority;

	if (this->Gunnery.dequeue(RemovedGunnery, Priority))
		return true;

	else
		return false;
}

/// Tank

ArrayStack<EarthTank *> EarthArmy::GetTanks() const
{
	return this->Tanks;
}

bool EarthArmy::AddTank(double Health, int Power, int AttackCapacity)
{
	EarthTank *NewTank = new EarthTank(++this->NextID, Health, Power, AttackCapacity, 0);

	if (this->Tanks.push(NewTank))
		return true;
	else
		return false;
}

bool EarthArmy::RemoveTank(EarthTank *&RemovedTank)
{
	if (this->Tanks.pop(RemovedTank))
		return true;
	else
		return false;
}

/// Other

void EarthArmy::Print() const
{
	std::cout << "============== Earth Army Alive Units ==============" << std::endl;
	if (this && !this->Soldiers.isEmpty())
	{
		std::cout << this->Soldiers.GetCount() << " ES ";
		this->Soldiers.Print();
	}
	else
		std::cout << "0 ES []\n";

	if (this && !this->Tanks.isEmpty())
	{
		std::cout << this->Tanks.GetCount() << " ET ";
		this->Tanks.Print();
	}
	else
		std::cout << "0 ET []\n";

	if (this && !this->Gunnery.isEmpty())
	{
		std::cout << this->Gunnery.GetCount() << " EG ";
		this->Gunnery.Print();
	} else
		std::cout << "0 EG []\n";
}

EarthArmy::~EarthArmy()
{
	EarthGunnery *Temp;
	int FalsePriority;
	while (this->Gunnery.dequeue(Temp, FalsePriority))
		delete Temp;
}