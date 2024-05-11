#ifndef Bag_H
#define Bag_H

#include "../../Utils/Utils.h"

#include <iostream>

constexpr int MaxSize = 500;

template <typename T>
class Bag
{
private:
	T *Elements[MaxSize];
	int Count;
public:
	Bag() : Count(0)
	{
		for (int i = 0; i < MaxSize; i++)
			Elements[i] = nullptr;
	}

	bool isFull() const
	{
		return this->Count >= MaxSize;
	}

	bool isEmpty() const
	{
		return this->Count == 0;
	}

	int GetCount() const
	{
		return this->Count;
	}

	bool Add(const T &NewElement)
	{
			if (isFull())
				return false;

			T* NewItem = new (std::nothrow) T(NewElement);

			if (NewItem == nullptr)
				return false;

			this->Elements[this->Count] = NewItem;

			this->Count++;
			return true;
	}

	bool Remove(T& RemovedElement) {
		if (isEmpty())
			return false;

		int RandomNumber = Utils::GenerateRandomNumber(0, this->Count - 1);;

		RemovedElement = *Elements[RandomNumber];

		Elements[RandomNumber] = Elements[Count - 1];

		Elements[Count - 1] = nullptr;

		this->Count--;

		return true;
	}

	bool Peek(T& PeekedElement) const {
		if (isEmpty())
			return false;

		PeekedElement = *this->Elements[0];
		return true;
	}

	void Print() const {
		if (isEmpty())
			return;

		std::cout << "[";

		for (int i = 0; i < this->Count; ++i) {
			std::cout << *this->Elements[i];
			if (i < this->Count - 1)
				std::cout << ", ";
		}
		std::cout << "]" << std::endl;
	}
};

#endif // Bag_H