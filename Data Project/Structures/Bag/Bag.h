#ifndef Bag_H
#define Bag_H

#include "../../Utils/Utils.h"

#include <iostream> 

constexpr int MaxSize = 500;

template <typename T>
class Bag
{
private:
	T* Array[MaxSize];
	int Count;
public:
	Bag() : Count(0) {
	}

	bool isFull() const {
		return this->Count >= MaxSize;
	}

	bool isEmpty() const {
		return this->Count == 0;
	}

	int GetCount() const {
		return this->Count;
	}

	bool Add(const T& NewElement) {
		if (isFull())
			return false;

		T* NewItem = new (std::nothrow) T(NewElement);

			if (NewItem == nullptr)
				return false;

		this->Array[this->Count] = NewItem;

		this->Count++;
		return true;
	}

	bool Remove(T& Removed) {
		if (isEmpty())
			return false;

		int RandomIndex = Utils::GenerateRandomNumber(0, this->Count - 1);

		Removed = *this->Array[RandomIndex];

		std::cout << Removed;

		//delete this->Array[RandomIndex];

	/*	if (this->Count > 1) {
			this->Array[RandomIndex] = this->Array[this->Count - 1];
			this->Array[this->Count - 1] = nullptr;
		}*/

		this->Count--;

		return true;
	}

	bool Peek(T& Peeked) {
		if (isEmpty())
			return false;

		int RandomIndex = Utils::GenerateRandomNumber(0, this->Count - 1);

		Peeked = *this->Array[RandomIndex];
		return true;
	}

	void Print() const {
		if (isEmpty()) 
			return;
		

		std::cout << "[";
		for (int i = 0; i < this->Count; ++i) {
			std::cout << *this->Array[i];
			if (i < this->Count - 1)
				std::cout << ", ";
		}
		std::cout << "]" << std::endl;
	}
};

#endif // Bag_H