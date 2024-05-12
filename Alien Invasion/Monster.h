#pragma once
#include"unit.h"
#include<iostream>
class Game;
class Monster:public unit
{
	Game* game;
	bool mode_inf = false;
public:
	Monster();
	Monster(int id, int jt, float h, float ap, int c,Game* g);
	virtual void dec_health(float damage);
	virtual bool attack();
	void set_mode_inf(bool f);
	bool get_mode_inf();
};

