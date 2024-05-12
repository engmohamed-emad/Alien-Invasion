#ifndef Game_h
#define Game_h
#include<iostream>
#include"AlienArmy.h"
#include"EarthArmy.h"
#include"LinkedQueue.h"
#include"ArrayStack.h"
#include"unit.h"
#include"RandGen.h"
#include"HealingUnit.h"
#include"solderunit.h"
#include"Tank.h"
#include"ally_army.h"
class RandGen;
class HealingUnit;
class EarthArmy;
class AlienArmy;
class ally_army;
class unit;
class EG;
class Game
{    //mohamed Ayman
	bool is_active = true;

	/// ////////////
	AlienArmy* Aarmy;
	EarthArmy* Earmy;
	ally_army* ally;
	RandGen* rand;
	LinkedQueue<unit*>killedlist;
	ArrayStack<HealingUnit*> HU;
	priQueue<Solderunit*> UML_ES;        
	LinkedQueue<Tank*>UML_ET;
	int num[29];
	int timestep = 0;
	int num_Killed;
	int num_healed_tank = 0;  //in UML
	int num_healed_sol = 0;  // in UML
	int num_HU=0;
	int total_num_healed=0;   // healed and returned to its original list
	bool flageE = true;
	bool flageA = true;
	
public:
	Game();
	void set_mode(bool f);
	bool is_interactive();
	/// ///////
	AlienArmy* get_Aarmy();
	EarthArmy* get_Earmy();
	ally_army* get_ally();
	RandGen* get_RandGen();
	bool read_data();
	void set_data(int a[]);
	void set_timestep(int t);
	int get_timestep();
	void add_killedlist(unit*&U);
	void print_Killed();
	void print_armys();
	void addto_UML_ES(Solderunit* &s);
	bool get_UML_ES(Solderunit*& s);
	bool addto_UML_ET(Tank*& T);
	bool get_UML_ET(Tank*& s);
	void ADD_HealUint(HealingUnit*H);
	bool Get_HU(HealingUnit* H);
//	void Healing();
	int fight();
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
	void print_healing_lists();
	int get_total_num_healed();
	int get_num_check();  //for check
	int get_num_killed();  //for check
	void set_left_items();  // to handle UML_lists after last time step
	void output_file();
	//LinkedQueue<unit*>* gt_temp();
	~Game();
};
#endif


