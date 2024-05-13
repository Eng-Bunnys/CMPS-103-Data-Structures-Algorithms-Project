#include "Unit Maintenance List.h"

UnitMaintenanceList::UnitMaintenanceList()
{
	this->UnitMaintenance = new PriorityQueue<EarthUnit *>();
}

PriorityQueue<EarthUnit *> *UnitMaintenanceList::GetUnitMaintenance() const
{
	return this->UnitMaintenance;
}

/// To-Do: Finish Add & Remove