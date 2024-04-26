#include "Game Manager.h"

void GameManager::EarthArmyAttack() {
	EarthGunnery* TempGunnery;

	int TempPri;

	if (this->Earth->GetGunnery().peek(TempGunnery, TempPri))
		TempGunnery->Attack(this);

}