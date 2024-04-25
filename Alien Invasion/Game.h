#ifndef Game_h
#define Game_h
#include<iostream>
#include"AlienArmy.h"
#include"EarthArmy.h"
#include"LinkedQueue.h"
#include"unit.h"
#include"RandGen.h"
#include"HealingUnit.h"
class RandGen;
class Game
{    //mohamed Ayman
	AlienArmy* Aarmy;
	EarthArmy* Earmy;
	RandGen* rand;
	LinkedQueue<unit*>killedlist;
	
	LinkedQueue<HealingUnit*> HU;
	priQueue<Solderunit*> UML_ES;
	LinkedQueue<Tank*>UML_ET;

	int num[21];
	int timestep = 0;
	int num_Killed;
public:
	Game();
	AlienArmy* get_Aarmy();
	EarthArmy* get_Earmy();
	RandGen* get_RandGen();
	bool read_data();
	void set_data(int a[]);
	void set_timestep(int t);
	int get_timestep();
	void add_killedlist(unit*&U);
	void print_Killed();
	void print_armys();
	void Earmy_attak();
	void Aarmy_attak();
	void Heal_unit();
	//void fight()
	// {
	//		
	//		Earmy_attak();
	//		killedlist
	//		Aarmy_attak();
	//		killedlist
	//		healed
	//		
	// 
	// }
	// to be able to run project with array (easier to test while working)
	void set_arr(int arr[]);
	~Game();
};
#endif


