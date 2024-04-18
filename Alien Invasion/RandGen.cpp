#include "RandGen.h"

float RandGen::gen_rand(int min, int max)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(min, max);
	 Rand_Num = dis(gen);
	return  Rand_Num;
}

unit*& RandGen::Create_Unit_Earth(int prob, int ID, int Jt, float H, float AP, int AC)
{
	//review in case of diffrant order of proplities
	if (prob <= array[1])
	{
		unit* U = new Solderunit(ID, Jt, H, AP, AC);
		return U;

	}
	else if (prob <= array[1] + array[2])
	{
		//proplity for tank
	}
	else if (prob <= array[1] + array[2] + array[3])
	{
		unit* U = new EG(ID, Jt, H, AP, AC);
		return U;
	}
}

void RandGen::Create_Random()
{    //we have to handle ID and Jt
	float prob;
	int ID;
	int Jt;
	float H;
	float AP;
	int AC;
	unit* pt;
	prob=gen_rand(1, 100);
	if (prob <= array[7])
	{   
		for (int i = 0; i < array[0]; i++)
		{
			prob = gen_rand(1, 100);
			H = gen_rand(array[10], array[11]);
			AC= gen_rand(array[12], array[13]);
			AP= gen_rand(array[8], array[9]);
			Create_Unit_Earth(prob, ID, Jt, H, AP, AC);
			//call Earth arramy using game pointer to add this unit
		}

		for (int i = 0; i < array[0]; i++)
		{
			for (int i = 0; i < array[0]; i++)
			{
				prob = gen_rand(1, 100);
				H = gen_rand(array[16], array[17]);
				AC = gen_rand(array[18], array[19]);
				AP = gen_rand(array[14], array[15]);
				pt=Create_Unit_Alian(prob,ID ,Jt , H, AP, AC);
				//call Alian arramy using game pointer to add this unit
			}
		}

	}
	
}

unit*& RandGen::Create_Unit_Alian(int prob, int ID, int Jt, float H, float AP, int AC)
{
	if (prob <= array[4])
	{
		unit* U = new AlianSounit(ID, Jt, H, AP, AC);
		return U;
		
	}
	else if (prob <= array[4] + array[5])
	{
		//proplity if monstar
	}
	else if (prob <= array[4]+ array[6]+ array[5])
	{
		unit* U = new Drones(ID, Jt, H, AP, AC);
		return U;
	}

}
