#include<iostream>
#include<string>
#include<fstream>
#include"solderunit.h"
#include"Tank.h"
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
void Game::addto_UML_ES(Solderunit*& s)
{
	num_healed_sol++;
	UML_ES.enqueue(s, 1000 - s->getcurrhealth());
}
bool Game::get_UML_ES(Solderunit* &s) //
{
	int pri = 0;
	if (UML_ES.dequeue(s, pri))
	{
		num_healed_sol--;
		return true;
	}
	else return false;
}
bool Game::addto_UML_ET(Tank* &T)  ///
{
	num_healed_tank++;
	return UML_ET.enqueue(T);
}
bool Game::get_UML_ET(Tank* &s)
{
	if (UML_ET.dequeue(s))
	{
		num_healed_tank--;
		return true;
	}
	else return false;
}
void Game::ADD_HealUint(HealingUnit* H)
{
	if(HU.push(H))
	num_HU++;
}
bool Game::Get_HU(HealingUnit* H)
{
	if (HU.pop(H))
	{
		num_HU--;
		return true;
	}
	else return false;
}
//void Game::Healing()   //check
//{
//	while (!UML_ES.isEmpty()&& !UML_ET.isEmpty())
//	{
//		HealingUnit* hu;
//		unit* khu;
//		if (HU.pop(hu))
//		{
//			hu->attack();
//			khu = dynamic_cast<unit*>(hu);
//			add_killedlist(khu);
//		}
//		else break;
//	}
//}
int Game::fight()
{

	bool flageE = true;
	bool flageA = true;
	HealingUnit* hu;
	unit* hptr;
	flageE = this->Earmy->Attack_Alien();
	flageA = this->Aarmy->Attack_Earth();
	if (!UML_ES.isEmpty() || !UML_ET.isEmpty())
	{
		if (HU.pop(hu))
		{
			hu->attack();
			total_num_healed += hu->get_num_healed();
			hptr = dynamic_cast<unit*>(hu);
			add_killedlist(hptr);
			num_HU--;
		}
	}
	if (flageE && flageA)
	{
		return 0;
	}
	if (!flageE && flageA)
	{
		return 1;
	}
	if (flageE && !flageA)
	{
		return -1;
	}
	else return 2;
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
void Game::print_healing_lists()
{
	cout << "======================== Healing lists ============================\n";
	cout << "HU " << num_HU << " ["  ;
	HU.print();
	cout << "]\n";
	cout << "UML_Tnaks " << num_healed_tank << " [";
	UML_ET.print();
	cout << "]\n";
	cout << "UML_soldiers " << num_healed_sol << " [";
	UML_ES.print();
	cout << "]\n\n";
}
int Game::get_total_num_healed()
{
	return total_num_healed;
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
	infile.open("E:\\Documents\\GitHub\\project\\test.txt");
	if (infile.is_open())
	{
		string line;
		getline(infile, line);
		num[0] = stoi(line.c_str());
		getline(infile, line, ' ');
		num[1] = stoi(line.c_str());
		getline(infile, line, ' ');
		num[2] = stoi(line.c_str());
		getline(infile, line, ' ');
		num[3] = stoi(line.c_str());
		getline(infile, line);
		num[20] = stoi(line.c_str());
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