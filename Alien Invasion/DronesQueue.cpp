#include "DronesQueue.h"

Node<Drones>* DronesQueue::get_prev()
{
    Node<Drones>* ptr = frontPtr;
    while (ptr)
    {
        if (ptr->getNext() == backPtr)
            return ptr;
        else
            ptr = ptr->getNext();
    }
}

bool DronesQueue::enqueue_front(Drones& D)//when you pop temp list should be stack to keep sequence same
{
    Node<Drones>* ptr = new Node<Drones>(D);
    if (isEmpty())
    {
        frontPtr = ptr;
        backPtr = ptr;
    }
    else
    {
        ptr->setNext(frontPtr);
        frontPtr = ptr;
    }
    return true;
}

bool DronesQueue::dequeue_rear(Drones& D)
{
    if (isEmpty())//case empty
        return false;
    else if (frontPtr == backPtr)//case one node
    {
        Node<Drones>* nodetodelete = backPtr;
        D = backPtr->getItem();
        delete nodetodelete;
        frontPtr = nullptr;
        backPtr = nullptr;
        return true;
    }
    else //case more than one
    {
        Node<Drones>* nodetodelete = backPtr;
        D = backPtr->getItem();
        backPtr = get_prev();
        delete nodetodelete;
        backPtr->setNext(nullptr);
        return true;
    }
}



DronesQueue::DronesQueue()
{
}

