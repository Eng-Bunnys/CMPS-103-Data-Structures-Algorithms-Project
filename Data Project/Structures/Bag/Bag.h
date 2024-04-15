#ifndef Bag_H
#define Bag_H

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

		if (isEmpty())
			this->Array[0] = new T(NewElement);
		else {
			this->Array[this->Count] = new T(NewElement);
		}

		this->Count++;
		return true;
	}

	T Remove(int Index = 0) {
		if (isEmpty() || (Index < 0 || Index >= Count))
			return T{};

		T Removed = *this->Array[Index];

		delete this->Array[Index];

		for (int i = Index; i < this->Count - 1; i++) {
			this->Array[i] = this->Array[i + 1];
		}
		this->Count--;

		return Removed;
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