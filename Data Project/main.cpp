#include "../../Units/Alien/Alien Army/Alien Army.h"
#include "../../Game Manager/Game Manager.h"
int main() {
	GameManager Game;
	AlienArmy Army(&Game);

	Army.AddSoldier(20.0, 20, 20);
	Army.AddSoldier(20.0, 20, 20);

	Army.AddDrone(1.0, 1, 2);

	Army.AddMonster(1.0, 1, 2);
	Army.AddMonster(1.0, 1, 2);

	Army.Print();
}
