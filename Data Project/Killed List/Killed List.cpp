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
	{
		this->Count++;
		return true;
	}
	else
		return false;
}

bool KilledList::RemoveUnit(Unit *&RemovedUnit)
{
	if (this->Killed->dequeue(RemovedUnit))
	{
		this->Count--;
		return true;
	}
	else
		return false;
}

void KilledList::Print()
{
	this->Killed->Print();
}

KilledList::~KilledList()
{
	delete Killed;
}