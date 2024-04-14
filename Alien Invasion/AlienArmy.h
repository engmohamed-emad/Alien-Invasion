#pragma once
#include <iostream>
#include"AlianSounit.h"
#include"Drones.h"
#include"Monster.h"
#include"DronesQueue.h"
#include"SoModQueue.h"
using namespace std;
class AlienArmy
{
protected:
	SoModQueue<AlianSounit> solders;


public:
	bool addSo_unit(AlianSounit& s);
	bool getSo_unit(Node<AlianSounit>*& SoUnit);
	bool ReturnSo_uint(Node<AlianSounit>*& SoUnit);
};

