#include "Earth Army.h"

EarthArmy::EarthArmy(GameManager* Game)
{
	this->Gunnery = PriorityQueue<EarthGunnery*>();
	this->NextID = 1;
}

PriorityQueue<EarthGunnery*> EarthArmy::GetGunnery() const
{
	return this->Gunnery;
}

void EarthArmy::AddGunnery(double Health, int Power, int AttackCapcity)
{
	/// To-Do: Complete game manager and add a GetTimeStep function & replace it in the last parameter
	/// To-Do: Check if the ID is negative 1, if so then don't add
	EarthGunnery* NewGunnery = new EarthGunnery(++this->NextID, Health, Power, AttackCapcity, 0);
	this->Gunnery.enqueue(NewGunnery, NewGunnery->GetPriority());
}

EarthGunnery* EarthArmy::RemoveGunnery()
{
	EarthGunnery* RemovedGunnery;
	double Priority;
	this->Gunnery.dequeue(RemovedGunnery, Priority);
	return RemovedGunnery;
}

EarthArmy::~EarthArmy()
{
	EarthGunnery* Temp;
	double FalsePriority;
	while (this->Gunnery.dequeue(Temp, FalsePriority))
		delete Temp;
}