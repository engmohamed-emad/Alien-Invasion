#pragma once
#include <iostream>
#include "Node.h"
#include "QueueADT.h"
#include "Solderunit.h"
#include "AlianSounit.h"
#include "unit.h"
#include "LinkedQueue.h"
using namespace std;


template <typename T>
class SoModQueue : public LinkedQueue<T>
{
public:
	
	~SoModQueue()
	{
		T temp;
		while (this->dequeue(temp));
	}
};


template <>
class SoModQueue<Solderunit*> : public LinkedQueue<Solderunit*>
{
public:
	void print()
	{
		Node<Solderunit*>* ptr = this->frontPtr;
		while (ptr)
		{
			cout << ptr->getItem()->getID() << ", ";
			ptr = ptr->getNext();
		}
	}
	
	~SoModQueue()
	{
		Solderunit* temp;
		while (this->dequeue(temp));
	}
};
/// //////////////////////////////////////////////////////////
template <>
class SoModQueue<AlianSounit*> : public LinkedQueue<AlianSounit*>
{
public:
	void print()
	{
		Node<AlianSounit*>* ptr = this->frontPtr;
		while (ptr)
		{
			cout << ptr->getItem()->getID() << ", ";
			ptr = ptr->getNext();
		}
	}

	~SoModQueue()
	{
		AlianSounit* temp;
		while (this->dequeue(temp));
	}
};





