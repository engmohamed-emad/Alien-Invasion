#pragma once
#include<iostream>
#include"unit.h"
class Game;
class Tank :public unit
{
private:
	int Heal_Time = 0;
	Game* game;
public:
	Tank();
	Tank(int id, int jt, float h, float ap, int c,Game *g);
	virtual bool attack();
	virtual void dec_health(float damage);
	bool help_soldier(int ES_num,int AS_num);//takes numbers of earth and alien soldiers to determine if tank will attack alien soldiers or not 
	void set_Heal_Time(int t);
	int get_Heal_Time();//before Heal you have to check weather a current timestep -heal time<or >10 
};

