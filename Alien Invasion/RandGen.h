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
	int array[29];
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
	//array[21]-> min for unit power for ally
	//array[22]-> max for unit power for ally
	//array[23]-> min of health for ally
	//array[24]-> max of health for ally
	//array[25]-> min of attack capcity for ally
	//array[26]-> max of attack capcity for ally
	//array[27]->persenteg to recust ally 
	//array[28]->persenteg to recust ally 
	int Earth_count_id = 1;
	int Alien_count_id = 2000;
	int Allay_count_id = 4000;
	int Rand_Num;
	Game* game;
	int num_prop = 0;
	int num_GEN_HU = 0;
	int num_GEN_ES = 0;
	int num_GEN_ET = 0;
	int num_GEN_EG = 0;
	int num_GEN_AS = 0;
	int num_GEN_AM = 0;
	int num_GEN_AD = 0;
	int num_GEN_SU = 0;
	bool flag_inf = false;
public:
	RandGen(Game* g);
	float gen_rand(int min, int max);
	void Create_Unit_Earth(int prob, int ID, int Jt, float H, float AP, int AC);
	void Create_Random();
	void Create_Unit_Alian(int prob, int ID, int Jt, float H, float AP, int AC);
	void Create_Unit_Ally(int prob, int ID, int Jt, float H, float AP, int AC);
	void trans_data();
	int get_num_prop();  //for check
	int get_num_HU(); //for check 
	int get_num_GEN_HU ();
	int get_num_GEN_ES ();
	int get_num_GEN_ET ();
	int get_num_GEN_EG ();
	int get_num_GEN_AS ();
	int get_num_GEN_AM ();
	int get_num_GEN_AD ();
	int get_num_GEN_SU();
	bool get_flag_inf();
	int get_total_num_GEN_check();
	/*void set_game(Game* g);*/
};
#endif
// game random