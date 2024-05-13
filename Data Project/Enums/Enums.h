#ifndef Enums_H
#define Enums_H

/**
 * @enum Army
 * Enumeration representing different armies
 */
enum Army
{
    /* For GetWinners, if all conditions aren't met */
    None,
    /* Represents the Earth Army */
    Earth,
    /* Represents the Alien Army */
    Alien
};

/**
 * @enum ArrayInsertPositions
 * Enumeration representing positions for inserting elements into an array
 */
enum ArrayInsertPositions
{
    /* Indicates that the element should be inserted at the front of the array */
    Front,
    /* Indicates that the element should be inserted at the back of the array */
    Back
};

/**
 * @enum {Mode}
 * Represents the mode of the game
 */
enum Mode
{
    /* Interactive mode where user interaction is enabled */
    Interactive = 1,
    /* Silent mode where no user interaction is allowed */
    Silent = 2
};

/**
 * @enum {Scenario}
 * Represents different scenarios for the game
 */
enum Scenario
{
    /* Both players are strong */
    BothStrong = 1,
    /* Both players are weak */
    BothWeak = 2,
    /* Earth player is strong, alien player is weak */
    EarthStrongAlienWeak = 3,
    /* Earth player is weak, alien player is strong */
    EarthWeakAlienStrong = 4,
    /* Testing scenario for game structure */
    StructureTest = 0
};

/**
 * @enum {Simulation}
 * Represents the type of simulation for the game
 */
enum Simulation
{
    /* Grand simulation mode */
    Grand = 1,
    /* Simple simulation mode */
    Simple = 0
};

/**
 * @enum {UnitType}
 * Represents different types of units in the game
 */
enum UnitType
{
    /** Human soldier unit */
    HumanSoldierEnum,
    /** Human tank unit */
    HumanTankEnum,
    /* Human Gunnery Unit */
    HumanGunneryEnum,
    /** Human healer unit */
    HumanHealerEnum,
    /** Alien soldier unit */
    AlienSoldierEnum,
    /** Alien monster unit */
    AlienMonsterEnum,
    /** Alien drone unit */
    AlienDroneEnum
};

#endif // !Enums_H