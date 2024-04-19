#pragma once
#include <iostream>
#include"ArrayStack.h"
#include"Tank.h"
#include"AlianSounit.h"
#include"Drones.h"
#include"Monster.h"
#include"DronesQueue.h"
#include"SoModQueue.h"
using namespace std;
class AlienArmy
{
protected:
	SoModQueue<AlianSounit*> solders;
	DronesQueue<Drones*> Drone;
	Monster* monsters[1000];
	bool place1 = false;    //to know whether  enqueue or front enqueue 
	bool place2 = false;  //same purpose but in fn get drones
	int num_sol = 0;
	int num_monster = 0;
	int num_drones=0;
	int num_killed = 0;
public:
	bool ADD_unit(unit*& ptr);
	bool addSo_unit(AlianSounit* s);
	bool getSo_unit(AlianSounit*& SoUnit);
	bool ReturnSo_uint(AlianSounit*& SoUnit);
	bool Add_Drones(Drones* D);
	bool Get_Drones(Drones* D);// dont forget to use fn can attack before make any attack
	//bool Return_Drones(Node<Drones>*& D, int Num_Drones);
	//edit
	bool Add_monster(Monster* M);
	void print();
};

