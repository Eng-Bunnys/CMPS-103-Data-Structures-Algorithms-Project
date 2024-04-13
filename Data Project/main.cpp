#include "../../Game Manager/GameManager.h"
#include "../../Units/Earth/Earth Army/Earth Army.h"
int main() {
	GameManager Game;

	EarthArmy Army(&Game);

	Army.AddGunnery(20.0, 20, 20);
	Army.AddGunnery(20.0, 20, 20);
	Army.AddGunnery(20.0, 20, 20);
	Army.AddGunnery(20.0, 20, 20);

	Army.AddSoldier(30.0, 30, 30);
	Army.AddSoldier(30.0, 30, 30);
	Army.AddSoldier(30.0, 30, 30);
	Army.AddSoldier(30.0, 30, 30);
	Army.AddSoldier(30.0, 30, 30);

	Army.AddTank(40.0, 40, 40);
	Army.AddTank(40.0, 40, 40);
	Army.AddTank(40.0, 40, 40);
	Army.AddTank(40.0, 40, 40);
	Army.AddTank(40.0, 40, 40);
	Army.AddTank(40.0, 40, 40);
	Army.AddTank(40.0, 40, 40);
	Army.AddTank(40.0, 40, 40);
	Army.AddTank(40.0, 40, 40);

	Army.Print();
}