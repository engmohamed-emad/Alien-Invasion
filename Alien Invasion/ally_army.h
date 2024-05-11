#pragma once
#include<iostream>
#include "Node.h"
#include"SU.h"
#include"SoModQueue.h"
#include "LinkedQueue.h"
#include"Game.h"
class Game;
class ally_army
{
private:
	SoModQueue<SU*>SU_unit;

	int num_killed_su = 0;
	int num_su = 0;
	int Df = 0;
	int Dd = 0;
	int Db = 0;
public:

	bool addSU_unit(SU*& s);
	bool ReturnSU_uint(SU*& SuUnit, unit*& pt);

	int get_num_su();

	void print();
	void update_num_killed_su();
	void ubdate_D(unit*& U);
	bool Attack_Alien();
	void print_statistics();
	~ally_army();
};

