#include"LinkedQueue.h"
#include"Drones.h"
#include "unit.h"
#include <iostream>
using namespace std;
#pragma once
template<class T>
class DronesQueue : public LinkedQueue<T>
{
private:

public:
	bool enqueue_front(const T& D);
	bool can_attacks();
	bool dequeue_rear(T& D);
	~DronesQueue();
};


	template<class T>
	inline bool DronesQueue<T>::enqueue_front(const T& D)
	{
		Node<T>* newNodePtr = new Node<T>(D);
		if (this->isEmpty())
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
	}
   template<class T>
   inline bool DronesQueue<T>::can_attacks()
	{
		if (this->backPtr == this->frontPtr)
			return false;
		else
			return true;
	}
	template<class T>
	inline bool DronesQueue<T>::dequeue_rear(T& D)
	{
		
		if(this->isEmpty())
			return false;
		else if (this->frontPtr == this->backPtr)//case one node
	    {
			        Node<T>* nodetodelete = this->backPtr;
			        D = this->backPtr->getItem();
					delete nodetodelete;
			        this->frontPtr = nullptr;
			        this->backPtr = nullptr;
			        return true;
	    }

		else //case more than one
		{
			Node<T>* nodetodelete = this->backPtr;
			D = this->backPtr->getItem();
			Node<T>* ptr = this->frontPtr;
			while (ptr)
			{
				if (ptr->getNext() == this->backPtr)
					break;
				else
					ptr = ptr->getNext();
			}
			this->backPtr = ptr;
			delete nodetodelete;
			this->backPtr->setNext(nullptr);
			return true;
		}
	
	}

template<class T>
DronesQueue<T>::~DronesQueue()
	  {
		  T temp;
		  while (this->dequeue(temp));
	  }

/////////////////////////////////////////////////////////////////////////////
template<>
class DronesQueue<Drones*> : public LinkedQueue<Drones*>
{
private:

public:
	bool enqueue_front(Drones*& D)
	{
		Node<Drones*>* newNodePtr = new Node<Drones*>(D);
		if (this->isEmpty())
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
	}
	bool can_attacks();
	bool dequeue_rear(Drones*& D)
	{
		if (this->isEmpty())
			return false;
		else if (this->frontPtr == this->backPtr)//case one node
		{
			Node<Drones*>* nodetodelete = this->backPtr;
			D = this->backPtr->getItem();
			delete nodetodelete;
			this->frontPtr = nullptr;
			this->backPtr = nullptr;
			return true;
		}

		else //case more than one
		{
			Node<Drones*>* nodetodelete = this->backPtr;
			D = this->backPtr->getItem();
			Node<Drones*>* ptr = this->frontPtr;
			while (ptr)
			{
				if (ptr->getNext() == this->backPtr)
					break;
				else
					ptr = ptr->getNext();
			}
			this->backPtr = ptr;
			delete nodetodelete;
			this->backPtr->setNext(nullptr);
			return true;
		}
	}
	void print()
	{
		Node<Drones*>* ptr = this->frontPtr;
		while (ptr)
		{
			cout << ptr->getItem()->getID() << ", ";
			ptr = ptr->getNext();
		}
	}
	
		~DronesQueue()
		{
			Drones* temp;
			while (this->dequeue(temp));
		}

	
};





	

