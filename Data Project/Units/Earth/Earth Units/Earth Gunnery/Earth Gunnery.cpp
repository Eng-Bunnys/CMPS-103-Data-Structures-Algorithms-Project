#include "Earth Gunnery.h"

#include "../../Game Manager/Game Manager.h"

#include "../../Structures/Priority Queue/PriorityQueue.h"
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

void EarthGunnery::Attack(GameManager *Game, bool Interactive)
{
	int RemainingCapacity = this->AttackCapacity;

	AlienMonster *AttackedMonster = nullptr;
	AlienDrone *FrontAttackedDrone = nullptr;
	AlienDrone *BackAttackedDrone = nullptr;

	while (RemainingCapacity > 0)
	{

		bool CapacityReduced = false;

		if (Game->GetAlienArmy()->RemoveMonster(AttackedMonster))
		{
			if (AttackedMonster->GetFirstAttackedTime() == -1)
				AttackedMonster->SetFirstAttackedTime(Game->GetTimeStep());

			Game->GetTempList()->AddMonster(AttackedMonster);
			CapacityReduced = true;
		}

		if (Game->GetAlienArmy()->GetDrones().DequeueFront(FrontAttackedDrone) && RemainingCapacity > 0)
		{
			if (FrontAttackedDrone->GetFirstAttackedTime() == -1)
				FrontAttackedDrone->SetFirstAttackedTime(Game->GetTimeStep());

			Game->GetTempList()->AddDrone(FrontAttackedDrone);
			CapacityReduced = true;
		}

		if (Game->GetAlienArmy()->GetDrones().DequeueBack(BackAttackedDrone) && RemainingCapacity > 0)
		{
			if (BackAttackedDrone->GetFirstAttackedTime() == -1)
				BackAttackedDrone->SetFirstAttackedTime(Game->GetTimeStep());

			Game->GetTempList()->AddDrone(BackAttackedDrone);
			CapacityReduced = true;
		}

		if (CapacityReduced)
			RemainingCapacity--;
		else
			break;
	}

	int AttackedCount = Game->GetTempList()->GetAlienDroneCount() + Game->GetTempList()->GetAlienMonsterCount();

	///To-Do: Add All Units to Pri Queue 

	if (Interactive && AttackedCount > 0)
	{
		std::cout << "EG " << AttackedCount << " shots";
		/// To-Do: Add a print that supports both drones & monster
	}

	AttackedMonster = nullptr;
	FrontAttackedDrone = nullptr;
	BackAttackedDrone = nullptr;

}