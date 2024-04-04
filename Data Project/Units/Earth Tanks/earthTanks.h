#pragma once
#include"../unit.h"
#include"../../Structures/Stack/ArrayStack.h"

template<typename T>
class earthTanks :public unit<T> {
	ArrayStack<T>* tank;
	static int ETcount = 0;
public:


	/**
	 * Removes an item from the unit
	 * @param {T} item - The new item to be removed.
	 * @returns {bool}
	 */
	bool remove(const T& item) {
		if (tank->pop(item)) {
			ETcount--;
			countOfunits--;
			return true;
		}
		//deleteEarthID(getEarthID());		waiting for doc answer
		return false;
	}


	/**
	 * Inserts an item to the unit
	 * @param {T} item - The new item to be added.
	 * @returns {bool}
	 */
	bool insert(const T& item) {
		setEarthID();
		tank->push(item);
		countOfunits++;
		ETcount++;

		return true;
	}


	/**
	 * Picks an item from the unit
	 * @param {T} refrence to item - The item holds the one that should to be picked.
	 * @returns {bool}
	 */
	 /*bool pick(const T& item) {
		 return tank->peek(item);    I am not sure yet of this
	 }*/


	 /**
	  * Print details in the earth tank units
	  * @returns {void}
	  */
	void print() {
		std::cout << "Health of tank = " << getHealth();
		std::cout << "\nPower of tank = " << getPower();
		std::cout << "\nMaximum attack capacity of tank = " << getAttackCapacity();
		std::cout << "\nID of tank = " << getEarthID();
		std::cout << "\nJoin time of tank = " << getJoinTime() << std::endl;
	}



	/**
	 * Gets count of items in earth tank unit
	 * @returns {int}
	 */
	int getNumberOfTanks() {
		return ETcount;
	}


	/**
	 * Moves an item from the unit to killed list
	 * @param {T} item - indicates the item is moved to killed list or not , if it should be moved then it moves it.
	 * @returns {bool}
	 */
	bool moveToKilledList(T item) {
		if (item.getHealth() <= 0) return true; // requires moving to killed list .. code not complete
		return false
	}

};