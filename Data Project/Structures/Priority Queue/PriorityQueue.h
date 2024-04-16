#ifndef PriorityQueue_H
#define PriorityQueue_H

#include "../Nodes/PriorityNode.h"

template <typename T>
class PriorityQueue
{
private:
    /* Pointer to the head of the priority queue */
    PriorityNode<T>* Head;
    /* The number of elements in the priority queue */
    int Count;

public:
    /**
     * Checks if the priority queue is empty
     *
     * @return {bool} - True if the priority queue is empty, false otherwise
     */
    bool isEmpty() const
    {
        return this->Count == 0;
    }

    /**
     * Adds a new element to the priority queue with the given priority
     *
     * @param {T&} Value - The value to be added to the priority queue
     * @param {int} Priority - The priority of the value
     * @return {bool} - True if the operation was successful, false otherwise
     */
    bool enqueue(const T& Value, int Priority)
    {
        PriorityNode<T>* NewNode = new PriorityNode<T>(Value, Priority);

        // In-case an error occurs when adding we handle it
        try
        {
            // For when the queue is empty / the new node has a higher priority
            if (this->Head == nullptr || Priority > this->Head->GetPriority())
            {
                NewNode->SetNext(this->Head);
                this->Head = NewNode;
                this->Count++;
                return true;
            }
            else
            {
                // If not then we traverse the queue to find the correct position to add the new node

                PriorityNode<T>* Current = this->Head;

                while (Current->GetNext() != nullptr && Priority <= Current->GetNext()->GetPriority())
                    Current = Current->GetNext();

                NewNode->SetNext(Current->GetNext());
                Current->SetNext(NewNode);
                this->Count++;
                return true;
            }
        }
        // Idk what error type would come here but ig it's bad_alloc but I'm not sure so I used ...
        catch (...)
        {
            std::cout << "An error occurred while enqueuing in PriorityQueue" << std::endl;
            return false;
        }

        return true;
    }

    /**
     * Removes and returns the element with the highest priority from the priority queue
     *
     * @param {T&} Value - Reference to store the value of the removed element
     * @param {int&} Priority - Reference to store the priority of the removed element
     * @return {bool} - True if the operation was successful, false otherwise
     */
    bool dequeue(T& Value, int& Priority)
    {
        if (isEmpty())
            return false;

        Value = this->Head->GetValue();
        Priority = this->Head->GetPriority();

        PriorityNode<T>* Temp = this->Head;
        this->Head = this->Head->GetNext();
        delete Temp;
        this->Count--;
        return true;
    }

    /**
     * Retrieves the element with the highest priority from the priority queue without removing it
     *
     * @param {T&} Value - Reference to store the value of the element
     * @param {int&} Priority - Reference to store the priority of the element
     * @return {bool} - True if the operation was successful, false otherwise
     */
    bool peek(T& Value, int& Priority)
    {
        if (isEmpty())
            return false;

        Value = this->Head->GetValue();
        Priority = this->Head->GetPriority();

        return true;
    }

    /**
     * Prints the elements of the priority queue
     */
    void Print() const
    {
        if (isEmpty())
            return;

        PriorityNode<T>* Current = this->Head;

        std::cout << "[";

        while (Current != nullptr)
        {
            std::cout << Current->GetValue();

            if (Current->GetNext() != nullptr)
                std::cout << ", ";

            Current = Current->GetNext();
        }

        std::cout << "]" << std::endl;
    }

    /**
     * Returns the number of elements in the priority queue
     *
     * @return {int} - The number of elements in the priority queue
     */
    int GetCount() const
    {
        return this->Count;
    }

    /**
     * Clears the priority queue, removing all elements
     */
    void Clear()
    {
        while (this->Head)
        {
            PriorityNode<T>* Temp = this->Head;
            this->Head = this->Head->GetNext();
            delete Temp;
        }

        this->Head = nullptr;
        this->Count = 0;
    }

    /**
     * Destructor for the priority queue
     */
    ~PriorityQueue()
    {
        Clear();
    }
};

#endif // !PriorityQueue_H