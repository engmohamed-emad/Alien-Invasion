#include"unit.h"
#include<iostream>

using namespace std;
#ifndef Drones_h
#define Drones_h
class Game;
class Drones :public unit
{
private:
	Game* game;
	int Attack_Cap_Tank;
	int Attack_Cap_Gun;
	void Set_Cap_Tank();
	void Set_Cap_Gun();
public:
	Drones();
	Drones(int id, int jt, float h, float ap, int c);
	virtual void dec_health(float damage);
	virtual bool attack();
	
};
#endif
