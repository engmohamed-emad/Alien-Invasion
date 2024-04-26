#include<iostream>
#include<string>
#include<fstream>
#include "Game.h"
using namespace std;
Game::Game() {
	Aarmy = new AlienArmy;
	Earmy = new EarthArmy;
	rand = new RandGen(this);
	num_Killed = 0;
}

AlienArmy* Game::get_Aarmy()
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
		a[i] = num[i];
}

void Game::add_killedlist(unit*& U)
{
	if (U != nullptr)
	{
		killedlist.enqueue(U);
		num_Killed++;
	}
	else
		return;
}
void Game::print_Killed()
{    
	cout << "==============  Killed Units ==============" << endl;
	cout << num_Killed << "  [";
	killedlist.print();
	cout << "]" << endl;
}
void Game::print_armys()
{
	this->get_Earmy()->print();
	cout << endl;
	this->get_Aarmy()->print();
	cout << endl;
}
void Game::addto_UML_ES(Solderunit* s)
{
	UML_ES.enqueue(s, 1000 - s->getcurrhealth());
}
void Game::set_timestep(int t)
{
	timestep = t;
}
int Game::get_timestep()
{
	return timestep;
}

void Game::set_arr(int arr[])
{
	for (int i = 0; i < 21; i++)
		num[i] = arr[i];
}
//LinkedQueue<unit*>* Game::gt_temp()
//{
//	return &templist;
//}
Game::~Game()
{
	delete Aarmy;
	delete Earmy;
	delete rand;
	unit* temp;
	while (killedlist.dequeue(temp))
	{
		delete temp;
		temp = nullptr;
	}
}

bool Game::read_data()
{
	// do not forget to change file path before running
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
		num[20] = 0;
		return true;
	}
	else
	{
		cout << "Error" << endl;
		return false;
	}

}