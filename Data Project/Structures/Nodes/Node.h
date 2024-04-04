#ifndef Node_H
#define Node_H

template <typename T>
class Node
{
public:
	/* The value of the node */
	T Value;
	/* The node after */
	Node<T> *Next;

	Node() : Next(nullptr) {}
	Node(const T &Value) : Value(Value), Next(nullptr) {}
	Node(const T &Value, Node<T> *Next) : Value(Value), Next(Next) {}

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
	 * Sets the next pointer of the node.
	 * @param {Node<T>*} NewNext - The new next pointer for the node.
	 * @returns {void}
	 */
	void SetNext(Node<T> *NewNext)
	{
		this->Next = NewNext;
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
	 * Gets the next pointer of the node.
	 * @returns {Node<T>*} The next pointer of the node.
	 */
	Node<T> *GetNext() const
	{
		return this->Next;
	}
};

#endif // !Node_H