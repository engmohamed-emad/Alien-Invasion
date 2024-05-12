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
	int num_su = 0;
public:

	bool addSU_unit(SU*& s);
	bool ReturnSU_uint(SU*& SuUnit, unit*& pt);
	int get_num_su();
	void print();
	bool Attack_Alien();
	~ally_army();
};

