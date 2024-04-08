#pragma once
#include "Node.h"
#include "QueueADT.h"
#include "LinkedQueue.h"


template <typename T>
class SoModQueue : public LinkedQueue<T>
{
public:
	bool rdequeue(Node<T>*& solderptr);
	bool frontenqueue(Node<T>*& solderptr);

};

template<typename T>
inline bool SoModQueue<T>::rdequeue(Node<T>*& solderptr)
{
	if (this->isEmpty())
		return false;
	solderptr = this->frontPtr;
	this->frontPtr = this->frontPtr->getNext();
	// Queue is not empty; remove front
	if (solderptr == this->backPtr)	 // Special case: last node in the queue
		this->backPtr = nullptr;

	return true;
}

template<typename T>
inline bool SoModQueue<T>::frontenqueue(Node<T>*& solderptr)
{
	if (solderptr != nullptr)
	{
		solderptr->setnext(this->frontPtr);
		this->frontPtr = solderptr;
	}
}
