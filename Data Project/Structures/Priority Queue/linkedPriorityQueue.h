#pragma once
#include "../Nodes/PriorityNode.h"

template <typename T>
class PriorityQueue
{
	PriorityNode<T> *head;
	int count;

public:
	PriorityQueue() : head(nullptr), count(0) {}

	/**
	 * Constructor that initializes the linked priority queue with a given head node
	 * @param {PriorityNode<T>*} head - The head node of the linked priority queue
	 */
	PriorityQueue(PriorityNode<T> *Head) : head(Head), count(0) {}

	/**
	 * Enqueues a new element according to its priority
	 * @param value The value of the element to be enqueued and priority of element
	 */
	void enqueue(const T &data, int priority)
	{
		PriorityNode<T> *newNode = new PriorityNode<T>(data, priority);
		// special case if it was empty or if the priority was greater than first element priority
		if (head == nullptr || priority > head->GetPriority())
		{
			newNode->SetNext(head);
			head = newNode;
			count++;
			return;
		}
		PriorityNode<T> *current = head;

		while (current->GetNext() && priority <= current->GetNext()->GetPriority())
			current = current->GetNext();
		// current is last element and prev is the element just before it or it reached point to insert new node

		// setting the element in order of priority
		if (current->GetNext())
		{
			newNode->SetNext(current->GetNext());
			current->SetNext(newNode);
			count++
		}
	}

	/**
	 * Dequeues an element from the front of the queue
	 * @param Value Reference to store the value of the dequeued element and Priority Refrence to store the priority of the dequeued element
	 * @return True if dequeuing was successful, false if the queue is empty
	 */
	bool dequeue(T &x, int &pri)
	{
		// if empty then it can't be dequeued
		if (isEmpty)
			return false;

		// x will hold the value of the dequeued element
		x = head->GetValue();
		// pri will holf the priority of the dequeued element
		pri = head->GetPriority();
		// storing the head in another node to delete it later
		PriorityNode<T> *tempNode = head;
		// removing the head without affecting the queue
		head = head->GetNext();
		// deleting the head
		delete tempNode;
		// returning that the element is dequeud successfully
		return true;
	}

	/**
	 * Checks if the pri-queue is empty or not
	 * @return True if it is empty, false if the pri-queue is not empty
	 */
	bool isEmpty()
	{
		// according to count we will return if it is empty or not ==> if count is 0 then it is empty , else it is not
		return count == 0;
	}

	/**
	 * Peeks an element from the front of the queue
	 * @param Value Reference to store the value of the dequeued element and Priority Refrence to store the priority of the dequeued element
	 * @return True if dequeuing was successful, false if the queue is empty
	 */
	bool peek(T &data, int &pri)
	{
		if (isEmpty)
			return false;

		// data will hold element on first element
		data = head->GetValue();
		// pri will store the priority of the first element
		pri = head->GetPriority();
		return true;
	}

	/*
	 * Prints the priority queue
	 */
	void print() const
	{
		if (isEmpty())
			return;

		PriorityNode<T> *current = head;

		while (current != nullptr)
		{
			std::cout << current->GetValue();

			if (current->GetNext() != nullptr)
				std::cout << " <- ";

			current = current->GetNext();
		}

		std::cout << " <- NULL" << std::endl;
	}

	~PriorityQueue()
	{
		PriorityNode<T> *current = head;
		while (current)
		{
			PriorityNode<T> *temp = current;
			current = current->GetNext();
			delete current;
		}
		head = nullptr;
		count = 0;
	}
};