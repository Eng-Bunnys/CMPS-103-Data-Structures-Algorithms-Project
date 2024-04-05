#ifndef DoublyNode_H
#define DoublyNode_H

template <typename T>
class DoublyNode
{
private:
    /* The value of the node */
    T Value;
    /* Pointer to the next node */
    DoublyNode<T> *Next;
    /* Pointer to the previous node */
    DoublyNode<T> *Back;

public:
    /**
     * Construct a new DoublyNode object with default value, previous, and next pointers.
     */
    DoublyNode() : Back(nullptr), Next(nullptr) {}

    /**
     * Construct a new DoublyNode object with given value and default previous and next pointers.
     * @param {T} Value - The value to be stored in the node.
     */
    DoublyNode(const T &Value) : Value(Value), Back(nullptr), Next(nullptr) {}

    /**
     * Construct a new DoublyNode object with given value, previous, and next pointers.
     * @param {T} Value - The value to be stored in the node.
     * @param {DoublyNode<T>*} Back - Pointer to the previous node.
     * @param {DoublyNode<T>*} Next - Pointer to the next node.
     */
    DoublyNode(const T &Value, DoublyNode *Back, DoublyNode *Next) : Value(Value), Back(Back), Next(Next) {}

    /**
     * Sets the value of the node.
     * @param {T} NewValue - The new value to be set.
     * @returns {void}
     */
    void SetValue(const T &NewValue)
    {
        this->Value = NewValue;
    }

    /**
     * Sets the pointer to the next node.
     * @param {DoublyNode<T>*} NewNext - Pointer to the new next node.
     * @returns {void}
     */
    void SetNext(DoublyNode<T> *NewNext)
    {
        this->Next = NewNext;
    }

    /**
     * Sets the pointer to the previous node.
     * @param {DoublyNode<T>*} NewBack - Pointer to the new previous node.
     * @returns {void}
     */
    void SetBack(DoublyNode<T> *NewBack)
    {
        this->Back = NewBack;
    }

    /**
     * Gets the value of the node.
     * @returns {T} The value of the node.
     */
    T GetValue() const
    {
        return this->Value;
    }

    /**
     * Gets the pointer to the next node.
     * @returns {DoublyNode<T>*} Pointer to the next node.
     */
    DoublyNode<T> *GetNext() const
    {
        return this->Next;
    }

    /**
     * Gets the pointer to the previous node.
     * @returns {DoublyNode<T>*} Pointer to the previous node.
     */
    DoublyNode<T> *GetBack() const
    {
        return this->Back;
    }
};

#endif // !DoublyNode_H