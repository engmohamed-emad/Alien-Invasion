#pragma once
#include "unit.h"
class Game;
class Solderunit : public unit
{
private:
	int Heal_Time = 0;
	
	int state_solider = -1;//normal -1 infected 0 immuned 1//******************
	bool second_heal = false;
	Game* game;
public:
	Solderunit();
	Solderunit(int id, int jt, float h, float ap, int c, Game* g);
	virtual void dec_health(float damage);
	virtual void set_state(int x);//**********************
	virtual int get_state();
	virtual void inc_health(float heal);
	virtual bool attack();
	bool attack_infected();//****************************************
	void set_Heal_Time(int t);
	int get_Heal_Time();//before Heal you have to check weather a current timestep -heal time<or >10 
	void set_second_heal();
	bool get_second_heal();

};