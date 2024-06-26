#ifndef TempList_H
#define TempList_H

/// Structure Imports

#include "../../Structures/Stack/ArrayStack.h"
#include "../../Structures/Queue/LinkedQueue.h"
#include "../../Structures/Priority Queue/PriorityQueue.h"
#include "../../Structures/Bag/Bag.h"
#include "../../Structures//Deque/Deque.h"

/// Earth Unit Imports

#include "../../Units/Earth/Earth Units/Earth Gunnery/Earth Gunnery.h"
#include "../../Units/Earth/Earth Units/Earth Soldier/Earth Soldier.h"
#include "../../Units/Earth/Earth Units/Earth Tanks/Earth Tank.h"

/// Alien Unit Imports

#include "../../Units/Alien/Alien Units/Alien Soldier/Alien Soldier.h"
#include "../../Units/Alien/Alien Units/Alien Monsters/Alien Monsters.h"
#include "../../Units/Alien/Alien Units/Alien Drones/Alien Drones.h"

class TempList
{
private:
    /* A queue of Earth soldiers */
    LinkedQueue<EarthSoldier *> *EarthSoldierList;

    /* A stack of Earth tanks */
    ArrayStack<EarthTank *> *EarthTankList;

    /* A priority queue of Earth gunnery units */
    PriorityQueue<EarthGunnery *> *EarthGunneryList;

    /* A queue of Alien soldiers */
    LinkedQueue<AlienSoldier *> *AlienSoldierList;

    /* A deque of Alien drones */
    Deque<AlienDrone *> *AlienDroneList;

    /* A bag of Alien monsters */
    Bag<AlienMonster *> *AlienMonsterList;

    /* A Priority queue of Alien Monsters & Drones, Priority 1 for Alien Drone, 0 for Monster */
    PriorityQueue<AlienUnit *> *AlienMonsterAndDroneList;

    /* A Priority queue of Alien Monsters & Soldiers, Priority 1 for Alien Monster, 0 for Soldier */
    PriorityQueue<AlienUnit *> *AlienMonsterAndSoldierList;

    /* The total number of Earth Units */
    int EarthCount;
    /* The total number of Alien Units */
    int AlienCount;
    /* The total number of Earth Soldiers */
    int EarthSoldierCount;
    /* The total number of Alien Soldiers */
    int AlienSoldierCount;
    /* The total number of Alien Monsters */
    int AlienMonsterCount;
    /* The total number of Alien Drones */
    int AlienDroneCount;

public:
    /**
     * Constructs a new TempList with default initialization
     */
    TempList();

#pragma region GunneryAttackList

    /*
     * Adds a Gunnery Attack Unit
     *
     * @param {int} Priority - The unit's priority
     * @param {AlienUnit*} AttackedUnit - A pointer to the unit that will get attacked
     * @returns {bool} - If the operation was successful
     */
    bool AddGunneryAttack(AlienUnit *AttackedUnit, int Priority);

    /*
     * Removes a Gunnery Attack Unit
     *
     * @param {int&} Priority - The unit's priority
     * @param {AlienUnit*&} AttackedUnit - A pointer to the unit that will get attacked
     * @returns {bool} - If the operation was successful
     */
    bool RemoveGunneryAttack(AlienUnit *&AttackedUnit, int &Priority);

    /*
     * Prints all of the available Gunnery Attacked Units
     *
     * @returns {void}
     */
    void PrintGunneryAttack();

    /*
     * Returns the Earth Gunnery attack instance
     *
     * @returns {PriorityQueue<AlienUnit *>*}
     */
    PriorityQueue<AlienUnit *> *GetGunneryAttack() const;

#pragma endregion

#pragma region TankAttackList

    /*
     * Adds a Tank Attack Unit
     *
     * @param {int} Priority - The unit's priority
     * @param {AlienUnit*} AttackedUnit - A pointer to the unit that will get attacked
     * @returns {bool} - If the operation was successful
     */
    bool AddTankAttack(AlienUnit *AttackedUnit, int Priority);

    /*
     * Removes a Tank Attack Unit
     *
     * @param {int&} Priority - The unit's priority
     * @param {AlienUnit*&} AttackedUnit - A pointer to the unit that will get attacked
     * @returns {bool} - If the operation was successful
     */
    bool RemoveTankAttack(AlienUnit *&AttackedUnit, int &Priority);

    /*
     * Prints all of the available Tank Attacked Units
     *
     * @returns {void}
     */
    void PrintTankAttack();

    /*
     * Returns the Earth Tank attack instance
     *
     * @returns {PriorityQueue<AlienUnit *>*}
     */
    PriorityQueue<AlienUnit *> *GetTankAttack() const;

#pragma endregion

#pragma region EarthSoldierList

    /**
     * Adds an Earth soldier to the list
     *
     * @param {EarthSoldier*} Soldier - A pointer to an Earth soldier to add
     * @returns {bool} - If the operation was successful
     */
    bool AddEarthSoldier(EarthSoldier *Soldier);

