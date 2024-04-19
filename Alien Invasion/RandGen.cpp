//#include "RandGen.h"
//float RandGen::gen_rand(int min, int max)
//{
//	random_device rd;
//	mt19937 gen(rd());
//	uniform_int_distribution<int> dis(min, max);
//	Rand_Num = dis(gen);
//	return  Rand_Num;
//}
//void RandGen::Create_Unit_Earth(int prob, int ID, int Jt, float H, float AP, int AC)
//{
//	//review in case of diffrant order of proplities
//	if (prob <= array[1])
//	{
//		//edit
//		Solderunit* U = new Solderunit(ID, Jt, H, AP, AC); 
//		game->get_Earmy()->addSo_unit(U);
//	}
//	else if (prob <= array[1] + array[2])
//	{
//		//proplity for tank
//		Tank* U = new Tank(ID, Jt, H, AP, AC);
//		game->get_Earmy()->Add_tank(U);
//	}
//	else if (prob <= array[1] + array[2] + array[3])
//	{
//		//edit
//		EG* U = new EG(ID, Jt, H, AP, AC);
//		game->get_Earmy()->Add_Earth_Gun(U);
//	}
//}
//void RandGen::Create_Random()
//{    //we have to handle ID and Jt
//	float prob;
//	int ID;
//	int Jt;
//	float H;
//	float AP;
//	int AC;
//	prob=gen_rand(1, 100);
//	if (prob <= array[7])
//	{   
//		for (int i = 0; i < array[0]; i++)
//		{
//			Jt = game->get_timestep();
//			ID = Earth_count_id++;
//			prob = gen_rand(1, 100);
//			H = gen_rand(array[10], array[11]);
//			AC= gen_rand(array[12], array[13]);
//			AP= gen_rand(array[8], array[9]);
//			Create_Unit_Earth(prob, ID, Jt, H, AP, AC);
//			//call Earth arramy using game pointer to add this unit
//		}
//
//		for (int i = 0; i < array[0]; i++)
//		{
//			for (int i = 0; i < array[0]; i++)
//			{
//				ID = Alien_count_id++;
//				prob = gen_rand(1, 100);
//				H = gen_rand(array[16], array[17]);
//				AC = gen_rand(array[18], array[19]);
//				AP = gen_rand(array[14], array[15]);
//				Create_Unit_Alian(prob,ID ,Jt , H, AP, AC);
//				//call Alian arramy using game pointer to add this unit
//			}
//		}
//	}
//}
//
//void RandGen::Create_Unit_Alian(int prob, int ID, int Jt, float H, float AP, int AC)
//{
//	if (prob <= array[4])
//	{
//		AlianSounit* U = new AlianSounit(ID, Jt, H, AP, AC);
//		game->get_Aarmy()->addSo_unit(U);
//		
//	}
//	else if (prob <= array[4] + array[5])
//	{
//		//proplity if monstar
//	}
//	else if (prob <= array[4]+ array[6]+ array[5])
//	{
//		Drones* U = new Drones(ID, Jt, H, AP, AC);
//		game->get_Aarmy()->Add_Drones(U);
//	}
//}
//
//void RandGen::trans_data()
//{
//	 game->set_data(array);
//}
//
//void RandGen::set_game(Game* g)
//{
//	game = g;
//}
