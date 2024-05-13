#ifndef UnitMaintenanceList_H
#define UnitMaintenanceList_H

#include "../../Structures/Priority Queue/PriorityQueue.h"
#include "../../Units/Earth/Earth Unit/Earth Unit.h"

class UnitMaintenanceList
{
private:
	/* The Priority Queue that contains the Units */
	PriorityQueue<EarthUnit *> *UnitMaintenance;

public:
	UnitMaintenanceList();

	PriorityQueue<EarthUnit *> *GetUnitMaintenance() const;
	bool AddUnit(EarthUnit *AddedUnit);
	bool RemoveUnit(EarthUnit *RemovedUnit);
};

#endif // !UnitMaintenanceList_H
