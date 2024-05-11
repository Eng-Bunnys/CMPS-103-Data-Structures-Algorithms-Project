#ifndef Deque_H
#define Deque_H

#include "../Nodes/DoublyNode.h"
#include "../ADTs/QueueADT.h"

template <typename T>
class Deque : public QueueADT<T>
{
private:
    /* The Head of the Deque */
    DoublyNode<T>* Head;
    /* The Tail of the Deque */
    DoublyNode<T>* Tail;
    /* The number of nodes in the Deque */
    int Count = 0;

public:
    Deque() : Head(nullptr), Tail(nullptr), Count(0) {}
    Deque(DoublyNode<T>* Head, DoublyNode<T>* Tail) : Head(Head), Tail(Tail), Count(2) {}
    Deque(const T& Head, const T& Tail)
    {
        DoublyNode<T>* HeadNode = new DoublyNode<T>(Head);
        DoublyNode<T>* TailNode = new DoublyNode<T>(Tail);

        HeadNode->SetNext(TailNode);
        TailNode->SetBack(HeadNode);
        this->Head = HeadNode;
        this->Tail = TailNode;
        this->Count = 2;
    }

    /**
     * Adds an element to the front of the Deque.
     * @param {T} NewElement - The element to be added.
     * @returns {boolean} True if the operation is successful, false otherwise.
     */
    bool EnqueueFront(const T& NewElement)
    {
        // Creating a new doubly node that contains the value of the new node
        DoublyNode<T>* NewNode = new DoublyNode<T>(NewElement);

        // Checking if the deque is empty, if true then we set both the head and tail to the new node since it's just one node
        if (isEmpty())
            Head = Tail = NewNode;
        else
        {
            // If false we set the next node of the new node to the head, the set back of the head to the new node then set the head to the new node
            NewNode->SetNext(Head);
            Head->SetBack(NewNode);
            Head = NewNode;
        }
        // Increment the value of the count so we know that the deque got a new element
        Count++;
        return true;
    }

    /**
     * Removes the element from the front of the Deque.
     * @param {T} FrontElement - The element removed from the front.
     * @returns {boolean} True if the operation is successful, false otherwise.
     */
    bool DequeueFront(T& FrontElement)
    {
        // If the deque is empty we can't remove anything (obv.)
        if (isEmpty())
            return false;
        else
        {
            // Setting the value of the removed head to the FrontElement parameter
            FrontElement = Head->GetValue();

            // I'm not sure if this is correct, but I created this to safely delete the front node, my thought process was if we didn't do this, there will be either a memory leak or dangling pointer
            DoublyNode<T>* Temp = Head;
            // Sometimes the deque can contain only 1 element, if that's the case we set both the head and tail to null
            if (Head == Tail)
                Head = Tail = nullptr;
            else
            {
                // If there are more than 1 elements in the deque, then we set the head to the node after the head
                Head = Head->GetNext();
                Head->SetBack(nullptr);
            }
            delete Temp;
            Count--;
            return true;
        }
    }

    /**
     * Adds an element to the back of the Deque.
     * @param {T} NewElement - The element to be added.
     * @returns {boolean} True if the operation is successful, false otherwise.
     */
    bool EnqueueBack(const T& NewElement)
    {
        // Creating a new node to add to the back
        DoublyNode<T>* NewNode = new DoublyNode<T>(NewElement);

        // If the deque is empty, we add the new node to both the head and tail just like above
        if (isEmpty())
            Head = Tail = NewNode;
        else
        {
            // If the deque is not empty, we set the next of the previous tail to the new node, and make them point at each other then set the tail to the new node
            Tail->SetNext(NewNode);
            NewNode->SetBack(Tail);
            Tail = NewNode;
        }
        Count++;
        return true;
    }

    /**
     * Removes the element from the back of the Deque.
     * @param {T} BackElement - The element removed from the back.
     * @returns {boolean} True if the operation is successful, false otherwise.
     */
    bool DequeueBack(T& BackElement)
    {
        // Just like dequeue front
        if (isEmpty())
            return false;
        else
        {
            // Setting the value of the old tail to the parameter
            BackElement = Tail->GetValue();

            if (Head == Tail)
                Head = Tail = nullptr;
            else
            {
                Tail = Tail->GetBack();
                Tail->SetNext(nullptr);
            }

            Count--;
            return true;
        }
    }

    /**
     * Retrieves the element at the front of the Deque without removing it.
     * @param {T} FrontElement - The element at the front of the Deque.
     * @returns {boolean} True if the operation is successful, false otherwise.
     */
    bool GetFront(T& FrontElement) const
    {
        // If the deque is empty, we set the parameter to null and return false
        if (isEmpty())
            return false;
        else
        {
            // Setting the value to the paramater and returning true
            FrontElement = Head->GetValue();
            return true;
        }
    }

    /**
     * Retrieves the element at the back of the Deque without removing it.
     * @param {T} BackElement - The element at the back of the Deque.
     * @returns {boolean} True if the operation is successful, false otherwise.
     */
    bool GetBack(T& BackElement) const
    {
        if (isEmpty())
            return false;
        else
        {
            BackElement = Tail->GetValue();
            return true;
        }
    }

    /**
     * Checks if the Deque is empty.
     * @returns {boolean} True if the Deque is empty, false otherwise.
     */
    bool isEmpty() const override
    {
        return !(Count > 0);
    }

    /*
     * Returns the number of nodes in the deque
     *
     * @returns {int} - The number of nodes in the deque
     */
    int GetCount() const
    {
        return this->Count;
    }

    /**
     * Prints the elements of the Deque.
     * @param {void}
     * @returns {void}
     */
    void Print() const
    {
        // Check if the deque is empty
        if (isEmpty())
            return;

        // Iterate through the deque and print each element
        DoublyNode<T>* Current = Head;

        std::cout << "[";

        while (Current != nullptr)
        {
            std::cout << Current->GetValue();

            // Print arrow if the current node is not the last node
            if (Current->GetNext() != nullptr)
                std::cout << ", ";

            Current = Current->GetNext();
        }

        std::cout << "]" << std::endl;
    }

    /**
     * Clears the Deque by removing all elements and deallocating memory.
     * @param {void}
     * @returns {void}
     */
    void Clear()
    {
        // Start from the head of the deque
        DoublyNode<T>* Current = Head;

        // Iterate through the deque and deallocate memory for each node
        while (Current != nullptr)
        {
            DoublyNode<T>* Temp = Current;

            // Move to the next node
            Current = Current->GetNext();

            // Deallocate memory for the current node
            delete Temp;
        }

        // Reset Head and Tail pointers to nullptr
        Head = nullptr;
        Tail = nullptr;

        // Reset Count to zero
        Count = 0;
    }

    // To avoid errors, we must implement the pure virtual functions found in QueueADT.h since deque implements it

    bool enqueue(const T& newEntry) override
    {
        return EnqueueBack(newEntry);
    }

    bool dequeue(T& FrontEntry) override
    {
        return DequeueFront(FrontEntry);
    }

    bool peek(T& FrontEntry) const override
    {
        return GetFront(FrontEntry);
    }

    ~Deque()
    {
        DoublyNode<T>* Current = Head;

        while (Current != nullptr)
        {
            DoublyNode<T>* Temp = Current;
            Current = Current->GetNext();
            delete Temp;
        }

        Head = Tail = nullptr;
        Count = 0;
    }
};

#endif // !Deque_H