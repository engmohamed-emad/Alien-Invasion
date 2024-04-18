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
	DronesQueue<Drones*> Drone;
	bool place1 = false;    //to know whether  enqueue or front enqueue 
	bool place2 = false;  //same purpose but in fn get drones
public:
	bool ADD_unit(unit*& ptr);

	bool addSo_unit(AlianSounit& s);
	bool getSo_unit(Node<AlianSounit>*& SoUnit);
	bool ReturnSo_uint(Node<AlianSounit>*& SoUnit);

	bool Add_Drones(Drones* D);
	bool Get_Drones(Drones* D);// dont forget to use fn can attack before make any attack
	//bool Return_Drones(Node<Drones>*& D, int Num_Drones);
};

