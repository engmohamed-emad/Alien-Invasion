#pragma once
#include<iostream>
#include"ArrayStack.h"
#include "Node.h"
#include"Solderunit.h"
#include"Tank.h"
#include"EG.h"
#include"SoModQueue.h"
#include"priQueue.h"
class EarthArmy
{
protected:
	SoModQueue<Solderunit*> solders;
	priQueue<EG*> Earth_Gun;
	ArrayStack<Tank*> tanks;
	int num_tank = 0;
	int num_EG = 0;
	int num_sol = 0;
public:

	bool Add_unit(unit* ptr);

	bool addSo_unit(Solderunit*& s);
	bool ReturnSo_uint(Solderunit*& SoUnit,unit*&pt);
	bool return_tank(Tank*& t,unit*&pt);
	void Add_Earth_Gun(EG*& G);              
	bool Return_Gun(EG*& G,int pri,unit*&pt);
	//edit
	bool Add_tank(Tank*& tank);
	void print();
	~EarthArmy();
};

