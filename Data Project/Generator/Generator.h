#ifndef Generator_H
#define Generator_H

#include "../../Enums/Enums.h"

/**
 * Struct to store parameters for army units
 * @typedef {Object} ArmyParameters
 */
struct ArmyParameters
{
    /* The minimum health of the army units */
    double MinHealth;
    /* The maximum health of the army units */
    double MaxHealth;
    /* The minimum power of the army units */
    int MinPower;
    /* The maximum power of the army units */
    int MaxPower;
    /* The minimum attack capacity of the army units */
    int MinAttackCapacity;
    /*The maximum attack capacity of the army units */
    int MaxAttackCapacity;
};

class GameManager;
/**
 * Class representing a Generator for army units
 */
class Generator
{
private:
    /*Pointer to the game manager instance */
    GameManager *Game;

    /// Probability Parameters
    /*Parameters for Earth army units generation probability */
    int GenerationProbability;
    /* Parameters for the number of units to generate */
    int GenerationCount;

    /// General Unit Parameters
    /* Parameters for Earth army units */
    ArmyParameters EarthArmyParameters;
    /* Parameters for Alien army units */
    ArmyParameters AlienArmyParameters;

    /// Earth Unit Parameters
    /*  Percentage of Earth soldiers */
    int EarthSoldierPercentage;
    /* Percentage of Earth tanks */
    int EarthTankPercentage;
    /* Percentage of Earth gunnery */
    int EarthGunneryPercentage;

    /// Alien Unit Parameters
    /* Percentage of Alien soldiers */
    int AlienSoldierPercentage;
    /*  Percentage of Alien monsters */
    int AlienMonsterPercentage;
    /* Percentage of Alien drones */
    int AlienDronePercentage;

    bool ValidatePercentage(int Percentage)
    {
        return Percentage >= 0 && Percentage <= 100;
    }

    template <typename T = int>
    bool ValidateParamRange(T Min, T Max)
    {
        return Min >= 0 && Max >= Min;
    }

public:
    /**
     * Constructor for Generator class
     *
     * @param {GameManager*} Game - Pointer to the game manager instance
     */
    Generator(GameManager *Game) {}

    /**
     * Assigns general unit parameters
     *
     * @param {number} UnitCount - Number of units to generate
     * @param {number} Probability - Probability of generation
     * @returns {boolean} - True if assignment successful, false otherwise
     */
    bool AssignGeneral(int UnitCount, int Probability);

    /**
     * Assigns Earth unit parameters
     *
     * @param {number} EarthSoldier - Number of Earth soldiers
     * @param {number} EarthTank - Number of Earth tanks
     * @param {number} EarthGunnery - Number of Earth gunnery
     * @param {number[]} Health - Array of health values
     * @param {number[]} Power - Array of power values
     * @param {number[]} AttackCapacity - Array of attack capacity values
     * @returns {boolean} - True if assignment successful, false otherwise
     */
    bool AssignEarth(int EarthSoldier, int EarthTank, int EarthGunnery, double Health[], int Power[], int AttackCapacity[]);

    /**
     * Assigns Alien unit parameters
     *
     * @param {number} AlienSoldier - Number of Alien soldiers
     * @param {number} AlienMonster - Number of Alien monsters
     * @param {number} AlienDrone - Number of Alien drones
     * @param {number[]} Health - Array of health values
     * @param {number[]} Power - Array of power values
     * @param {number[]} AttackCapacity - Array of attack capacity values
     * @returns {boolean} - True if assignment successful, false otherwise
     */
    bool AssignAlien(int AlienSoldier, int AlienMonster, int AlienDrone, double Health[], int Power[], int AttackCapacity[]);

    /**
     * Generates army units based on assigned parameters
     *
     * @returns {boolean} - True if generation successful, false otherwise
     */
    bool Generate();
};

#endif // !Generator_H
