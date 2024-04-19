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
using namespace std;
double generate_ran(int num1, int num2)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(num1, num2); 
	
		int random_num = dis(gen);
		return  random_num;
	
}
// function for files 
bool readfile(string name, int num[], int n)
{
	fstream infile;
	infile.open("C:\\Users\\pc\\Documents\\GitHub\\project\\test.txt");
	if (infile.is_open())
	{
		string line;
		getline(infile, line);
		num[0] = stoi(line.c_str());
		getline(infile, line, ' ');
		num[1] = stoi(line.c_str());
		getline(infile, line, ' ');
		num[2] = stoi(line.c_str());
		getline(infile, line);
		num[3] = stoi(line.c_str());
		getline(infile, line, ' ');
		num[4] = stoi(line.c_str());
		getline(infile, line, ' ');
		num[5] = stoi(line.c_str());
		getline(infile, line);
		num[6] = stoi(line.c_str());
		getline(infile, line);
		num[7] = stoi(line.c_str());

		getline(infile, line, '-');
		num[8] = stoi(line.c_str());
		getline(infile, line, ' ');
		num[9] = stoi(line.c_str());
		getline(infile, line, '-');
		num[10] = stoi(line.c_str());
		getline(infile, line, ' ');
		num[11] = stoi(line.c_str());
		getline(infile, line, '-');
		num[12] = stoi(line.c_str());
		getline(infile, line);
		num[13] = stoi(line.c_str());

		getline(infile, line, '-');
		num[14] = stoi(line.c_str());
		getline(infile, line, ' ');
		num[15] = stoi(line.c_str());
		getline(infile, line, '-');
		num[16] = stoi(line.c_str());
		getline(infile, line, ' ');
		num[17] = stoi(line.c_str());
		getline(infile, line, '-');
		num[18] = stoi(line.c_str());
		getline(infile, line);
		num[19] = stoi(line.c_str());
		return true;
	}
	else
	{
		cout << "Error" << endl;
		return false;
	}

}
int main()
{

	//mohamed Ayman
	//in each loop you have to set JT
	
	return 0;
}