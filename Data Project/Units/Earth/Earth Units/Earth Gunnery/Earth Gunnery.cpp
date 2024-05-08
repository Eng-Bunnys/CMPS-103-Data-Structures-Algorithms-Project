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
	// Priority 0 Monster , 1 Drone
	int RemainingCapacity = this->AttackCapacity;

	AlienMonster *AttackedMonster = nullptr;
	AlienDrone *FrontAttackedDrone = nullptr;
	AlienDrone *BackAttackedDrone = nullptr;

	while (RemainingCapacity > 0)
	{
		if (Game->GetAlienArmy()->RemoveMonster(AttackedMonster))
		{
			if (AttackedMonster->GetFirstAttackedTime() == -1)
				AttackedMonster->SetFirstAttackedTime(Game->GetTimeStep());

			Game->GetTempList()->AddGunneryAttack(AttackedMonster, 0);
			RemainingCapacity--;
		}

		if (Game->GetAlienArmy()->GetDrones()->DequeueFront(FrontAttackedDrone) && RemainingCapacity > 0)
		{
			if (FrontAttackedDrone->GetFirstAttackedTime() == -1)
				FrontAttackedDrone->SetFirstAttackedTime(Game->GetTimeStep());

			Game->GetTempList()->AddGunneryAttack(FrontAttackedDrone, 0);
			RemainingCapacity--;
		}

		if (Game->GetAlienArmy()->GetDrones()->DequeueBack(BackAttackedDrone) && RemainingCapacity > 0)
		{
			if (BackAttackedDrone->GetFirstAttackedTime() == -1)
				BackAttackedDrone->SetFirstAttackedTime(Game->GetTimeStep());

			Game->GetTempList()->AddGunneryAttack(BackAttackedDrone, 0);
			RemainingCapacity--;
		}
	}

	int AttackedCount = Game->GetTempList()->GetAlienDroneCount() + Game->GetTempList()->GetAlienMonsterCount();

	AttackedMonster = nullptr;
	FrontAttackedDrone = nullptr;
	BackAttackedDrone = nullptr;

	if (Interactive && AttackedCount > 0)
	{
		std::cout << "EG " << AttackedCount << " shots";
		Game->GetTempList()->PrintGunneryAttack();
	}

	int UnitPriority;

	AlienUnit *AttackedUnit = nullptr;

	while (AttackedCount > 0 && Game->GetTempList()->RemoveGunneryAttack(AttackedUnit, UnitPriority))
	{

		if (AttackedUnit->GetFirstAttackedTime() == -1)
			AttackedUnit->SetFirstAttackedTime(Game->GetTimeStep());

		const double DamageDealt = this->CalculateDamage(this->Power, this->Health, AttackedUnit->GetHealth());

		const double NewHealth = AttackedUnit->GetHealth() - DamageDealt;

		if (NewHealth <= 0)
		{
			AttackedUnit->SetHealth(0);
			AttackedUnit->SetDestructionTime(Game->GetTimeStep());
			Game->GetKilledList()->AddUnit(static_cast<Unit *>(AttackedUnit));
		}
		else
		{
			AttackedUnit->SetHealth(NewHealth);

			if (UnitPriority == 1)
			{
				Game->GetAlienArmy()->AddDrone(
					AttackedUnit->GetHealth(),
					AttackedUnit->GetPower(),
					AttackedUnit->GetAttackCapacity());
			}
			else
			{
				Game->GetAlienArmy()->AddMonster(
					AttackedUnit->GetHealth(),
					AttackedUnit->GetPower(),
					AttackedUnit->GetAttackCapacity());
			}
		}
	}
}