#pragma once
#include"../Earth Unit.h"


class earthTank :public earthUnit {
	const int id;
public:
	earthTank(int ID, int attackCap, int joinedTime, int power, double health);
	int getID();
	double getHealth();
};