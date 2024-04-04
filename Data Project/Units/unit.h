#pragma once
#include <iostream>
#include"../Game Manager/GameManager.h"

template<typename T>
class unit {
	GameManager* gManager;
	int power, health, attackCapacity, joinTime;
	int deletedEarthID[1000];
	int deletedAlienID[1000];
	std::string type;
	int earthID = 0; // static or keep them as int?
	int alienID = 1999;
protected:
	static int countOfunits = 0;

public:
	unit(std::string Type) :type(Type) {}

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
	void setHealth(int h) { health = h > 100 ? 100 : h; };

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
	void setEarthID() {
		/*for (int i = 0; i < 1000; i++) {
			if (deletedEarthID[i]) {				not completed yet
				earthID = deletedEarthID[i];
				return;
			}
		}*/
		if (earthID < 999 && earthID >= 0) earthID++;
	};


	/**
	 * Sets the value of the alien units id
	 * @returns {void}
	 */
	void setAlienID() {
		/*for (int i = 0; i < 1000; i++) {
			if (deletedAlienID[i]) {
				earthID = deletedAlienID[i];
				return;
			}
		}*/
		if (alienID < 2999 && earthID >= 1999) alienID++;
	};

	/**
	 * Gets the value of the power
	 * @returns {const int}
	 */
	int getPower() const { return power; };

	/**
	 * Gets the value of the healthe
	 * @returns {const int}
	 */
	int getHealth()const { return health; };

	/**
	 * Gets the value of the maximum attack capacity
	 * @returns {const int}
	 */
	int getAttackCapacity()const { return attackCapacity; };

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
	 * Gets the value of the earth id
	 * @returns {const int}
	 */
	int getEarthID()const { return earthID; };


	/**
	 * Gets the value of the alien id
	 * @returns {const int}
	 */
	int getAlienID()const { return alienID; };

	/**
	 * Print units --> virtual to be derived in units
	 * @returns {void}
	 */
	void print() = 0;

	/**
	 * Inserts an item to the unit
	 * @param {T} reference to item - The new item to be inserted.
	 * @returns {bool}
	 */
	bool insert(const T& item) = 0;

	/**
	 * Removes an item from the unit
	 * @param {T} reference to item - The new item to be removed.
	 * @returns {bool}
	 */
	bool remove(const T& item) = 0;

	/**
	 * Picks an item from the unit
	 * @param {T} refrence to item - The item holds the one that should to be picked.
	 * @returns {bool}
	 */
	bool pick(const T& item) = 0;


	/**
	 * Move an item from the unit to killed list
	 * @param {T} item - The item holds the one that should be moved to killed list.
	 * @returns {bool}
	 */
	bool moveToKilledList(T item) = 0;//not sure of the param and the functionality itself if it is right to be here or not
	//friend std::ostream& operator <<(std::ostream& output, const unit<T>& ut);


	/**
	 * Stores ids of deleted earth objects
	 * @param {int} id - id to be deleted
	 * @returns {void}
	 */
	void deleteEarthID(int id) {
		int i = 0;
		while (deletedEarthID[i]) i++;
		deletedEarthID[i] = id;
	}



	/**
	 * Stores ids of deleted alien objects
	 * @param {int} id - id to be deleted
	 * @returns {void}
	 */
	void deleteAlienID(int id) {
		int i = 0;
		while (deletedAlienID[i]) i++;
		deletedAlienID[i] = id;
	}
};



//operator overloading if needed ... implementation not complete
//template<typename T>
//std::ostream& operator <<(std::ostream& output, unit<T>& ut) {
//	output << ;
//	//return output;
//}