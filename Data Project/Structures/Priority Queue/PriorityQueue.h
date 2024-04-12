#ifndef PriorityQueue_H
#define PriorityQueue_H

#include "../Nodes/PriorityNode.h"

template <typename T>
class PriorityQueue
{
	/**
	 *  Pointer to the head node of the priority queue.
	 */
	PriorityNode<T> *Head;

	/**
	 *  Number of nodes in the priority queue.
	 */
	int Count;

public:
	/**
	 *  Default constructor that initializes an empty linked priority queue.
	 */
	PriorityQueue() : Head(nullptr), Count(0) {}

	/**
	 *  Constructor that initializes the linked priority queue with a given head node.
	 *
	 * @param {PriorityNode<T>*} head - The head node of the linked priority queue.
	 */
	PriorityQueue(PriorityNode<T> *Head) : Head(Head), Count(0) {}

	/**
	 *  Enqueues a new element into the priority queue with the given priority.
	 *
	 * @param U Type of the priority.
	 * @param {T&} Value - The value to be enqueued.
	 * @param {double} Priority - The priority of the value.
	 */
	void enqueue(const T &Value, double Priority)
	{
		PriorityNode<T> *NewNode = new PriorityNode<T>(Value, Priority);
		if (this->Head == nullptr || Priority > this->Head->GetPriority())
		{
			NewNode->SetNext(Head);
			this->Head = NewNode;
			this->Count++;
			return;
		}
		PriorityNode<T> *Current = this->Head;

		while (Current->GetNext() && Priority <= Current->GetNext()->GetPriority())
			Current = Current->GetNext();

		if (Current->GetNext())
		{
			NewNode->SetNext(Current->GetNext());
			Current->SetNext(NewNode);
			this->Count++;
		}
	}

	/**
	 * Dequeues an element from the priority queue.
	 *
	 * @param U Type of the priority.
	 * @param {T&} Value - Reference to store the dequeued value.
	 * @param {double&} Priority - Reference to store the priority of the dequeued value.
	 * @return {bool} - True if dequeue operation is successful, false otherwise.
	 */

	bool dequeue(T &Value, double &Priority)
	{
		if (isEmpty())
			return false;

		Value = this->Head->GetValue();
		Priority = this->Head->GetPriority();
		PriorityNode<T> *Temp = Head;
		this->Head = this->Head->GetNext();
		delete Temp;
		return true;
	}

	/**
	 *  Checks if the priority queue is empty.
	 *
	 * @return {bool} - True if the priority queue is empty, false otherwise.
	 */
	bool isEmpty()
	{
		return this->Count == 0;
	}

	/**
	 *  Retrieves the element at the front of the priority queue without removing it.
	 *
	 * @param U Type of the priority.
	 * @param {T&} Value - Reference to store the value at the front.
	 * @param {double&} Priority - Reference to store the priority of the value at the front.
	 * @return {bool} - True if the operation is successful, false if the queue is empty.
	 */

	bool peek(T &Value, double&Priority)
	{
		if (isEmpty)
			return false;

		Value = this->Head->GetValue();
		Priority = this->Head->GetPriority();
		return true;
	}

	/**
	 *  Prints the elements of the priority queue.
	 */
	void print() const
	{
		if (isEmpty())
			return;

		PriorityNode<T> *Current = this->Head;

		while (Current != nullptr)
		{
			std::cout << Current->GetValue();

			if (Current->GetNext() != nullptr)
				std::cout << " <- ";

			Current = Current->GetNext();
		}

		std::cout << " <- NULL" << std::endl;
	}

	/**
	 * Clears the priority queue.
	 */
	void Clear()
	{
		PriorityNode<T> *Current = this->Head;
		while (Current)
		{
			PriorityNode<T> *Temp = Current;
			Current = Current->GetNext();
			delete Current;
		}
		this->Head = nullptr;
		this->Count = 0;
	}

	/*
	 * Returns the number of nodes
	 */
	void GetCount() const
	{
		return this->Count;
	}

	/**
	 * Destructor to clean up memory.
	 */
	~PriorityQueue()
	{
		Clear();
	}
};

#endif // !PriorityQueue_H