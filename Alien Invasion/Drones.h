#include"unit.h"
#ifndef Drones_h
#define Drones_h

class Drones :public unit
{

public:
	Drones(int id, int jt, float h, float ap, int c);
	virtual int attack(int enhealth);
	virtual void dec_health(float damage) ;


};
#endif
