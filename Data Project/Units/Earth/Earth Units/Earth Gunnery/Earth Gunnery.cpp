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
	AlienDrone *AttackedDrone = nullptr;

	while (RemainingCapacity > 0)
	{
		if (Game->GetAlienArmy()->RemoveMonster(AttackedMonster))
		{
			Game->GetTempList()->AddGunneryAttack(AttackedMonster, 0);
			RemainingCapacity--;
		}

		if (RemainingCapacity > 0 && Game->GetAlienArmy()->RemoveDrone(AttackedDrone))
		{
			Game->GetTempList()->AddGunneryAttack(AttackedDrone, 1);
			RemainingCapacity--;
		}
	}

	int AttackedCount = Game->GetTempList()->GetGunneryAttack()->GetCount();

	AttackedMonster = nullptr;
	AttackedDrone = nullptr;

	if (Interactive && AttackedCount > 0)
	{
		std::cout << "EG (ID " << this->GetID() << ") is Attacking ";
		Game->GetTempList()->PrintGunneryAttack();
	}

	int UnitPriority;

	AlienUnit *AttackedUnit = nullptr;

	while (AttackedCount > 0 &&
		   Game->GetTempList()->RemoveGunneryAttack(AttackedUnit, UnitPriority))
	{

		const double DamageDealt = this->CalculateDamage(this->Power, this->Health, AttackedUnit->GetHealth());

		const double NewHealth = AttackedUnit->GetHealth() - DamageDealt;

		if (NewHealth <= 0)
		{
			AttackedUnit->SetHealth(0);
			Game->GetKilledList()->AddUnit(AttackedUnit);
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