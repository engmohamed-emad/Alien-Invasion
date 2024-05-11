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
	int mode;
	unit* pt = nullptr;
	int x;
	string s;
	// we used it while testing the file while working as it was easier than file
	//int arr[21] = { 7, 70, 20, 10, 50, 30, 20, 30, 3, 50, 30, 90, 2, 5, 1, 20, 40, 80, 1, 4, 0 };
	//mygame->set_arr(arr);
	Game* mygame = new Game;
	cout << " Enter 1 for interactive and 0 for silant." << endl;
	cin >> mode;
	if (mode == 0)
		mygame->set_mode(false);

	mygame->read_data();
	RandGen* rand = mygame->get_RandGen();
	rand->trans_data();
	int flag = 0;
	for (int i = 1; i <= 300; i++)
	{
		mygame->set_timestep(i);
		rand->Create_Random();
		if (mygame->is_interactive())
		{
			cout << "Current time step " << i << endl;
			mygame->get_Earmy()->print();
			cout << endl;
			mygame->get_Aarmy()->print();
			cout << endl;
			mygame->print_healing_lists();
			cout << "===================Units fighting at current timestep========================\n";
		}
	    flag = mygame->fight();
		if (mygame->is_interactive())
			cout << endl;

	//	mygame->Healing();
		if (mygame->is_interactive())
		{
			cout << endl;
			cout << "===================After  fighting at current timestep=====================================\n";
			mygame->get_Earmy()->print();
			cout << endl;
			mygame->get_Aarmy()->print();
			cout << endl;
			mygame->print_healing_lists();
			//print enter to continue
			cout << endl;
			mygame->print_Killed();
		}
		int num_real = mygame->get_num_check() + mygame->get_Aarmy()->get_num_Army() + mygame->get_Earmy()->get_num_Army() + mygame->get_num_killed();
		int num_expected = rand->get_num_prop() * 6;
		if (mygame->is_interactive())
		{
			cout << "=====================================================================================================\n";
			cout << "prop : " << rand->get_num_prop() << "\nnum real : " << num_real << "\nnum expected : " << num_expected << "\n";
			cout << "=====================================================================================================\n";
		}
		if (num_real != num_expected)
		{
			cout << "ERROR\n";
			getline(cin, s);
		}
		if (mygame->is_interactive())
		{
			cout << "\n";
			cout << "========================================================================================================================================\n";
		}
		//getline(cin,s);
    }
	if (flag == 1)
	{
		if (mygame->is_interactive())
			cout << "Winner Earth Army\n";
		mygame->set_left_items();
		if (mygame->is_interactive())
			mygame->get_Earmy()->print_statistics();
		//cout << "healed units/total units = " << (float((mygame->get_total_num_healed() * 100) / mygame->get_Earmy()->get_total_units()))<<"%\n\n";
		if (mygame->is_interactive())
		{
			cout << "Loser Alien Army\n";
			mygame->get_Aarmy()->print_statistics();
		}
	}
	else if (flag == -1)
	{
		if (mygame->is_interactive())
			cout << "Loser Earth Army\n";
		mygame->set_left_items();
		if (mygame->is_interactive())
		{
			mygame->get_Earmy()->print_statistics();
			//	cout << "healed units/total units = " << (float((mygame->get_total_num_healed() * 100) / mygame->get_Earmy()->get_total_units())) << "%\n\n";
			cout << "Winner Alien Army\n";
			mygame->get_Aarmy()->print_statistics();
		}
	}
	else
	{
		if (mygame->is_interactive())
			cout << "Draw\n";
		mygame->set_left_items();
		if (mygame->is_interactive())
		{
			mygame->get_Earmy()->print_statistics();
			//		cout << "healed units/total units = " << (float((mygame->get_total_num_healed() * 100) / mygame->get_Earmy()->get_total_units())) << "%\n\n";
			cout << "Draw\n";
			mygame->get_Aarmy()->print_statistics();
		}
	}
	if (mygame->is_interactive())
		cout << "\n\nnum HU Generated : " << rand->get_num_HU() << endl;
	mygame->output_file();
	if (!mygame->is_interactive())
	{
		cout << "Silent mode\nSimulation starts....\nSimulation ends, output file criated\n";
	}
	delete mygame;
	mygame = nullptr;
	return 0;
}