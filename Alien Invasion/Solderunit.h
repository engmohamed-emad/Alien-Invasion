#pragma once
#include "unit.h"
class Game;
class Solderunit : public unit
{
private:
	int Heal_Time = 0;
	Game* game;
public:
	Solderunit();
	Solderunit(int id, int jt, float h, float ap, int c, Game* g);
	virtual void dec_health(float damage);


	
	virtual void inc_health(float heal);
	virtual bool attack();
	void set_Heal_Time(int t);
	int get_Heal_Time();//before Heal you have to check weather a current timestep -heal time<or >10 


};