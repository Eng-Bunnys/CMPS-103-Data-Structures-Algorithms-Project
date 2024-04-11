#include "Game Manager/GameManager.h"

#include"Units/Unit.h"

int main()
{
	GameManager Game;
	
	/*std::cout << "Testing Create Unit...\n";
	unit  U (0, 80, 12, 20, 100, 100);
	U.print();

	std::cout << "Testing set health\n";
	U.setHealth(80.0);
	U.print();

	std::cout << "Testing set power\n";
	U.setPower(50);
	U.print();

	std::cout << "Testing set attCap\n";
	U.setAttackCapacity(16);
	U.print();*/

	Game.Start();

	return 0;
}