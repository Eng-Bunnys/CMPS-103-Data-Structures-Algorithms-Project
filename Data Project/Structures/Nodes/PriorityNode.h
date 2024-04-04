#ifndef PriorityNode_H
#define PriorityNode_H

template <typename T>
class PriorityNode
{
private:
    /* The value of the node */
    T Value;
    /* The node's priority */
    T Priority;
    /* Pointer to the next node */
    PriorityNode<T> *Next;

public:
    /**
     * Construct a new PriorityNode object with default value and next pointer.
     */
    PriorityNode() : Next(nullptr) {}

    /**
     * Construct a new PriorityNode object with given value, priority, and default next pointer.
     * @param {T} Value - The value to be stored in the node.
     * @param {T} Priority - The priority of the node.
     */
    PriorityNode(const T &Value, const T &Priority) : Value(Value), Priority(Priority), Next(nullptr) {}

    /**
     * Construct a new PriorityNode object with given value, priority, and next pointer.
     * @param {T} Value - The value to be stored in the node.
     * @param {T} Priority - The priority of the node.
     * @param {PriorityNode<T>*} Next - Pointer to the next node.
     */
    PriorityNode(const T &Value, const T &Priority, PriorityNode<T> *Next) : Value(Value), Priority(Priority), Next(Next) {}

    /**
     * Sets the value of the node.
     * @param {T} NewValue - The new value to set for the node.
     * @returns {void}
     */
    void SetValue(const T &NewValue)
    {
        this->Value = NewValue;
    }

    /**
     * Sets the priority of the node.
     * @param {T} NewPriority - The new priority to set for the node.
     * @returns {void}
     */
    void SetPriority(const T &NewPriority)
    {
        this->Priority = NewPriority;
    }

    /**
     * Sets both the value and priority of the node.
     * @param {T} NewValue - The new value to set for the node.
     * @param {T} NewPriority - The new priority to set for the node.
     * @returns {void}
     */
    void SetNode(const T &NewValue, const T &NewPriority)
    {
        this->Value = NewValue;
        this->Priority = NewPriority;
    }

    /**
     * Sets the next pointer of the node.
     * @param {PriorityNode<T>*} NextNode - The new next pointer for the node.
     * @returns {void}
     */
    void SetNext(PriorityNode<T> *NextNode)
    {
        this->Next = NextNode;
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
     * Gets the priority of the node.
     * @returns {T} The priority of the node.
     */
    T GetPriority() const
    {
        return this->Priority;
    }

    /**
     * Gets the next pointer of the node.
     * @returns {PriorityNode<T>*} The next pointer of the node.
     */
    PriorityNode<T> *GetNext() const
    {
        return this->Next;
    }
};

#endif // !PriorityNode_H