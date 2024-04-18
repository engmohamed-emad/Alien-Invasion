#pragma once
#include<iostream>
#include "Node.h"
#include"Solderunit.h"
#include"Tank.h"
#include"EG.h"
#include"SoModQueue.h"
#include"priQueue.h"
class EarthArmy
{
protected:
	SoModQueue<Solderunit> solders;
	priQueue<EG*> Earth_Gun;
	
public:

	bool Add_unit(unit* ptr);

	bool addSo_unit(Solderunit& s);
	bool getSo_unit(Node<Solderunit>*& SoUnit);
	bool ReturnSo_uint(Node<Solderunit>*& SoUnit);

	void Add_Earth_Gun(EG* G);              
	bool Return_Gun(EG* G,int pri);


};

