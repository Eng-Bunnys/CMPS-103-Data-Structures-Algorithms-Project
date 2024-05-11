#include "../Game Manager.h"

void GameManager::EarthArmyAttack(GameManager* Game, bool Print)
{
#pragma region SoldierAttack

	EarthSoldier* AttackingSoldier = nullptr;

	if (this->Earth->PeekSoldier(AttackingSoldier))
		AttackingSoldier->Attack(this);

#pragma endregion

#pragma region GunneryAttack
	
	EarthGunnery* AttackingGunnery = nullptr;

	if (this->Earth->PeekGunnery(AttackingGunnery))
		AttackingGunnery->Attack(this);

#pragma endregion


#pragma region TankAttack

	EarthTank* AttackingTank = nullptr;

	if (this->Earth->PeekTank(AttackingTank))
		AttackingTank->Attack(this);

#pragma endregion
}