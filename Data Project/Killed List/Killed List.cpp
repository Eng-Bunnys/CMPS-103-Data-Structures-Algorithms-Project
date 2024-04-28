#include "Killed List.h"

KilledList::KilledList() : Count(0)
{
	this->Killed = new LinkedQueue<Unit *>;
}

LinkedQueue<Unit *> *KilledList::GetKilledList() const
{
	return this->Killed;
}

int KilledList::GetCount() const
{
	return this->Count;
}

bool KilledList::AddUnit(Unit *NewUnit)
{
	if (this->Killed->enqueue(NewUnit))
		return true;
	else
		return false;
}

bool KilledList::RemoveUnit(Unit *&RemovedUnit)
{
	if (this->Killed->dequeue(RemovedUnit))
		return true;
	else
		return false;
}