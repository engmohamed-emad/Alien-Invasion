#pragma once
#include <iostream>
#include "Node.h"
#include "QueueADT.h"
#include "Solderunit.h"
#include "AlianSounit.h"
#include "unit.h"
#include "LinkedQueue.h"
#include "SU.h"
#define RESET   "\033[0m"
#define RED     "\033[31m"  

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
			if (ptr->getItem()->get_state() == 0)
				cout << RED << ptr->getItem()->getID() << "(" << ptr->getItem()->getcurrhealth() << ")" << RESET;
			else
				cout << ptr->getItem()->getID() << "(" << ptr->getItem()->getcurrhealth() << ")";
			ptr = ptr->getNext();
			if (ptr)
				cout << ", ";
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
			cout << ptr->getItem()->getID() << "(" << ptr->getItem()->getcurrhealth()<<")";
			ptr = ptr->getNext();
			if (ptr)
				cout << ", ";
		}
	}

	~SoModQueue()
	{
		AlianSounit* temp;
		while (this->dequeue(temp));
	}
};


template <>
class SoModQueue<SU*> : public LinkedQueue<SU*>
{
public:
	void print()
	{
		Node<SU*>* ptr = this->frontPtr;
		while (ptr)
		{
			
			cout << ptr->getItem()->getID() << "(" << ptr->getItem()->getcurrhealth() << ")";
			ptr = ptr->getNext();
			if (ptr)
				cout << ", ";
		}
	}

	~SoModQueue()
	{
		SU* temp;
		while (this->dequeue(temp));
	}
};


