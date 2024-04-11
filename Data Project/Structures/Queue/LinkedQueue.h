#ifndef LinkedQueue_H
#define LinkedQueue_H

#include "../Nodes/Node.h"
#include "../ADTs/QueueADT.h"

template <typename T>
class LinkedQueue : public QueueADT<T>
{
private:
	/* Pointer to the first node */
	Node<T> *Head;
	/* Pointer to the last node */
	Node<T> *Tail;
	/* The number of nodes in the queue */
	int Count;

public:
	LinkedQueue() : Head(nullptr), Tail(nullptr), Count(0) {}
	/**
	 * Constructor that initializes the linked queue with a given head node
	 * @param {Node<T>*} Head - The head node of the linked queue
	 */
	LinkedQueue(Node<T> *Head) : Head(Head), Tail(nullptr), Count(1)
	{
		this->Head->SetNext(nullptr);
	}

	/**
	 * Constructor that initializes the linked queue with a single node containing the given value
	 * @param {T} HeadValue - The value for the head node of the linked queue
	 */
	LinkedQueue(const T &HeadValue)
	{
		Node<T> *HeadNode = new Node<T>(HeadValue);

		this->Head = HeadNode;
		this->Head->SetNext(nullptr);
		this->Count++;
	}

	/**
	 * Constructor that initializes the linked queue with head and tail nodes containing the given values
	 * @param {T} HeadValue - The value for the head node of the linked queue
	 * @param {T} TailValue - The value for the tail node of the linked queue
	 */
	LinkedQueue(const T &HeadValue, const T &TailValue)
	{
		Node<T> *HeadNode = new Node<T>(HeadValue);
		Node<T> *TailNode = new Node<T>(TailValue);

		this->Head = HeadNode;
		this->Head->SetNext(TailNode);
		this->Tail = TailNode;
		this->Tail->SetNext(nullptr);
		this->Count++;
	}

	/**
	 * Deep copy constructor
	 * Creates a new instance of the queue with a deep copy of the elements
	 * @param {LinkedQueue<T>} OtherList - The queue to be copied
	 */
	LinkedQueue(const LinkedQueue &OtherList) : Head(nullptr), Tail(nullptr)
	{
		// Adjusting the count
		Count += OtherList.Count;

		// Pointers for traversal
		Node<T> *CurrentOther = OtherList.Head;
		Node<T> *PreviousCopy = nullptr;

		// Traverse the other queue and copy each node
		while (CurrentOther != nullptr)
		{
			// Create a new node for the copy
			Node<T> *NewNode = new Node<T>(CurrentOther->GetValue());

			// If it's the first node, set it as the head
			if (Head == nullptr)
				Head = NewNode;
			// Link the previous node to the new node
			else
				PreviousCopy->SetNext(NewNode);

			// Update the tail
			Tail = NewNode;

			// Move to the next node in the other queue
			CurrentOther = CurrentOther->GetNext();
			// Update the previous copy node
			PreviousCopy = NewNode;
		}
	}

	/**
	 * Enqueues a new element at the back of the queue
	 * @param {T} NewElement - The value of the element to be enqueued
	 * @returns {boolean} - True if the operation is successful, false otherwise
	 */
	bool enqueue(const T &NewElement) override
	{
		// Create a new node with the given value
		Node<T> *NewNode = new Node<T>(NewElement);

		// If the queue is empty, set both head and tail to the new node
		if (isEmpty())
			Head = Tail = NewNode;
		else
		{
			// Otherwise, link the current tail to the new node and update the tail pointer
			Tail->SetNext(NewNode);
			Tail = NewNode;
		}
		Count++;
		return true;
	}

	/**
	 * Dequeues an element from the front of the queue
	 * @param {T} Value - Reference to store the value of the dequeued element
	 * @returns {boolean} - True if dequeuing was successful, false if the queue is empty
	 */
	bool dequeue(T &Value)
	{
		// If the queue is empty, return false
		if (isEmpty())
			return false;

		// Store the value of the head node
		Value = Head->GetValue();

		// Move the head pointer to the next node
		Node<T> *Temp = Head;
		Head = Head->GetNext();

		// If the queue becomes empty after dequeuing, update the tail pointer to null
		if (!Head)
			Tail = nullptr;

		Count--;
		delete Temp;
		return true;
	}

	/**
	 * Retrieves the element at the front of the queue without removing it
	 * @param {T} FrontElement - Reference to store the value of the front element
	 * @returns {boolean} - True if the operation is successful (queue is not empty), false otherwise
	 */
	bool peek(T &FrontElement) const override
	{
		// If the queue is empty, return false
		if (isEmpty())
			return false;

		// Set the value to the data of the head node
		FrontElement = Head->GetValue();
		return true;
	}

	/*
	 * Returns if the queue is empty
	 * @returns {boolean} - True if the queue is empty, False otherwise
	 */

	bool isEmpty() const override
	{
		return !(Count > 0);
	}

	/**
	 * Prints the queue
	 * @param {void}
	 * @returns {void}
	 */
	void print() const
	{
		if (isEmpty())
			return;

		Node<T> *Current = Head;

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
	 * Clears the contents of the queue by deallocating memory for each node and resetting the queue's state.
	 * @param {void}
	 * @returns {void}
	 */
	void clear()
	{
		// Start from the head of the queue
		Node<T> *Current = Head;

		// Iterate through the queue and deallocate memory for each node
		while (Current != nullptr)
		{
			Node<T> *temp = Current;
			Current = Current->GetNext();
			delete temp;
		}

		// Reset Head, Tail, and Count to nullptr and 0 respectively
		Head = Tail = nullptr;
		Count = 0;
	}

	~LinkedQueue()
	{
		clear();
	}
};

#endif // !LinkedQueue_H