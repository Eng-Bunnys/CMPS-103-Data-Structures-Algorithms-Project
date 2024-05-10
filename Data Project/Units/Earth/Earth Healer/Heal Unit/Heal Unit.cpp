#include "Heal Unit.h"
//include here heal list
#include"../Unit Maintenance List/Unit Maintenance List.h"

HealUnit::HealUnit(int ID, int attackCap, int joinedTime, int power, double health) : EarthUnit(ID, attackCap, joinedTime, power, health) {}

///Uncomment the commented parts+ add handling of temp lists when it is done

void HealUnit::Attack(GameManager* game)
{
	//healList* HL = game->getHealList();
	UnitMaintenanceList* UML = game->GetUML();
	TempList* temp = game->GetTempList();
	KilledList* killed = game->GetKilledList();

	if (/*!game->GetHealList()->isHealListEmpty()*/) {
		HealUnit* HU;
		//HL->getHealList().pop(HU);
		for (int i = 0; i < HU->GetAttackCapacity(); i++) {
			if (!UML->IsSoldierUMLEmpty()) {
				EarthSoldier* ES;
				int pri;
				UML->GetSoldierUML().dequeue(ES, pri);
				int timeSpentInUML = game->GetTimeStep() - ES->GetTimeJoinedUML();
				if (timeSpentInUML >= 10) {
					Unit* unitKilled = static_cast<Unit*>(ES);
					killed->AddUnit(unitKilled);
				}
				else {
					ES->SetHealth(ES->GetHealth() + CalculateDamage(HU->GetPower(), HU->GetHealth(), ES->GetHealth()));
					if (ES->GetHealth() >= 100.00) ES->SetHealth(100.00);
					//temp->AddHealedSoldier(ES);
				}

			}
			else {
				EarthTank* ET;
				UML->GetTankUML().dequeue(ET);
				int timeSpentInUML = game->GetTimeStep() - ET->GetTimeJoinedUML();
				if (timeSpentInUML >= 10) {
					Unit* unitKilled = static_cast<Unit*>(ET);
					killed->AddUnit(unitKilled);
				}
				else {
					ET->SetHealth(ET->GetHealth() + CalculateDamage(HU->GetPower(), HU->GetHealth(), ET->GetHealth()));
					if (ET->GetHealth() >= 100.00) ET->SetHealth(100.00);
					//temp->AddHealedTank(ET);
				}

			}

		}
		//temp->addHUToList(HU);
	}
}
