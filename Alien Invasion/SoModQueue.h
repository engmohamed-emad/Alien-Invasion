#pragma once
#include "Node.h"
#include "QueueADT.h"
#include "LinkedQueue.h"


template <typename T>
class SoModQueue : public LinkedQueue<T>
{
public:
	bool enqueue_front(const T& D);
	~SoModQueue();
};

template<typename T>
inline bool SoModQueue<T>::enqueue_front(const T& S)
{
	Node<T>* newNodePtr = new Node<T>(S);
	if (this->isEmpty())//case of empty Queue
	{
		newNodePtr->setNext(nullptr);
		this->frontPtr = newNodePtr;
		this->backPtr = newNodePtr;
		return true;
	}
	else
	{
		newNodePtr->setNext(this->frontPtr);
		this->frontPtr = newNodePtr;
		return true;
	}
	return false;
}

template<typename T>
inline SoModQueue<T>::~SoModQueue()
{
	T temp;
	while (this->dequeue(temp));
}
