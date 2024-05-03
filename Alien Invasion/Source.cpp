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
	// we used it while testing the file while working as it was easier than file
	//int arr[21] = { 7, 70, 20, 10, 50, 30, 20, 30, 3, 50, 30, 90, 2, 5, 1, 20, 40, 80, 1, 4, 0 };
	//mygame->set_arr(arr);
	Game* mygame = new Game;
	mygame->read_data();
	RandGen* rand = mygame->get_RandGen();
	rand->trans_data();
	int flag = 0;
	for (int i = 1; i <= 200||(!flag); i++)
	{
		mygame->set_timestep(i);
		rand->Create_Random();
		cout << "Current time step " << i << endl;
		mygame->get_Earmy()->print();
		cout << endl;
		mygame->get_Aarmy()->print();
		cout << endl;
		mygame->print_healing_lists();
		cout << "===================Units fighting at current timestep========================\n";
	    flag = mygame->fight();
		cout << endl;

	//	mygame->Healing();
		cout << endl;
		mygame->print_Killed();
		cout << endl;
		//print enter to continue
		cout << "========================================================================================================================================\n";
		//getline(cin,s);
    }
	if (flag == 1)
	{
		cout << "Winner Earth Army\n";
		mygame->get_Earmy()->print_statistics();
		cout << "healed units/total units = " << (float((mygame->get_total_num_healed() * 100) / mygame->get_Earmy()->get_total_units()))<<"%\n\n";
		cout << "Loser Alien Army\n";
		mygame->get_Aarmy()->print_statistics();
	}
	else if (flag == -1)
	{
		cout << "Loser Earth Army\n";
		mygame->get_Earmy()->print_statistics();
		cout << "healed units/total units = " << (float((mygame->get_total_num_healed() * 100) / mygame->get_Earmy()->get_total_units())) << "%\n\n";
		cout << "Winner Alien Army\n";
		mygame->get_Aarmy()->print_statistics();
	}
	else
	{
		cout << "Draw\n";
		mygame->get_Earmy()->print_statistics();
		cout << "healed units/total units = " << (float((mygame->get_total_num_healed() * 100) / mygame->get_Earmy()->get_total_units())) << "%\n\n";
		cout << "Draw\n";
		mygame->get_Aarmy()->print_statistics();	
	}
	delete mygame;
	mygame = nullptr;
	return 0;
}