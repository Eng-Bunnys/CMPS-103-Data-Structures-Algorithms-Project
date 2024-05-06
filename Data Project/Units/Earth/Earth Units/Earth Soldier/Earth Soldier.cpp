#include "Earth Soldier.h"
#include "../../Structures/Queue/LinkedQueue.h"
#include "../../Game Manager/Game Manager.h"
#include "../../Utils/Utils.h"

#include <iostream>

EarthSoldier::EarthSoldier(int ID, double Health, int Power, int AttackCapacity, int JoinTime)
	: EarthUnit(ID, Health, Power, AttackCapacity, JoinTime) {}

void EarthSoldier::Attack(GameManager *Game, bool Interactive)
{
	int RemainingCapacity = this->AttackCapacity;

	AlienSoldier *AttackedSoldier = nullptr;

	while (RemainingCapacity > 0 && Game->GetAlienArmy()->RemoveSoldier(AttackedSoldier))
	{
		if (AttackedSoldier->GetFirstAttackedTime() == -1)
			AttackedSoldier->SetFirstAttackedTime(Game->GetTimeStep());

		Game->GetTempList()->AddAlienSoldier(AttackedSoldier);
		RemainingCapacity--;
	}

	int AttackedCount = Game->GetTempList()->AlienSoldierCount;

	AttackedSoldier = nullptr;

	while (AttackedCount > 0)
	{
		if (Game->GetTempList()->RemoveAlienSoldier(AttackedSoldier))
		{
			const double DamageDealt = this->CalculateDamage(this->Power, this->Health, AttackedSoldier->GetHealth());

			const double NewHealth = AttackedSoldier->GetHealth() - DamageDealt;

			if (NewHealth <= 0)
			{
				AttackedSoldier->SetHealth(0);
				AttackedSoldier->SetDestructionTime(Game->GetTimeStep());
				Game->GetKilledList()->AddUnit(static_cast<Unit *>(AttackedSoldier));
			}
			else
			{
				AttackedSoldier->SetHealth(NewHealth);

				Game->GetAlienArmy()->AddSoldier(
					AttackedSoldier->GetHealth(),
					AttackedSoldier->GetPower(),
					AttackedSoldier->GetAttackCapacity());
			}
		}
		AttackedCount--;
	}
}
