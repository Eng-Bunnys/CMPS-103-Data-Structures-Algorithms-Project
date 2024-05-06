#ifndef KilledList_H
#define KilledList_H

#include "../../Units/Unit.h"
#include "../../Structures/Queue/LinkedQueue.h"
/// Missing docs & print fn
class KilledList
{
private:
	/* A Pointer to the killed list */
	LinkedQueue<Unit *> *Killed;
	/* The number of units in the killed list */
	int Count;
public:
	KilledList();

	LinkedQueue<Unit *> *GetKilledList() const;

	int GetCount() const;

	bool AddUnit(Unit *NewUnit);

	bool RemoveUnit(Unit *&RemovedUnit);

	void Print();
};

#endif // !KilledList_H
