#include <iostream>
#include"DronesQueue.h"
#include"Drones.h"
#include<random>
#include"EarthArmy.h"
#include"AlienArmy.h"
#include"unit.h"
#include <fstream>
#include"SoModQueue.h"
#include"priQueue.h"
#include <string>
#include"EG.h"
#include"Game.h"
using namespace std;
double generate_ran(int num1, int num2)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(num1, num2); 
	
		int random_num = dis(gen);
		return  random_num;

}

int main()
{
	unit* pt = nullptr;
	int x;
	string s;
	//int arr[21] = { 7, 70, 20, 10, 50, 30, 20, 30, 3, 50, 30, 90, 2, 5, 1, 20, 40, 80, 1, 4, 0 };
	//mygame->set_arr(arr);
	Game* mygame = new Game;
	mygame->read_data();
	RandGen* rand = mygame->get_RandGen();
	rand->trans_data();
	for (int i = 1; i <= 50; i++)
	{
		mygame->set_timestep(i);
		rand->Create_Random();
		x = generate_ran(1, 100);
		cout << "Current time step " << i << endl;
		cout << "X= " << x << endl; 
		//we did this to check before and after 
		/*mygame->get_Aarmy()->print();
		cout << endl;
		mygame->get_Earmy()->print();
		cout << endl;
		mygame->print_Killed();
		cout << endl;
		cout << "=================================================" << endl;*/
		if (x < 10)
		{
			Solderunit* ES = nullptr;
			mygame->get_Earmy()->ReturnSo_uint(ES, pt);
			mygame->get_Earmy()->addSo_unit(ES);
		}
		else if (x>10 && x < 20)
		{
			Tank* t = nullptr;
			mygame->get_Earmy()->print();
			mygame->get_Earmy()->return_tank(t, pt);
			mygame->add_killedlist(pt);
			mygame->get_Earmy()->print();
			cout << endl;
			mygame->print_Killed();
		}
		else if (x>20 && x < 30)
		{
			int pri = 0;
			EG* G = nullptr;
			mygame->get_Earmy()->Return_Gun(G, pri, pt);
			G->dec_health((G->getcurrhealth() / 2));
			mygame->get_Earmy()->Add_Earth_Gun(G);
		}
		else if (x>30 && x < 40)
		{
			AlianSounit* AS = nullptr;
			LinkedQueue<AlianSounit*>Q;

			for (int i = 0; i < 5; i++)
			{
				if (mygame->get_Aarmy()->ReturnSo_uint(AS, pt))
				{
					AS->dec_health(10);
					Q.enqueue(AS);
				}
				else
					break;
			}

			while (Q.dequeue(AS))
			{
				mygame->get_Aarmy()->addSo_unit(AS);
			}
		}
		else if (x>40 && x< 50)
		{
			LinkedQueue<Monster*>Q;
			Monster* M = nullptr;

			for (int i = 0; i < 5; i++)
			{
				if (mygame->get_Aarmy()->get_monster(M, pt))
				{
					Q.enqueue(M);
				}
				else
					break;
			}

			while (Q.dequeue(M))
			{
				mygame->get_Aarmy()->Add_monster(M);
			}

		}
		else if (x>50 && x < 60)
		{
			Drones* D;
			LinkedQueue<unit*>Q;
			for (int i = 0; i < 6; i++)
			{
				if (mygame->get_Aarmy()->Get_Drones(D, pt))
				{
					Q.enqueue(pt);
				}
				else
					break;
			}
			while (Q.dequeue(pt))
			{
				mygame->add_killedlist(pt);
			}
		}
		mygame->get_Aarmy()->print();
		cout << endl;
		mygame->get_Earmy()->print();
		cout << endl;
		mygame->print_Killed();
		cout << endl;
		//print enter to continue
		getline(cin,s);
}

	delete mygame;
	mygame = nullptr;
	return 0;
}