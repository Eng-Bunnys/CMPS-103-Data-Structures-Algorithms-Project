#pragma once
#include "../Unit.h"

#define MAX_HEALTH 100;
class earthUnit :
    public unit
{
public:
    earthUnit(int ID, int attackCap, int joinedTime, int bTime, int power, double health);
};

