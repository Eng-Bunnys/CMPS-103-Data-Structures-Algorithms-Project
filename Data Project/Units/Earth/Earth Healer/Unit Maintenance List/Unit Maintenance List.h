#pragma once
#include"../../Structures/Priority Queue/PriorityQueue.h" // Include for priority queue
#include"../../Structures/Queue/LinkedQueue.h" // Include for queue

#include"../../Earth Units/Earth Soldier/Earth Soldier.h" // Include for Earth Soldiers
#include"../../Earth Units/Earth Tanks/Earth Tank.h" // Include for Earth Tanks

#include"../../Game Manager/Game Manager.h" // Include for Game Manager

class UnitMaintenanceList
{
	PriorityQueue<EarthSoldier*> soldierUML; // Priority queue for Earth Soldiers in the unit maintenance list
	LinkedQueue<EarthTank*> tankUML; // Queue for Earth Tanks in the unit maintenance list

	GameManager* game; // Pointer to the game manager

	/*int joinedUML_Time;*/

	/**
	 * Retrieves the priority of a soldier in the unit maintenance list.
	 * @param soldier Pointer to the Earth Soldier.
	 * @return The priority of the soldier.
	 */
	int GetSoldierPriority(EarthSoldier* soldier);

public:
	/**
	 * Constructor for the unitMaintenanceList class.
	 * @param gManager GameManager* - Pointer to the game manager.
	 */
	UnitMaintenanceList(GameManager* gManager);

	/**
	 * Retrieves the priority queue of Earth Soldiers in the unit maintenance list.
	 * @return The priority queue of Earth Soldiers.
	 */
	PriorityQueue<EarthSoldier*> GetSoldierUML();

	/**
	 * Retrieves the queue of Earth Tanks in the unit maintenance list.
	 * @return The queue of Earth Tanks.
	 */
	LinkedQueue<EarthTank*> GetTankUML();

	/*void setjoinedUML_Time(int time);
	int getjoinedUML_Time();*/

	/**
	 * Adds a soldier to the unit maintenance list.
	 * @param soldier Pointer to the Earth Soldier.
	 * @param time The current time.
	 * @return True if addition was successful, false otherwise.
	 */
	bool AddSoldierToUML(EarthSoldier*& soldier, int time);

	/**
	 * Removes a soldier from the unit maintenance list.
	 * @param soldier Pointer to the Earth Soldier.
	 * @return True if removal was successful, false otherwise.
	 */
	bool RemoveSoldierFromUML(EarthSoldier*& soldier);

	/**
	 * Checks if the unit maintenance list of soldiers is empty.
	 * @return True if the list is empty, false otherwise.
	 */
	bool IsSoldierUMLEmpty();

	/**
	 * Prints the list of soldiers in the unit maintenance list.
	 */
	void PrintSoldiers();


	/**
	 * Adds a tank to the unit maintenance list.
	 * @param tank Pointer to the Earth Tank.
	 * @param time The current time.
	 * @return True if addition was successful, false otherwise.
	 */
	bool AddTankToUML(EarthTank*& tank, int time);

	/**
	 * Removes a tank from the unit maintenance list.
	 * @param tank Pointer to the Earth Tank.
	 * @return True if removal was successful, false otherwise.
	 */
	bool RemoveTankFromUML(EarthTank*& tank);

	/**
	 * Checks if the unit maintenance list of tanks is empty.
	 * @return True if the list is empty, false otherwise.
	 */
	bool IsTankUMLEmpty();

	/**
	 * Prints the list of tanks in the unit maintenance list.
	 */
	void PrintTanks();

	/**
	 * Prints the entire unit maintenance list.
	 */
	void PrintUML();
};

