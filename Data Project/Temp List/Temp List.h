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
    LinkedQueue<EarthSoldier *> EarthSoldierList;

    /* A stack of Earth tanks */
    ArrayStack<EarthTank *> EarthTankList;

    /* A priority queue of Earth gunnery units */
    PriorityQueue<EarthGunnery *> EarthGunneryList;

    /* A queue of Alien soldiers */
    LinkedQueue<AlienSoldier *> AlienSoldierList;

    /* A deque of Alien drones */
    Deque<AlienDrone *> AlienDroneList;

    /* A bag of Alien monsters */
    Bag<AlienMonster *> AlienMonsterList;

    /* The total number of units in the TempList */
    int Count;
    /* The total number of Earth Units */
    int EarthCount;
    /* The total number of Alien Units */
    int AlienCount;
public:
    /* The total number of Earth Soldiers */
    int EarthSoldierCount;

    /* The total number of Earth Soldiers */
    int AlienSoldierCount;
    /**
     * Constructs a new TempList with default initialization
     */
    TempList();

    /**
     * Adds an Earth soldier to the list
     *
     * @param {EarthSoldier*} Soldier - A pointer to an Earth soldier to add
     */
    void AddEarthSoldier(EarthSoldier *Soldier);

    /**
     * Removes an Earth soldier from the list
     *
     * @param {EarthSoldier*&} Soldier - A reference to a pointer where the removed Earth soldier will be stored
     */
    bool RemoveEarthSoldier(EarthSoldier *&Soldier);

    /**
     * Adds an Earth tank to the list
     *
     * @param {EarthTank*} Tank - A pointer to an Earth tank to add
     */
    void AddTank(EarthTank *Tank);

    /**
     * Removes an Earth tank from the list
     *
     * @param {EarthTank*&} Tank - A reference to a pointer where the removed Earth tank will be stored
     */
    void RemoveTank(EarthTank *&Tank);

    /**
     * Adds an Earth gunnery unit to the list
     *
     * @param {EarthGunnery*} Gunnery - A pointer to an Earth gunnery unit to add
     */
    void AddGunnery(EarthGunnery *Gunnery);

    /**
     * Removes an Earth gunnery unit from the list
     *
     * @param {EarthGunnery*&} Gunnery - A reference to a pointer where the removed Earth gunnery unit will be stored
     */
    void RemoveGunnery(EarthGunnery *&Gunnery);

    /**
     * Adds an Alien soldier to the list
     *
     * @param {AlienSoldier*} Soldier - A pointer to an Alien soldier to add
     */
    void AddAlienSoldier(AlienSoldier *Soldier);

    /**
     * Removes an Alien soldier from the list
     *
     * @param {AlienSoldier*&} Soldier - A reference to a pointer where the removed Alien soldier will be stored
     */
    bool RemoveAlienSoldier(AlienSoldier *&Soldier);

    /**
     * Adds an Alien drone to the list
     *
     * @param {AlienDrone*} Drone - A pointer to an Alien drone to add
     */
    void AddDrone(AlienDrone *Drone);

    /**
     * Removes an Alien drone from the list
     *
     * @param {AlienDrone*&} Drone - A reference to a pointer where the removed Alien drone will be stored
     */
    void RemoveDrone(AlienDrone *&Drone);

    /**
     * Adds an Alien monster to the list
     *
     * @param {AlienMonster*} Monster - A pointer to an Alien monster to add
     */
    void AddMonster(AlienMonster *Monster);

    /**
     * Removes an Alien monster from the list
     *
     * @param {AlienMonster*&} Monster - A reference to a pointer where the removed Alien monster will be stored
     */
    void RemoveMonster(AlienMonster *&Monster);

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

    ~TempList();
};

#endif // !TempList_H
