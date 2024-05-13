#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include "../ADTs/StackADT.h"

template <typename T>
class ArrayStack : public StackADT<T>
{
private:
    /**
     * The maximum size of the array.
     */
    static constexpr int MAX_SIZE = 500;
    /**
     * The array of stack items.
     */
    T Items[MAX_SIZE];
    /**
     * The index of the item at the top of the stack.
     */
    int TopElement;
    /**
     * The number of elements currently in the stack.
     */
    int Count;

public:
    /**
     * Default constructor.
     */
    ArrayStack()
    {
        this->TopElement = -1;
        this->Count = 0;
    }

    /**
     * Checks if the stack is empty.
     *
     * @returns {bool} - True if the stack is empty, false otherwise.
     */
    bool isEmpty() const
    {
        return this->TopElement == -1;
    }

    /**
     * Pushes a new entry onto the stack.
     *
     * @param {T&} NewEntry - The new entry to be pushed onto the stack.
     * @returns {bool} - True if the operation is successful, false if the stack is full.
     */
    bool push(const T &NewEntry)
    {
        if (this->TopElement == this->MAX_SIZE - 1)
            return false;

        this->TopElement++;
        this->Count++;
        this->Items[this->TopElement] = NewEntry;
        return true;
    }

    /**
     * Pops the top entry from the stack.
     *
     * @param {T&} TopEntry - Reference to store the popped entry.
     * @returns {bool} - True if the operation is successful, false if the stack is empty.
     */
    bool pop(T &TopEntry)
    {
        if (isEmpty())
            return false;

        TopEntry = this->Items[this->TopElement];
        this->TopElement--;
        this->Count--;
        return true;
    }

    /**
     * Retrieves the top entry from the stack without removing it.
     *
     * @param {T&} TopEntry - Reference to store the top entry.
     * @returns {bool} - True if the operation is successful, false if the stack is empty.
     */
    bool peek(T &TopEntry) const
    {
        if (isEmpty())
            return false;

        TopEntry = this->Items[this->TopElement];
        return true;
    }

    /**
     * Prints the elements of the stack.
     */
    void Print() const
    {
        if (isEmpty())
            return;

        std::cout << "[";
        for (int i = 0; i <= this->TopElement; i++)
        {
            std::cout << this->Items[i];
            if (i < this->TopElement)
                std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }

    /**
     * Clears the stack by resetting the top index.
     */
    void Clear()
    {
        this->TopElement = -1;
        this->Count = 0;
    }

    /**
     * Retrieves the number of elements currently in the stack.
     *
     * @returns {int} - The number of elements in the stack.
     */
    int GetCount() const
    {
        return this->Count;
    }

    /**
     * Destructor to clean up memory.
     */
    ~ArrayStack()
    {
        this->Clear();
    }
};

#endif // ARRAY_STACK_H
