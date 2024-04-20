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
//// function for files 
//bool readfile(string name, int num[], int n)
//{
//	fstream infile;
//	infile.open("C:\\Users\\pc\\Documents\\GitHub\\project\\test.txt");
//	if (infile.is_open())
//	{
//		string line;
//		getline(infile, line);
//		num[0] = stoi(line.c_str());
//		getline(infile, line, ' ');
//		num[1] = stoi(line.c_str());
//		getline(infile, line, ' ');
//		num[2] = stoi(line.c_str());
//		getline(infile, line);
//		num[3] = stoi(line.c_str());
//		getline(infile, line, ' ');
//		num[4] = stoi(line.c_str());
//		getline(infile, line, ' ');
//		num[5] = stoi(line.c_str());
//		getline(infile, line);
//		num[6] = stoi(line.c_str());
//		getline(infile, line);
//		num[7] = stoi(line.c_str());
//
//		getline(infile, line, '-');
//		num[8] = stoi(line.c_str());
//		getline(infile, line, ' ');
//		num[9] = stoi(line.c_str());
//		getline(infile, line, '-');
//		num[10] = stoi(line.c_str());
//		getline(infile, line, ' ');
//		num[11] = stoi(line.c_str());
//		getline(infile, line, '-');
//		num[12] = stoi(line.c_str());
//		getline(infile, line);
//		num[13] = stoi(line.c_str());
//
//		getline(infile, line, '-');
//		num[14] = stoi(line.c_str());
//		getline(infile, line, ' ');
//		num[15] = stoi(line.c_str());
//		getline(infile, line, '-');
//		num[16] = stoi(line.c_str());
//		getline(infile, line, ' ');
//		num[17] = stoi(line.c_str());
//		getline(infile, line, '-');
//		num[18] = stoi(line.c_str());
//		getline(infile, line);
//		num[19] = stoi(line.c_str());
//		return true;
//	}
//	else
//	{
//		cout << "Error" << endl;
//		return false;
//	}
//
//}
int main()
{
	int x;
	int arr[21] = { 7, 70, 20, 10, 80, 12, 8, 30, 3, 50, 30, 90, 2, 5, 1, 20, 40, 80, 1, 4, 0 };
	Game* mygame = new Game;
	mygame->set_arr(arr);
	RandGen* rand = mygame->get_RandGen();
	rand->trans_data();
	for (int i = 1; i <= 1; i++)
	{
		mygame->set_timestep(i);
		rand->Create_Random();
		x = 5;//generate_ran(1, 100);
		if (x < 10)
		{
			Solderunit* ES = nullptr;
			mygame->get_Earmy()->print();
			//mygame->get_Earmy()->ReturnSo_uint(ES);
			cout << endl;
			mygame->get_Earmy()->print();
			cout << endl;
			//mygame->get_Earmy()->addSo_unit(ES);
		}
		else if (x < 20)
		{

		}
		else if (x < 30)
		{

		}
		else if (x < 40)
		{

		}
		else if (x < 50)
		{

		}
		else if (x < 60)
		{

		}
		mygame->get_Aarmy()->print();
		cout << endl;
		mygame->get_Earmy()->print();
	}
	return 0;
}