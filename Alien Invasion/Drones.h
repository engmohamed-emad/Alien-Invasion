#include"unit.h"
#include<iostream>
using namespace std;
#ifndef Drones_h
#define Drones_h

class Drones :public unit
{

public:
	Drones();
	Drones(int id, int jt, float h, float ap, int c);
	virtual void dec_health(float damage);
};
#endif
