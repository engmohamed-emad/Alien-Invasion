#pragma once
#include <iostream>
#include<random>
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
	int num_killed_sol = 0;
	int num_killed_monster = 0;
	int num_killed_drones = 0;
	int Df = 0;
	int Dd = 0;
	int Db = 0;
public:
	bool ADD_unit(unit*& ptr);
	bool addSo_unit(AlianSounit*& s);
	bool ReturnSo_uint(AlianSounit*& SoUnit,unit*& pt);
	bool get_monster(Monster*& M, unit*& pt);
	bool Add_Drones(Drones*& D);
	bool Get_Drones(Drones*& D, unit*& pt);// dont forget to use fn can attack before make any attack
	int get_num_sol();
	//bool Return_Drones(Node<Drones>*& D, int Num_Drones);
	//edit
	~AlienArmy();
	bool Add_monster(Monster*& M);
	void print();
	void update_num_killed_sol();
	void update_num_killed_monster();
	void update_num_killed_drones();
	void ubdate_D(unit*&U);
	bool Attack_Earth();
};

