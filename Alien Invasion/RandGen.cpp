#include "RandGen.h"
RandGen::RandGen(Game* g)
{
	game = g;
}
float RandGen::gen_rand(int min, int max)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(min, max);
	Rand_Num = dis(gen);
	return  Rand_Num;
}
void RandGen::Create_Unit_Earth(int prob, int ID, int Jt, float H, float AP, int AC)//we didnt handle  case if prob changes
{
	if (prob <= array[20])
	{
		num_GEN_HU++;
		HealingUnit* U = new HealingUnit(ID, Jt, H, AP, AC, this->game);
		game->ADD_HealUint(U);
	}
	else if (prob <= array[1]+array[20])
	{
		num_GEN_ES++;
		Solderunit* U = new Solderunit(ID, Jt, H, AP, AC, this->game);
		game->get_Earmy()->addSo_unit(U);
	}
	else if (prob <= array[1] + array[2]+array[20])
	{
		num_GEN_ET++;
		//proplity for tank
		Tank* U = new Tank(ID, Jt, H, AP, AC,this->game);
		game->get_Earmy()->Add_tank(U);
	}
	else if (prob <= array[1] + array[2] + array[3]+array[20])
	{
		num_GEN_EG++;
		EG* U = new EG(ID, Jt, H, AP, AC,this->game);
		game->get_Earmy()->Add_Earth_Gun(U);
	}
}
void RandGen::Create_Random()
{  
	float prob;

	int ID;
	int Jt;
	float H;
	float AP;
	int AC;
	prob = gen_rand(1, 100);
	if (prob <= array[28])
	{
		flag_inf = true;
	}
	else
	{
		flag_inf = false;
	}
	if (prob <= array[7])
	{
		num_prop++;
		for (int i = 0; i < array[0]; i++)
		{
			Jt = game->get_timestep();
			ID = Earth_count_id++;
			prob = gen_rand(1, 100);
			H = gen_rand(array[10], array[11]);
			AC = gen_rand(array[12], array[13]);
			AP = gen_rand(array[8], array[9]);
			Create_Unit_Earth(prob, ID, Jt, H, AP, AC);
			
		}
		for (int i = 0; i < array[0]; i++)
		{
			Jt = game->get_timestep();
			ID = Alien_count_id++;
			prob = gen_rand(1, 100);
			H = gen_rand(array[16], array[17]);
			AC = gen_rand(array[18], array[19]);
			AP = gen_rand(array[14], array[15]);
			
			Create_Unit_Alian(prob, ID, Jt, H, AP, AC);
			
		}
		if ((game->get_ally()->is_emty()) || game->get_Earmy()->get_allay_canAttack())
		{
			for (int i = 0; i < array[0] && !game->get_Earmy()->retret_ally(); i++)
			{
				Jt = game->get_timestep();
				ID = Allay_count_id++;
				prob = gen_rand(1, 100);
				H = gen_rand(array[23], array[24]);
				AC = gen_rand(array[25], array[26]);
				AP = gen_rand(array[21], array[22]);
				Create_Unit_Ally(prob, ID, Jt, H, AP, AC);
			}
		}
	}
	
}

void RandGen::Create_Unit_Alian(int prob, int ID, int Jt, float H, float AP, int AC)
{
	if (prob <= array[4])
	{
		num_GEN_AS++;
		AlianSounit* U = new AlianSounit(ID, Jt, H, AP, AC, this->game);
		game->get_Aarmy()->addSo_unit(U);

	}
	else if (prob <= array[4] + array[5])
	{
		num_GEN_AM++;
		Monster* U = new Monster(ID, Jt, H, AP, AC,this->game);
		game->get_Aarmy()->Add_monster(U);
		//proplity if monstar
	}
	else if (prob <= array[4] + array[6] + array[5])
	{
		num_GEN_AD++;
		Drones* U = new Drones(ID, Jt, H, AP, AC,this->game);
		game->get_Aarmy()->Add_Drones(U);
	}
}

void RandGen::Create_Unit_Ally(int prob, int ID, int Jt, float H, float AP, int AC)
{
	num_GEN_SU++;
	SU* U = new SU(ID, Jt, H, AP, AC, this->game);         
	game->get_ally()->addSU_unit(U);

}

void RandGen::trans_data()
{
	game->set_data(array);
}


int RandGen::get_num_prop()
{
	return num_prop;
}
int RandGen::get_num_HU()
{
	
	return num_GEN_HU;
}
int RandGen::get_num_GEN_AD()
{
	
	return num_GEN_AD;
}
int RandGen::get_num_GEN_SU()
{
	
	return num_GEN_SU;
}
bool RandGen::get_flag_inf()
{
	return flag_inf;
}
int RandGen::get_num_GEN_AS()
{
	
	return num_GEN_AS;
}
int RandGen::get_num_GEN_AM()
{
	
	return num_GEN_AM;
}
int RandGen::get_num_GEN_ES()
{
	
	return num_GEN_ES;
}
int RandGen::get_num_GEN_ET()
{
	
	return num_GEN_ET;
}
int RandGen::get_num_GEN_EG()
{
	
	return num_GEN_EG;
}
int RandGen::get_num_GEN_HU()
{
	
	return num_GEN_HU;
}
int RandGen::get_total_num_GEN_check()   // to check 
{
	return num_GEN_HU+num_GEN_SU+num_GEN_ES+num_GEN_AS+num_GEN_AD+ num_GEN_AM+num_GEN_ET+num_GEN_EG;
}

RandGen::~RandGen()
{
}

