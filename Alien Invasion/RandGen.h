#ifndef RandGen_h
#define RandGen_h
#include<random>
#include"Game.h"
#include"unit.h"
#include"Drones.h"
#include "AlianSounit.h"
#include "Solderunit.h"
#include"EG.h"
using namespace std;
class Game;
class RandGen
{

private:
	int array[21];
	//array[0]-> number of unit to generate each timestep 
	//array[1]-> % of ES
	//array[2]-> % of ET
	//array[3]-> % of EG
	//array[4]-> % of AS
    //array[5]-> % of AM
	//array[6]-> % of AD
	//array[7]->prob used by randgen to generate new units of not
	//array[8]-> min for unit power for Earth
	//array[9]-> max for unit power for Earth
	//array[10]-> min of health for Earth
    //array[11]-> max of health for Earth
	//array[12]-> min of attack capcity for Earth
	//array[13]-> max of attack capcity for Earth
	//array[14]-> min for unit power for Alien
	//array[15]-> max for unit power for Alien
	//array[16]-> min of health for Alien
	//array[17]-> max of health for Alien
	//array[18]-> min of attack capcity for Alien
	//array[19]-> max of attack capcity for Alien
	//aarray[20]->empty place for H.U in phase 2
	int Earth_count_id=1;
	int Alien_count_id = 2000;
	int Rand_Num;
	Game* game;
public:
	RandGen( Game* g);
	float gen_rand(int min, int max);
	void Create_Unit_Earth(int prob, int ID, int Jt, float H, float AP, int AC);
	void Create_Random();
	void Create_Unit_Alian(int prob, int ID, int Jt, float H, float AP, int AC);
	void trans_data();
	/*void set_game(Game* g);*/
};
#endif
// game random