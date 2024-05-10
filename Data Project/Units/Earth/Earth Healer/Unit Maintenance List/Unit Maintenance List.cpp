#include "Unit Maintenance List.h"

int UnitMaintenanceList::GetSoldierPriority(EarthSoldier* soldier)
{
	return 100.00 - soldier->GetHealth();
}

UnitMaintenanceList::UnitMaintenanceList(GameManager* gManager)
{
	game = gManager;
}

PriorityQueue<EarthSoldier*> UnitMaintenanceList::GetSoldierUML()
{
	return soldierUML;
}

LinkedQueue<EarthTank*> UnitMaintenanceList::GetTankUML()
{
	return tankUML;
}

//void unitMaintenanceList::setjoinedUML_Time(int time)
//{
//	joinedUML_Time = time;
//}
//
//int unitMaintenanceList::getjoinedUML_Time()
//{
//	return joinedUML_Time;
//}

bool UnitMaintenanceList::AddSoldierToUML(EarthSoldier*& soldier, int timeToJoin) /// time to join is the current time step in the game
{
	int priority = GetSoldierPriority(soldier);
	//setjoinedUML_Time(timeToJoin);
	if (!soldier->GetUMLFlags()) soldier->SetTimeJoinedUML(timeToJoin);
	return soldierUML.enqueue(soldier, priority);
}

bool UnitMaintenanceList::RemoveSoldierFromUML(EarthSoldier*& soldier)
{
	int prriority;
	return soldierUML.dequeue(soldier, prriority);
}

bool UnitMaintenanceList::IsSoldierUMLEmpty()
{
	return soldierUML.isEmpty();
}

void UnitMaintenanceList::PrintSoldiers()
{
	if (!IsSoldierUMLEmpty()) {
		soldierUML.Print();
		std::cout << " , ";
	}

}

bool UnitMaintenanceList::AddTankToUML(EarthTank*& tank, int timeToJoin)  /// time to join is the current time step in the game
{
	//setjoinedUML_Time(timeToJoin);
	if (!tank->GetUMLFlags()) tank->SetTimeJoinedUML(timeToJoin);
	return tankUML.enqueue(tank);
}

bool UnitMaintenanceList::RemoveTankFromUML(EarthTank*& tank)
{
	return tankUML.dequeue(tank);
}

bool UnitMaintenanceList::IsTankUMLEmpty()
{
	return tankUML.isEmpty();
}

void UnitMaintenanceList::PrintTanks()
{

	if (!IsTankUMLEmpty()) tankUML.Print();
}

void UnitMaintenanceList::PrintUML()
{
	std::cout << "==================================== Unit Mainetenance List ====================================\n";
	std::cout << soldierUML.GetCount() + tankUML.GetCount() << " UML[ ";
	PrintSoldiers();
	PrintTanks();
	std::cout << " ]" << std::endl;
}


