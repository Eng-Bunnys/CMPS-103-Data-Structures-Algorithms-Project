#ifndef Bag_H
#define Bag_H

#define MAX 100

#include <iostream>
#include "../../Enums/Enums.h"

std::string MaxSizeError = "Array size exceeds maximum allowed size.";
std::string EmptyArrayError = "Cannot remove an element from an empty array.";

template <typename T>
class Bag
{
private:
	T** Array;
	int Size;

public:
	Bag(int Size)
	{
		this->Size = MAX < Size ? MAX : Size;
		Array = new T * [this->Size];
	}

	/**
	 * Inserts a new element into the Bag at the specified position.
	 * @param {T} NewElement - The element to insert.
	 * @param {ArrayInsertPositions} Position - The position to insert the element (Front or Back).
	 */
	void Insert(const T& NewElement, ArrayInsertPositions Position)
	{
		if (Position == ArrayInsertPositions::Front)
			InsertFront(NewElement);
		else
			InsertBack(NewElement);
	}

	/**
	 * Checks if the Bag is empty.
	 * @returns bool
	 */
	bool isEmpty()
	{
		return !(Size > 0);
	}

	/**
	 * Prints the elements of the Bag.
	 */
	void Print() const {
		std::cout << "Bag Contents:" << std::endl;
		for (int i = 0; i < Size; ++i) {
			std::cout << *Array[i] << " ";
		}
		std::cout << std::endl;
	}

	/**
	 * Removes the specified element from the Bag.
	 * Throws a runtime error if the Bag is empty.
	 * @param {T} element - The element to remove.
	 */
	void Remove(const T& element) noexcept(false) {
		if (isEmpty())
			throw std::runtime_error(EmptyArrayError);

		int index = -1;
		for (int i = 0; i < Size; i++) {
			if (*Array[i] == element) {
				index = i;
				break;
			}
		}

		if (index != -1) {
			delete Array[index];
			for (int i = index; i < Size - 1; i++) {
				Array[i] = Array[i + 1];
			}
			Size--;
		}
	}

	/**
	 * Counts the occurrences of a specific element in the Bag.
	 * @param {T} element - The element to count.
	 * @returns int - The count of the element in the Bag.
	 */
	int getCount(const T& Element) const {
		int count = 0;
		for (int i = 0; i < Size; i++) {
			if (*Array[i] == Element) {
				count++;
			}
		}
		return count;
	}

	~Bag()
	{
		for (int i = 0; i < Size; i++)
			delete Array[i];

		delete[] Array;
	}

private:
	/**
	 * Inserts a new element at the front of the Bag.
	 * Throws a runtime error if the Bag size exceeds the maximum allowed size.
	 * @param {T} NewElement - The element to insert.
	 */
	void InsertFront(const T& NewElement) noexcept(false)
	{
		if (Size + 1 > MAX)
			throw std::runtime_error(MaxSizeError);

		Array[Size] = Array[0];
		Array[0] = NewElement;
		Size++;
	}

	/**
	 * Inserts a new element at the back of the Bag.
	 * Throws a runtime error if the Bag size exceeds the maximum allowed size.
	 * @param {T} NewElement - The element to insert.
	 */
	void InsertBack(const T& NewElement) noexcept(false)
	{
		if (Size + 1 > MAX)
			throw std::runtime_error(MaxSizeError);

		Array[Size] = NewElement;
		Size++;
	}
};

#endif // !Bag_H