#pragma once
#pragma once
#include "priNode.h"
#include "unit.h"
#include "EG.h"
#include <iostream>
#include"Solderunit.h"
#define RESET   "\033[0m"
#define RED     "\033[31m"  

using namespace std;


//This class impelements the priority queue as a sorted list (Linked List)
//The item with highest priority is at the front of the queue
template <typename T>
class priQueue
{
protected:
    priNode<T>* head;
public:
    priQueue() : head(nullptr) {}

    ~priQueue() {
        T tmp;
        int p;
        while (dequeue(tmp, p));
    }

    //insert the new node in its correct position according to its priority
    void enqueue(const T& data, int priority) {
        priNode<T>* newNode = new priNode<T>(data, priority);

        if (head == nullptr || priority > head->getPri()) {

            newNode->setNext(head);
            head = newNode;
            return;
        }

        priNode<T>* current = head;
        while (current->getNext() && priority <= current->getNext()->getPri()) {
            current = current->getNext();
        }
        newNode->setNext(current->getNext());
        current->setNext(newNode);
    }

    bool dequeue(T& topEntry, int& pri) {
        if (isEmpty())
            return false;

        topEntry = head->getItem(pri);
        priNode<T>* temp = head;
        head = head->getNext();
        delete temp;
        return true;
    }

    bool peek(T& topEntry, int& pri) {
        if (isEmpty())
            return false;

        topEntry = head->getItem();
        pri = head->getPri();
        return true;
    }

    bool isEmpty() const {
        return head == nullptr;
    }
    void print()
    {

    }
};
///////////////////////////////////////////////////////////////

template <>
class priQueue<EG*>
{
protected:
    priNode<EG*>* head;
public:
    priQueue() : head(nullptr) {}

    ~priQueue() {
        EG* tmp;
        int p;
        while (dequeue(tmp, p));
    }

    //insert the new node in its correct position according to its priority
    void enqueue(EG*& data, int priority) {
        priNode<EG*>* newNode = new priNode<EG*>(data, priority);

        if (head == nullptr || priority > head->getPri()) {

            newNode->setNext(head);
            head = newNode;
            return;
        }

        priNode<EG*>* current = head;
        while (current->getNext() && priority <= current->getNext()->getPri()) {
            current = current->getNext();
        }
        newNode->setNext(current->getNext());
        current->setNext(newNode);
    }

    bool dequeue(EG*& topEntry, int& pri) {
        if (isEmpty())
            return false;

        topEntry = head->getItem(pri);
        priNode<EG*>* temp = head;
        head = head->getNext();
        delete temp;
        return true;
    }

    bool peek(EG*& topEntry, int& pri) {
        if (isEmpty())
            return false;
        pri = head->getPri();
        topEntry = head->getItem(pri);
        return true;
    }

    bool isEmpty() const {
        return head == nullptr;
    }
    void print()
    {
        int pri;
        priNode<EG*>* ptr = this->head;
        while (ptr)
        {
            pri = head->getPri();
            cout << ptr->getItem(pri)->getID() << "(" << ptr->getItem(pri)->getcurrhealth() << ")";
            ptr = ptr->getNext();
            if (ptr)
                cout << ", ";
        }
    }
};
template<>
inline void priQueue<Solderunit*>::print()
{
    int pri;
    priNode<Solderunit*>* ptr = this->head;
    while (ptr)
    {
        pri = head->getPri();
        if (ptr->getItem(pri)->get_state() == 0)
            cout << RED << ptr->getItem(pri)->getID() << "(" << ptr->getItem(pri)->getcurrhealth() << ")" << RESET;
        else cout << ptr->getItem(pri)->getID() << "(" << ptr->getItem(pri)->getcurrhealth() << ")";
        ptr = ptr->getNext();
        if (ptr)
            cout << ", ";
    }
}