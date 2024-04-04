/*
To-Do:
Print
Remove
*/
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
	T **Array;
	int Size;

public:
	Bag(int Size)
	{
		this->Size = MAX > Size ? MAX : Size;
		Array = new T *[Size];

		for (int i = 0; i < Size; i++) Array[i] = nullptr;
	}

	/**
	 * Inserts a new element into the Bag at the specified position.
	 * @param {T} NewElement - The element to insert.
	 * @param {ArrayInsertPositions} Position - The position to insert the element (Front or Back).
	 */
	void Insert(T NewElement, ArrayInsertPositions Position)
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
	void InsertFront(T &NewElement) noexcept(false)
	{
		if (Size + 1 > MAX)
			throw std::runtime_error(MaxSizeError);

		Array[Size] = Array[0];
		Array[0] = &NewElement;
		Size++;
	}

	/**
	 * Inserts a new element at the back of the Bag.
	 * Throws a runtime error if the Bag size exceeds the maximum allowed size.
	 * @param {T} NewElement - The element to insert.
	 */
	void InsertBack(T &NewElement) noexcept(false)
	{
		if (Size + 1 > MAX)
			throw std::runtime_error(MaxSizeError);

		Array[Size] = &NewElement;
		Size++;
	}
};

#endif // !Bag_H