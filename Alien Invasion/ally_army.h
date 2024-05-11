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
	bool Add_unit(unit* ptr);

	bool addSU_unit(Solderunit*& s);
	bool ReturnSU_uint(Solderunit*& SoUnit, unit*& pt);

	int get_num_sol();

	void print();
	void update_num_killed_su();
	void ubdate_D(unit*& U);
	bool Attack_Alien();
	void print_statistics();
	int get_total_units();
	~ally_army();
};

