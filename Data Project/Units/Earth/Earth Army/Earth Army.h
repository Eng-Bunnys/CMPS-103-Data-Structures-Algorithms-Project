#pragma once


/// Just uncomment and adjust the includes/wording of variables , classes , etc.. if there is error , I have tested this and it works



#include "../../Structures/Priority Queue/linkedPriorityQueue.h"
#include "../../Structures/Queue/LinkedQueue.h"
#include "../../Structures/Stack/ArrayStack.h"

//#include "../Earth Soldiers/Earth Soldiers.h"
//#include "../Earth Gunnery/Earth Gunnery.h"
#include "../Earth Tanks/Earth Tanks.h"

#include "../../Game Manager/GameManager.h"

class earthArmy {
        // Lists for the 3 main subunits
        //PriorityQueue<earthGunnery*> earthGunneries; // Priority queue for Earth Gunnery units
        //linkedQueue<earthSoldier*> earthSoldiers;          // Queue for Earth Soldier units
        ArrayStack<earthTank*> earthTanks;                 // Stack for Earth Tank units

        // IDs for the units
        int nextSoldierID = 0;    // Next ID for Earth Soldier
        int nextTankID = 0;        // Next ID for Earth Tank
        int nextGunneryID = 0;     // Next ID for Earth Gunnery

        // Counters for the units
        int EScount = 0;  // Counter for Earth Soldiers
        int EGcount = 0;  // Counter for Earth Gunneries
        int ETcount = 0;  // Counter for Earth Tanks

        GameManager* gManager;  // Pointer to the game manager

 public:
        earthArmy();  // Default constructor
        earthArmy(GameManager* gameManager);  // Constructor with a game manager parameter

        // ========================= Soldiers functions =========================
        


        /**
         * Gets the list of Earth Soldiers.
         * @return {linkedQueue<earthSoldier*>} - The list of Earth Soldiers.
         */
 //       linkedQueue<earthSoldier*> getEarthSoldiersList();

        /**
         * Adds a new Earth Soldier to the army.
         * @param Power - The power of the soldier.
         * @param Health - The health of the soldier.
         * @param AttackCapacity - The attack capacity of the soldier.
         * @return {bool} - True if the addition was successful, false otherwise.
         */
 //       bool addSoldier(int Power, double Health, int AttackCapacity);

        /**
         * Removes an Earth Soldier from the army.
         * @param pointer to soldier - The Earth Soldier to be removed.
         * @return {bool} - True if the removal was successful, false otherwise.
         */
 //       bool removeSoldier(earthSoldier*& soldier);

        /**
        * Checks if the Earth Soldier list is empty or not
        * @return {bool} - True if empty , false if not empty
        */
 //       bool isES_Empty();

        /**
         * Prints the list of Earth Soldiers.
         */
 //       void printSoldiers();



        // ========================= Tanks functions =========================

        /**
         * Gets the list of Earth Tanks.
         * @return {linkedStack<earthTank*>} - The list of Earth Tanks.
         */
        ArrayStack<earthTank*> getTanksList();

        /**
         * Adds a new Earth Tank to the army.
         * @param Power - The power of the tank.
         * @param Health - The health of the tank.
         * @param AttackCapacity - The attack capacity of the tank.
         * @return {bool} - True if the addition was successful, false otherwise.
         */
        bool addTank(int Power, double Health, int AttackCapacity);

        /**
         * Removes an Earth Tank from the army.
         * @param pointer to tank - The Earth Tank to be removed.
         * @return {bool} - True if the removal was successful, false otherwise.
         */
        bool removeTank(earthTank*& tank);

        /**
        * Checks if the Earth Soldier list is empty or not
        * @return {bool} - True if empty , false if not empty
        */
        bool isET_Empty();


        /**
         * Prints the list of Earth Tanks.
         */
        void printTanks();

        // ========================= Gunneries functions =========================

        /**
         * Gets the list of Earth Gunneries.
         * @return {linkedPriorityQueue<earthGunnery*>} - The list of Earth Gunneries.
         */
//        PriorityQueue<earthGunnery*> getGunneryList();

        /**
         * Adds a new Earth Gunnery to the army.
         * @param Power - The power of the gunnery.
         * @param Health - The health of the gunnery.
         * @param AttackCapacity - The attack capacity of the gunnery.
         * @param Priority - The priority of the gunnery.
         * @return {bool} - True if the addition was successful, false otherwise.
         */
 //       bool addGunnery(int Power, double Health, int AttackCapacity);

        /**
         * Removes an Earth Gunnery from the army.
         * @param pointer to gunnery - The Earth Gunnery to be removed.
         * @return {bool} - True if the removal was successful, false otherwise.
         */
  //      bool removeGunnery(earthGunnery*& gunnery, int& priority);

        /**
        * Checks if the Earth Soldier list is empty or not
        * @return {bool} - True if empty , false if not empty
        */
  //      bool isEG_Empty();

        /**
        * Prints the list of Earth Gunneries.
        */
 //     void printGunneries();
};


