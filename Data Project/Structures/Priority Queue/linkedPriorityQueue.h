#pragma once
#include<iostream>
#include "../Nodes/PriorityNode.h"

template <typename T>
class PriorityQueue {
    PriorityNode<T>* head; // Pointer to the head node of the priority queue
    int count;             // Number of elements in the priority queue

public:
    PriorityQueue() : head(nullptr), count(0) {}

    /**
     * Constructor that initializes the linked priority queue with a given head node
     * @param {PriorityNode<T>*} head - The head node of the linked priority queue
     */
    PriorityQueue(PriorityNode<T>* Head) : head(Head), count(0) {}

    /**
     * Enqueues a new element according to its priority
     * @param data The value of the element to be enqueued.
     * @param priority The priority of the element to be enqueued.
     * @return bool - True if the enqueue operation was successful, false otherwise.
     */
    bool enqueue(const T& data, int priority) {
        PriorityNode<T>* newNode = new PriorityNode<T>(data, priority);
        if (head == nullptr || priority > head->GetPriority()) {
            newNode->SetNext(head);
            head = newNode;
            count++;
            return true;
        }
        PriorityNode<T>* current = head;

        while (current->GetNext() && priority <= current->GetNext()->GetPriority())
            current = current->GetNext();

        if (current->GetNext()) {
            newNode->SetNext(current->GetNext());
            current->SetNext(newNode);
            count++;
            return true;
        }
        return false;
    }

    /**
     * Dequeues an element from the front of the queue
     * @param x Reference to store the value of the dequeued element.
     * @param pri Reference to store the priority of the dequeued element.
     * @return bool - True if dequeuing was successful, false if the queue is empty.
     */
    bool dequeue(T& x, int& pri) {
        if (isEmpty())
            return false;

        x = head->GetValue();
        pri = head->GetPriority();
        PriorityNode<T>* tempNode = head;
        head = head->GetNext();
        delete tempNode;
        return true;
    }

    /**
     * Checks if the priority queue is empty or not
     * @return bool - True if it is empty, false otherwise.
     */
    bool isEmpty() const {
        return count == 0;
    }

    /**
     * Peeks an element from the front of the queue
     * @param data Reference to store the value of the peeked element.
     * @param pri Reference to store the priority of the peeked element.
     * @return bool - True if peeking was successful, false if the queue is empty.
     */
    bool peek(T& data, int& pri) const {
        if (isEmpty())
            return false;

        data = head->GetValue();
        pri = head->GetPriority();
        return true;
    }

    /**
     * Prints the priority queue
     */
    void print() const {
        if (isEmpty())
            return;

        PriorityNode<T>* current = head;

        while (current != nullptr) {
            std::cout << current->GetValue();

            if (current->GetNext() != nullptr)
                std::cout << " <- ";

            current = current->GetNext();
        }

        std::cout << " <- NULL" << std::endl;
    }

    /**
     * Gets the number of items in the priority queue.
     * @return int - The number of items in the priority queue.
     */
    int getCount() const {
        return count;
    }

    ~PriorityQueue() {
        PriorityNode<T>* current = head;
        while (current) {
            PriorityNode<T>* temp = current;
            current = current->GetNext();
            delete temp;
        }
        head = nullptr;
        count = 0;
    }
};