    /**
     * Removes an Earth soldier from the list
     *
     * @param {EarthSoldier*&} Soldier - A reference to a pointer where the removed Earth soldier will be stored
     * @returns {bool} - If the operation was successful
     */
    bool RemoveEarthSoldier(EarthSoldier *&Soldier);

    /*
     * Returns the Earth Soldier instance
     *
     * @returns { LinkedQueue<EarthSoldier*>*}
     */
    LinkedQueue<EarthSoldier *> *GetEarthSoldiers() const;

#pragma endregion

    /*
     * Prints all of the available Earth Soldiers
     *
     * @returns {void}
     */
    //  void PrintEarthSoldier();

    /**
     * Adds an Earth tank to the list
     *
     * @param {EarthTank*} Tank - A pointer to an Earth tank to add
     * @returns {bool} - If the operation was successful
     */
    bool AddTank(EarthTank *Tank);

    /**
     * Removes an Earth tank from the list
     *
     * @param {EarthTank*&} Tank - A reference to a pointer where the removed Earth tank will be stored
     * @returns {bool} - If the operation was successful
     */
    bool RemoveTank(EarthTank *&Tank);

    /**
     * Adds an Earth gunnery unit to the list
     *
     * @param {EarthGunnery*} Gunnery - A pointer to an Earth gunnery unit to add
     * @returns {bool} - If the operation was successful
     */
    bool AddGunnery(EarthGunnery *Gunnery);

    /**
     * Removes an Earth gunnery unit from the list
     *
     * @param {EarthGunnery*&} Gunnery - A reference to a pointer where the removed Earth gunnery unit will be stored
     * @returns {bool} - If the operation was successful
     */
    bool RemoveGunnery(EarthGunnery *&Gunnery);

#pragma region AlienSoldier

    /**
     * Adds an Alien soldier to the list
     *
     * @param {AlienSoldier*} Soldier - A pointer to an Alien soldier to add
     * @returns {bool} - If the operation was successful
     */
    bool AddAlienSoldier(AlienSoldier *Soldier);

    /**
     * Removes an Alien soldier from the list
     *
     * @param {AlienSoldier*&} Soldier - A reference to a pointer where the removed Alien soldier will be stored
     * @returns {bool} - If the operation was successful
     */
    bool RemoveAlienSoldier(AlienSoldier *&Soldier);

    /*
     * Returns the Alien Soldier instance
     *
     * @returns { LinkedQueue<EarthSoldier*>*}
     */
    LinkedQueue<AlienSoldier *> *GetAlienSoldiers() const;

#pragma endregion

    /*
     * Prints all of the available Alien Soldiers
     *
     * @returns {void}
     */
    void PrintAlienSoldier();

    /**
     * Adds an Alien drone to the list
     *
     * @param {AlienDrone*} Drone - A pointer to an Alien drone to add
     * @returns {bool} - If the operation was successful
     */
    bool AddDrone(AlienDrone *Drone);

    /**
     * Removes an Alien drone from the list
     *
     * @param {AlienDrone*&} Drone - A reference to a pointer where the removed Alien drone will be stored
     * @returns {bool} - If the operation was successful
     */
    bool RemoveDrone(AlienDrone *&Drone);

    /*
     * Prints all of the available Alien Drones
     *
     * @returns {void}
     */
    void PrintAlienDrones();

    /**
     * Adds an Alien monster to the list
     *
     * @param {AlienMonster*} Monster - A pointer to an Alien monster to add
     * @returns {bool} - If the operation was successful
     */
    bool AddMonster(AlienMonster *Monster);

    /**
     * Removes an Alien monster from the list
     *
     * @param {AlienMonster*&} Monster - A reference to a pointer where the removed Alien monster will be stored
     * @returns {bool} - If the operation was successful
     */
    bool RemoveMonster(AlienMonster *&Monster);

    /*
     * Prints all of the available Alien Monsters
     *
     * @returns {void}
     */
    void PrintAlienMonsters();

    /*
     * Returns the total number of units in the temp list
     *
     * @returns {int} - The unit count
     */
    int GetCount() const;

    /*
     * Returns the total number of Earth units in the temp list
     *
     * @returns {int} - The unit count
     */
    int GetEarthCount() const;

    /*
     * Returns the total number of Alien units in the temp list
     *
     * @returns {int} - The unit count
     */
    int GetAlienCount() const;

    /*
     * Returns the total number of Alien soldiers in the temp list
     *
     * @returns {int} - The unit count
     */
    int GetAlienSoldierCount() const;

    /*
     * Returns the total number of Alien Monsters in the temp list
     *
     * @returns {int} - The unit count
     */
    int GetAlienMonsterCount() const;

    /*
     * Returns the total number of Alien Drone in the temp list
     *
     * @returns {int} - The unit count
     */
    int GetAlienDroneCount() const;

    ~TempList();
};

#endif // !TempList_H
