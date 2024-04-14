#pragma once
#include<iostream>
#include "Node.h"
#include"Solderunit.h"
#include"Tank.h"
#include"EG.h"
#include"SoModQueue.h"
class EarthArmy
{
protected:
	SoModQueue<Solderunit> solders;



public:
	bool addSo_unit(Solderunit& s);
	bool getSo_unit(Node<Solderunit>*& SoUnit);
	bool ReturnSo_uint(Node<Solderunit>*& SoUnit);
};

