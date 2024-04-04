#ifndef PriorityNode_H
#define PriorityNode_H

template <typename T>
class PriorityNode
{
public:
    T Value;
    T Priority;
    PriorityNode<T> *Next;

    PriorityNode() : Next(nullptr) {}
    PriorityNode(const T &Value, const T &Priority) : Value(Value), Priority(Priority), Next(nullptr) {}
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