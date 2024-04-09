#pragma once
#include <iostream>
#include "../Game Manager/GameManager.h"

class unit
{
	GameManager *gManager;
	int power, attackCapacity, joinTime , battleTime;
	int health;
	//int deletedEarthID[1000];
	//int deletedAlienID[1000];
	std::string type;
	const int id; // const to be unchanged
	

protected:
	//static int countOfunits = 0;

public:
	unit(std::string Type , int ID) : type(Type ) , id(ID) {}

	unit(int ID, std::string t, int jt, int h, int p, int attCap): id(ID) {
		 
		type = t; 
		health = h; 
		power = p;
		attackCapacity = attCap;
		joinTime = jt;
	}

	
	/**
	 * Sets the value of the power
	 * @param int p - The new value to set for the power.
	 * @returns {void}
	 */
	void setPower(int p) { power = p; };

	/**
	 * Sets the value of the health
	 * @param int h - The new value to set for the health.
	 * @returns {void}
	 */
	void setHealth(double h) { health = h > 100 ? 100 : h; };

	/**
	 * Sets the value of the maximum attck capacity
	 * @param int cap - The new value to set for the maximum attacj capacity.
	 * @returns {void}
	 */
	void setAttackCapacity(int cap) { attackCapacity = cap; };

	/**
	 * Sets the value of the join time
	 * @param int jt - The new value to set for the join time.
	 * @returns {void}
	 */
	void setJoinTime(int jt) { joinTime = jt; };

	/**
	 * Sets the value of the type
	 * @param string t - The new value to set for the type.
	 * @returns {void}
	 */
	void setType(std::string t) { type = t; };

	/**
	 * Sets the value of the earth units id
	 * @returns {void}
	 */
	

	

	/**
	 * Gets the value of the power
	 * @returns {const int}
	 */
	int getPower() const { return power; };

	/**
	 * Gets the value of the healthe
	 * @returns {const int}
	 */
	double getHealth() const { return health; };

	/**
	 * Gets the value of the maximum attack capacity
	 * @returns {const int}
	 */
	int getAttackCapacity() const { return attackCapacity; };

	/**
	 * Gets the value of the join time
	 * @returns {const int}
	 */
	int getJoinTime() const { return joinTime; };

	/**
	 * Gets the value of the type
	 * @returns {const string}
	 */
	std::string getType() const { return type; };

	/**
	 * Gets the value of the unit id
	 * @returns {const int}
	 */
	const int getID() const { 
		
		return id; 
	
	};

	/**
	 * Print unit details
	 * @returns {void}
	 */
	void print() {
		std::cout << "Health of unit = " << getHealth();
		std::cout << "\nPower of unit = " << getPower();
		std::cout << "\nMaximum attack capacity of unit = " << getAttackCapacity();
		std::cout << "\nID of tank = " << getID();
		std::cout << "\nJoin time of unit = " << getJoinTime() << std::endl;
	}

	
};

// operator overloading if needed ... implementation not complete
// template<typename T>
// std::ostream& operator <<(std::ostream& output, unit<T>& ut) {
//	output << ;
//	//return output;
// }