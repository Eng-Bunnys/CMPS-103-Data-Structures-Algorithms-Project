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

void EarthGunnery::Attack(GameManager* Game) {
	///To-Do: Handle print
	/* 
	Since the document stated that we attack monsters first then we attack drones, I created a priority queue where the monster has a
	priority of 0 and drone has 1
	*/
	PriorityQueue<Unit*>* AttackOrder = new PriorityQueue<Unit*>;

	int RemainingCapacity = this->AttackCapacity;

	AlienMonster* AttackedMonster = nullptr;
	AlienDrone* AttackedFrontDrone = nullptr;
	AlienDrone* AttackedBackDrone = nullptr;

	// Adding the units to be attacked to the queue
	while (RemainingCapacity != 0) {
		if (Game->GetAlienArmy()->RemoveMonster(AttackedMonster))
		{
			AttackOrder->enqueue(AttackedMonster, 0);
			RemainingCapacity--;
		}
		
		if (Game->GetAlienArmy()->GetDrones().DequeueFront(AttackedFrontDrone)) {
			AttackOrder->enqueue(AttackedFrontDrone, 1);
			RemainingCapacity--;
		}

		if (Game->GetAlienArmy()->GetDrones().DequeueBack(AttackedBackDrone)) {
			AttackOrder->enqueue(AttackedBackDrone, 1);
			RemainingCapacity--;
		}
	}

	Unit* AttackedUnit = nullptr;
	int UnitPriority = -1;

	// Attacking them 
	for (int i = 0; i < AttackOrder->GetCount(); i++) {
		if (AttackOrder->dequeue(AttackedUnit, UnitPriority))
		{
			if (AttackedUnit->GetFirstAttackedTime() == -1)
				AttackedUnit->SetFirstAttackedTime(Game->GetTimeStep());

			const double DamageRecieved = this->CalculateDamage(this->Power, this->Health, AttackedUnit->GetHealth());

			const double NewHealth = AttackedUnit->GetHealth() - DamageRecieved;

			if (NewHealth <= 0) {
				AttackedUnit->SetDestructionTime(Game->GetTimeStep());
				Game->GetKilledList()->AddUnit(AttackedUnit);
			}
			else {
				// Adding to temp list

				if (UnitPriority == 0)
					Game->GetTempList()->AddMonster(static_cast<AlienMonster*>(AttackedUnit));
				else
					Game->GetTempList()->AddDrone(static_cast<AlienDrone*>(AttackedUnit));
			}
		}
	}

	delete AttackOrder;
}