#pragma once
#include"../Earth Unit.h"


class earthTanks :public earthUnit {
	//static int ETcount = 0;
public:
	earthTanks(int ID, int attackCap, int joinedTime, int bTime, int power, double health);
	void print() override {};
};