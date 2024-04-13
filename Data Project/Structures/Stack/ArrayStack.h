//	This is an updated version of code originally
//  created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT stack: Array-based implementation.
 @file ArrayStack.h */

#ifndef ARRAY_STACK_
#define ARRAY_STACK_

#include "../ADTs/StackADT.h"

 // Unless specified by the stack user, the default size is 100
template <typename T>
class ArrayStack : public StackADT<T>
{
	enum
	{
		MAX_SIZE = 100
	};

private:
	T items[MAX_SIZE]; // Array of stack items
	int top;		   // Index to top of stack
	int count;			// number of items in stack

public:
	/**
	 * Constructor that initializes the stack with a given top
	 * @param {T} item - The top item of the stack
	 */
	ArrayStack()
	{
		top = -1;
	} // end default constructor

	ArrayStack(T item) : top(0)
	{
		items[top] = item;
	}


	/**
	 * Returns if the stack is empty
	 * @returns {boolean} - True if the stack is empty, False otherwise
	 */
	bool isEmpty() const
	{
		return top == -1;
	} // end isEmpty


	/**
	 * Returns if the stack is full
	 * @returns {boolean} - True if the stack is full, False otherwise
	 */
	bool isFull() {
		return top == MAX_SIZE - 1;
	}


	/**
	 * Pushes a new elemenet to the stack and increments top
	 * @param {T} newEntry - the value of the element to be pushed
	 * @returns {boolean} - True if the operation is successful, false otherwise
	 */
	bool push(const T& newEntry)
	{
		// Special case if Stack is full
		if (top == MAX_SIZE - 1)
			return false; // Stack is FULL

		top++;
		count++;
		items[top] = newEntry;
		return true;
	} // end push


	/**
	 * Pops the top element of the stack and decrements top
	 * @param {T} TopEntry - Reference to store the value of the popped element
	 * @returns {boolean} - True if the operation is successful, false otherwise
	 */
	bool pop(T& TopEntry)
	{
		// Special case if stack is empty
		if (isEmpty())
			return false; // Stack is EMPTY

		TopEntry = items[top];
		top--;
		count--;
		return true;
	} // end pop


	/**
	 * Retrieves the top element of the stack without removing it
	 * @param {T} TopEntry - Reference to store the value of the popped element
	 * @returns {boolean} - True if the operation is successful, false otherwise
	 */
	bool peek(T& TopEntry) const
	{
		// Special case if stack is empty
		if (isEmpty())
			return false; // Stack is EMPTY

		TopEntry = items[top];
		return true;
	} // end peek


	/**
	 * Prints the stack
	 * @param {void}
	 * @returns {void}
	 */
	void print() const
	{
		// Special case if stack is empty
		if (isEmpty())
			return; // Stack is EMPTY

		for (int i = 0; i < top + 1; i++)
		{
			std::cout << items[i] << "<-";
		}
		std::cout << "NULL";
	}


	/**
	 * Clears the contents of the stack by resetting the top to -1
	 * @param {void}
	 * @returns {void}
	 */
	void clear()
	{
		top = -1;
	}


	/**
	* Gets how many items are there in the list
	* @return {int} - number of items
	*/
	int getCount() {
		return count;
	}


	/**
	 * Destructor that calls function clear to remove all elements in stack
	 */
	~ArrayStack()
	{
		clear();
	}
}; // end ArrayStack

#endif