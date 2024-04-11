#include "Earth Army.h"

EarthArmy::EarthArmy(GameManager* Game) {
	this->Gunnery = new PriorityQueue<EarthGunnery*>;
	this->NextID = 1;
}

PriorityQueue<EarthGunnery*>* EarthArmy::GetGunnery() const {
	return this->Gunnery;
}

void EarthArmy::AddGunnery(double Health, int Power, int AttackCapcity) {
	/// To-Do: Complete game manager and add a GetTimeStep function & replace it in the last parameter
	EarthGunnery* NewGunnery = new EarthGunnery(++this->NextID, Health, Power, AttackCapcity, 0);
	this->Gunnery->enqueue(NewGunnery, NewGunnery->GetPriority());
}

EarthArmy::~EarthArmy() {
	EarthGunnery* Temp;
	// Since the dequeue takes a priority we create an empty variable for it
	double FalsePriority;
	while (this->Gunnery->dequeue(Temp, FalsePriority))
		delete Temp;

	delete this->Gunnery;
}

void EarthArmy::print() {
	std::cout << "============= Earth Army Alive Units =============\n";
}