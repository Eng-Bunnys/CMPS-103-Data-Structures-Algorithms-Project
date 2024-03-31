#ifndef DeQue_H
#define DeQue_H

#include "../Nodes/DoublyNode.h"
#include "../Queue/QueueADT.h"

template <typename T>
class DeQue : public QueueADT<T>
{
private:
    /* The Head of the Deque */
    DoublyNode<T> *Head;
    /* The Tail of the Deque */
    DoublyNode<T> *Tail;
    /* The number of nodes in the Deque */
    int Count = 0;

public:
    DeQue() : Head(nullptr), Tail(nullptr), Count(0)
    {
    }
    DeQue(DoublyNode<T> *Head, DoublyNode<T> *Tail) : Head(Head), Tail(Tail), Count(2)
    {
    }
    DeQue(const T &Head, const T &Tail)
    {
        DoublyNode<T> *HeadNode = new DoublyNode<T>(Head);
        DoublyNode<T> *TailNode = new DoublyNode<T>(Tail);

        HeadNode->Next = TailNode;
        TailNode->Back = HeadNode;
        this->Head = HeadNode;
        this->Tail = TailNode;
        this->Count = 2;
    }
    /**
     * Adds an element to the front of the Deque.
     * @param {T} NewElement - The element to be added.
     * @returns {boolean} True if the operation is successful, false otherwise.
     */
    bool EnqueueFront(const T &NewElement)
    {
        // Creating a new doubly node that contains the value of the new node
        DoublyNode<T> *NewNode = new DoublyNode<T>(NewElement);

        // Checking if the deque is empty, if true then we set both the head and tail to the new node since it's just one node
        if (isEmpty())
            Head = Tail = NewNode;
        else
        {
            // If false we set the next node of the new node to the head, the set back of the head to the new node then set the head to the new node
            NewNode->Next = Head;
            Head->Back = NewNode;
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
    bool DequeueFront(T &FrontElement)
    {
        // If the deque is empty we can't remove anything (obv.)
        if (isEmpty())
            return false;
        else
        {
            // Setting the value of the removed head to the FrontElement parameter
            FrontElement = Head->Value;

            // I'm not sure if this is correct, but I created this to safely delete the front node, my thought process was if we didn't do this, there will be either a memory leak or dangling pointer
            DoublyNode<T> *Temp = Head;
            // Sometimes the deque can contain only 1 element, if that's the case we set both the head and tail to null
            if (Head == Tail)
                Head = Tail = nullptr;
            else
            {
                // If there are more than 1 elements in the deque, then we set the head to the node after the head
                Head = Head->Next;
                Head->Back = nullptr;
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
    bool EnqueueBack(const T &NewElement)
    {
        // Creating a new node to add to the back
        DoublyNode<T> *NewNode = new DoublyNode<T>(NewElement);

        // If the deque is empty, we add the new node to both the head and tail just like above
        if (isEmpty())
            Head = Tail = NewNode;
        else
        {
            // If the deque is not empty, we set the next of the previous tail to the new node, and make them point at each other then set the tail to the new node
            Tail->Next = NewNode;
            NewNode->Back = Tail;
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
    bool DequeueBack(T &BackElement)
    {
        // Just like dequeue front
        if (isEmpty())
            return false;
        else
        {
            // Setting the value of the old tail to the parameter
            BackElement = Tail->Value;

            // Just like dequeue front
            DoublyNode<T> *Temp = Tail;

            if (Head == Tail)
                Head = Tail = nullptr;
            else
            {
                Tail = Tail->Back;
                Tail->Next = nullptr;
            }
            delete Temp;
            Count--;
            return true;
        }
    }

    /**
     * Retrieves the element at the front of the Deque without removing it.
     * @param {T} FrontElement - The element at the front of the Deque.
     * @returns {boolean} True if the operation is successful, false otherwise.
     */
    bool GetFront(T &FrontElement)
    {
        // If the deque is empty, we set the parameter to null and return false
        if (isEmpty())
        {
            FrontElement = nullptr;
            return false;
        }
        else
        {
            // Setting the value to the paramater and returning true
            FrontElement = Head->Value;
            return true;
        }
    }

    /**
     * Retrieves the element at the back of the Deque without removing it.
     * @param {T} BackElement - The element at the back of the Deque.
     * @returns {boolean} True if the operation is successful, false otherwise.
     */
    bool GetBack(T &BackElement)
    {
        if (isEmpty())
        {
            BackElement = nullptr;
            return false;
        }
        else
        {
            BackElement = Tail->Value;
            return true;
        }
    }

    /**
     * Checks if the Deque is empty.
     * @returns {boolean} True if the Deque is empty, false otherwise.
     */
    bool isEmpty()
    {
        return !(Count > 0);
    }

    virtual ~DeQue() {}
};

#endif // !DeQue_H