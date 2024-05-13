#include "Earth Tank.h"
#include "../../Game Manager/Game Manager.h"

EarthTank::EarthTank(int ID, double Health, int Power, int AttackCapacity, int JoinTime)
	: EarthUnit(ID, Health, Power, AttackCapacity, JoinTime) {}

bool EarthTank::AttackSoldiers(GameManager *Game)
{
	int AlienSoldierCount = Game->GetAlienArmy()->GetSoldiers()->GetCount();
	int EarthSoldierCount = Game->GetEarthArmy()->GetSoldiers()->GetCount();

	static bool HasEarthSoldierRatioDropped = false;

	double EarthToAlienRatio = 100.0 * static_cast<double>(EarthSoldierCount) / AlienSoldierCount;

	if (EarthToAlienRatio < 30.0)
	{
		HasEarthSoldierRatioDropped = true;
		return true;
	}
	else if (HasEarthSoldierRatioDropped && EarthToAlienRatio >= 80.0)
	{
		HasEarthSoldierRatioDropped = false;
		return false;
	}

	return false;
}

void EarthTank::Attack(GameManager *Game, bool Interactive)
{
	int RemainingCapacity = this->AttackCapacity;

	AlienSoldier *AttackedSoldier = nullptr;
	AlienMonster *AttackedMonster = nullptr;

	while (RemainingCapacity > 0)
	{

		if (Game->GetAlienArmy()->RemoveMonster(AttackedMonster))
		{
			if (AttackedMonster->GetFirstAttackedTime() == -1)
				AttackedMonster->SetFirstAttackedTime(Game->GetTimeStep());

			Game->GetTempList()->AddTankAttack(AttackedMonster, 1);
			RemainingCapacity--;
		}
		else if (AttackSoldiers(Game) && Game->GetAlienArmy()->RemoveSoldier(AttackedSoldier))
		{
			if (AttackedSoldier->GetFirstAttackedTime() == -1)
				AttackedSoldier->SetFirstAttackedTime(Game->GetTimeStep());

			Game->GetTempList()->AddTankAttack(AttackedSoldier, 0);
			RemainingCapacity--;
		}
		else
		{
			break;
		}
	}

	int AttackedCount = Game->GetTempList()->GetTankAttack()->GetCount();

	AttackedSoldier = nullptr;
	AttackedMonster = nullptr;

	if (Interactive && AttackedCount > 0)
	{
		std::cout << "ET (ID " << this->GetID() << ") is Attacking ";
		Game->GetTempList()->PrintTankAttack();
	}

	int UnitPriority;

	AlienUnit *AttackedUnit = nullptr;

	while (AttackedCount > 0 && Game->GetTempList()->RemoveTankAttack(AttackedUnit, UnitPriority))
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
				Game->GetAlienArmy()->AddMonster(
					AttackedUnit->GetHealth(),
					AttackedUnit->GetPower(),
					AttackedUnit->GetAttackCapacity());
			}
			else
			{
				Game->GetAlienArmy()->AddSoldier(
					AttackedUnit->GetHealth(),
					AttackedUnit->GetPower(),
					AttackedUnit->GetAttackCapacity());
			}
		}
	}
}