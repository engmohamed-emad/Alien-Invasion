#include<iostream>
#include<string>
#include<fstream>
#include "Game.h"
using namespace std;
Game::Game(){
	Aarmy = new AlienArmy;
	Earmy = new EarthArmy;
	rand = new RandGen(this);
	//rand->set_game(this);
}

AlienArmy* Game:: get_Aarmy()
{
	return Aarmy;
}
EarthArmy* Game::get_Earmy()
{
	return Earmy;
}
RandGen* Game::get_RandGen()
{
	return rand;
}
void Game::set_data(int a[])
{
	for (int i = 0; i < 21; i++)
		a[i] == num[i];
}
void Game::set_timestep(int t)
{
	timestep = t;
}
int Game::get_timestep()
{
	return timestep;
}

bool Game::read_data()
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