#pragma once
#include<iostream>
#include"ArrayStack.h"
#include "Node.h"
#include"Solderunit.h"
#include"Tank.h"
#include"EG.h"
#include"SoModQueue.h"
#include"priQueue.h"
#include "LinkedQueue.h"
#include"Game.h"
class Game;
class EarthArmy
{
protected:
	SoModQueue<Solderunit*> solders;
	priQueue<EG*> Earth_Gun;
	ArrayStack<Tank*> tanks;
	

	int num_killed_tank=0;
	int num_killed_EG=0;
	int num_killed_sol=0;
	int num_tank = 0;
	int num_EG = 0;
	int num_sol = 0;
	int Df = 0;
	int Dd = 0;
	int Db = 0;
public:

	bool Add_unit(unit* ptr);

	bool addSo_unit(Solderunit*& s);
	bool ReturnSo_uint(Solderunit*& SoUnit,unit*&pt);
	bool return_tank(Tank*& t,unit*&pt);
	void Add_Earth_Gun(EG*& G);              
	bool Return_Gun(EG*& G,int pri,unit*&pt);
	int get_num_sol();
	//edit
	/*
	* void attak (Alienarmy* a)
	* {
	* node* ES=solders.peek();
	* if(!ES->attack2(a->getsolder))
	* Retuen_solder;
	* }
	* 
	* 
		*/
	bool Add_tank(Tank*& tank);
	void print();
	void update_num_killed_sol();
	void update_num_killed_EG();
	void update_num_killed_tank();
	void ubdate_D(unit*& U);
	bool Attack_Alien();
	~EarthArmy();
};

