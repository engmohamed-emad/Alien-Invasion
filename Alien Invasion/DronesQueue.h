#include"LinkedQueue.h"
#include"Drones.h"
#ifndef DronesQueue_h
#define DronesQueue_h

class DronesQueue : public LinkedQueue<Drones> 
{
private:
	Node<Drones>* get_prev();//utility func that get pointer of prev of last node 
public:
	bool enqueue_front(Drones &D);
	bool dequeue_rear(Drones &D);




};
#endif