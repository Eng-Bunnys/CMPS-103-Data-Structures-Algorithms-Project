#pragma once

#include"../../Structures/Stack/ArrayStack.h"
#include"../../Structures/Queue/LinkedQueue.h"
#include"../../Structures/Priority Queue/PriorityQueue.h"
#include"../../Structures/Bag/Bag.h"
#include"../../Structures//Deque/Deque.h"

#include "../../Units/Unit.h"

#include"../../Units/Earth/Earth Units/Earth Gunnery/Earth Gunnery.h"
#include"../../Units/Earth/Earth Units/Earth Soldier/Earth Soldier.h"
#include"../../Units/Earth/Earth Units/Earth Tanks/Earth Tank.h"

#include"../../Units/Alien/Alien Units/Alien Soldier/Alien Soldier.h"
#include"../../Units/Alien/Alien Units/Alien Monsters/Alien Monsters.h"
#include"../../Units/Alien/Alien Units/Alien Drones/Alien Drones.h"



class TempList
{
	LinkedQueue<EarthSoldier*> ES_TempList;
	ArrayStack<EarthTank*> ET_TempList;
	PriorityQueue<EarthGunnery*> EG_TempList;

	LinkedQueue<AlienSoldier*> AS_TempList;
	Deque<AlienDrones*> AD_TempList;
	Bag<AlienMonsters*> AM_TempList;

	int TempCount;

public:
	TempList();

	void AddESTemp(EarthSoldier* Soldier);
	void RemoveESTemp(EarthSoldier*& Soldier);

	void AddETTemp(EarthTank* Tank);
	void RemoveETTemp(EarthTank*& Tank);

	void AddEGTemp(EarthGunnery* Gunnery, int p);
	void RemoveEGTemp(EarthGunnery*& Gunnery, int p);


	void AddASTemp(AlienSoldier* Soldier);
	void RemoveASTemp(AlienSoldier*& Soldier);

	void AddADTemp(AlienDrones* Drone);
	void RemoveADTemp(AlienDrones*& Drone);

	/*void AddAMTemp(AlienMonsters* Monster);
	void RemoveAMTemp(AlienMonsters*& Monster);*/

	~TempList();



};