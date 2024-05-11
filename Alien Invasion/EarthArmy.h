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
	int num_Hsol=0;
	int num_Htank=0;
	int num_HU = 0;
	int num_killed_HU = 0;
	int num_killed_tank = 0;
	int num_killed_EG=0;
	int num_killed_sol=0;
	int num_tank = 0;
	int num_EG = 0;
	int num_sol = 0;
	int Df = 0;
	int Dd = 0;
	int Db = 0;
	int total_units = 0;
	int Num_infect_solid = 0;//***********************************
public:

	bool Add_unit(unit* ptr);

	bool addSo_unit(Solderunit*& s);
	bool ReturnSo_uint(Solderunit*& SoUnit,unit*&pt);
	bool return_tank(Tank*& t,unit*&pt);
	void Add_Earth_Gun(EG*& G);              
	bool Return_Gun(EG*& G,int pri,unit*&pt);
	int get_num_sol();
	void increment_infected();//**********************************
	void decrement_infected();//*************************************
	void spread_infection();//***************************************
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
	void set_num_HU(int num);
	void set_num_killed_HU(int num);
	bool Add_tank(Tank*& tank);
	void print();
	void update_num_killed_sol();
	void update_num_killed_EG();
	void update_num_killed_tank();
	void ubdate_D(unit*& U);
	bool Attack_Alien();/***************************************/
	void print_statistics();
	int get_total_ES_units();
	int get_total_EG_units();
	int get_total_ET_units();
	int get_total_HU_units();
	float get_per_ES();
	float get_per_EG();
	float get_per_ET();
	float get_per_total();
	float get_per_Df();
	float get_per_Dd();
	float get_per_Db();
	float get_per_Df_Db();
	float get_per_Dd_Db();
	int get_num_Army();
	void set_num_Hsol(int num);
	void set_num_Htank(int num);
	~EarthArmy();
};

