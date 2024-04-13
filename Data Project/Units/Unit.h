#pragma once
#include <iostream>
//#include "../Game Manager/GameManager.h"

class unit
{
protected:
	//GameManager* gManager = nullptr;
	int power = 100, attackCapacity = 100, joinTime = 0, battleTime = 0;
	double health = 0.0;
	//int deletedEarthID[1000];
	//int deletedAlienID[1000];
	std::string type = "unit";
	const int id; // const to be unchanged



	//static int countOfunits = 0;

public:
	unit(int ID);

	unit(int ID, int attCap, int jt, int p, double h);


	/**
	 * Sets the value of the power
	 * @param int p - The new value to set for the power.
	 * @returns {void}
	 */
	void setPower(int p);

	/**
	 * Sets the value of the health
	 * @param int h - The new value to set for the health.
	 * @returns {void}
	 */
	void setHealth(double h);

	/**
	 * Sets the value of the maximum attck capacity
	 * @param int cap - The new value to set for the maximum attacj capacity.
	 * @returns {void}
	 */
	void setAttackCapacity(int cap);

	/**
	 * Sets the value of the join time
	 * @param int jt - The new value to set for the join time.
	 * @returns {void}
	 */
	void setJoinTime(int jt);

	/**
	 * Sets the value of the type
	 * @param string t - The new value to set for the type.
	 * @returns {void}
	 */
	void setType(std::string t);

	/**
	 * Gets the value of the power
	 * @returns {const int}
	 */
	int getPower() const;

	/**
	 * Gets the value of the healthe
	 * @returns {const int}
	 */
	double getHealth() const;

	/**
	 * Gets the value of the maximum attack capacity
	 * @returns {const int}
	 */
	int getAttackCapacity() const;

	/**
	 * Gets the value of the join time
	 * @returns {const int}
	 */
	int getJoinTime() const;

	/**
	 * Gets the value of the type
	 * @returns {const string}
	 */
	std::string getType() const;

	/**
	 * Gets the value of the unit id
	 * @returns {const int}
	 */
	const int getID() const;

	/**
	 * Print unit details
	 * @returns {void}
	 */
	void virtual print();

	int getBattleTime();
};

// operator overloading if needed ... implementation not complete
// template<typename T>
// std::ostream& operator <<(std::ostream& output, unit<T>& ut) {
//	output << ;
//	//return output;
// }