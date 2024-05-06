#include "../Game Manager.h"

void GameManager::EarthArmyAttack(GameManager* Game, bool Print)
{
#pragma region SoldierAttack

	EarthSoldier* AttackingSoldier = nullptr;

	if (this->Earth->PeekSoldier(AttackingSoldier))
		AttackingSoldier->Attack(this);

#pragma endregion
}