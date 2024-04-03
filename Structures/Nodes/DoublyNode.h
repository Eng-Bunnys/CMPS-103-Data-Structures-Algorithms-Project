#ifndef DoublyNode_H
#define DoublyNode_H

template <typename T>
struct DoublyNode
{
	T Value;
	DoublyNode<T> *Next;
	DoublyNode<T> *Back;

	DoublyNode() : Back(nullptr), Next(nullptr) {}
	DoublyNode(const T &Value) : Value(Value), Back(nullptr), Next(nullptr) {}
	DoublyNode(const T &Value, DoublyNode *Back, DoublyNode *Next) : Value(Value), Back(Back), Next(Next) {}
};

#endif // !DoublyNode_H