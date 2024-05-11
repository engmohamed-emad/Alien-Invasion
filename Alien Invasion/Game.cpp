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
	this->Earmy->set_num_HU(num_HU);
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
	  
	   



	 flageE = true;
     flageA = true;
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
			//hu->set_Td(this->get_timestep());
			//hu->set_Ta(this->get_timestep());
			hptr = dynamic_cast<unit*>(hu);
			add_killedlist(hptr);
			num_HU--;
			this->Earmy->set_num_HU(num_HU);
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
	infile.open("C:\\Users\\LENONO\\OneDrive\\Documents\\GitHub\\project\\test.txt");
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
int Game::get_num_check()
{
	return num_HU + num_healed_tank + num_healed_sol;
}

int Game::get_num_killed()
{
	return  num_Killed;
}

void Game::set_left_items()
{
	unit* U;
	Tank* T;
	Solderunit* S;
	LinkedQueue<Tank*>tempT;
	LinkedQueue<Solderunit*>tempS;
	while (this->get_UML_ET(T))
	{
		if (this->get_timestep() - T->get_Heal_Time() < 10)
		{
			tempT.enqueue(T);
		}
		else
		{
			this->get_Earmy()->update_num_killed_tank();
			T->set_Td(this->get_timestep());
			U = dynamic_cast<unit*>(T);
			this->add_killedlist(U);
		}
	}
	while (tempT.dequeue(T))
	{
		this->addto_UML_ET(T);
	}
	            //Ask Hossam
	while (this->get_UML_ES(S))
	{
		if (this->get_timestep() - S->get_Heal_Time() < 10)
		{
			tempS.enqueue(S);
		}
		else
		{
			S->set_Td(this->get_timestep());
			this->get_Earmy()->update_num_killed_sol();
			U = dynamic_cast<unit*>(S);
			this->add_killedlist(U);
		}
	}
	while (tempS.dequeue(S))
	{
		this->addto_UML_ES(S);
	}

	this->Earmy->set_num_Hsol(num_healed_sol);
	this->Earmy->set_num_Htank(num_healed_tank);
}

void Game::output_file()
{
	fstream out_file;
	out_file.open("output.txt", ios::out);
	unit* ptr = nullptr;
	if (out_file.is_open())
	{
		out_file << "		Td	ID	Tj	Df	Dd	Db	\n";
		while (killedlist.dequeue(ptr))
		{
			out_file << "\t\t" << ptr->get_Td() << "\t" << ptr->getID() << "\t" << ptr->get_Tj() << "\t" << ptr->get_Df() << "\t" << ptr->get_Dd() << "\t" << ptr->get_Db() << endl;
		}
		if (!flageE && flageA)
		{
			out_file << "Winner Earth Army \n";
			out_file << "===============Earth Army statistics===================== \n";
			out_file << "ES total number : " <<this->Earmy->get_total_ES_units() << " \n";
			out_file << "ET total number : " << this->Earmy->get_total_ET_units() << "\n";
			out_file << "EG total number : " << this->Earmy->get_total_EG_units() << "\n";
			out_file << "ES Destructed/ES total = " << this->Earmy->get_per_ES() << "%" << "\n";
			out_file << "ET Destructed/ET total = " << this->Earmy->get_per_ET() << "%" << "\n";
			out_file << "EG Destructed/EG total = " << this->Earmy->get_per_EG() << "%" << "\n";
			out_file << "Total Destructed/Total Units = " << this->Earmy->get_per_total() << "%" << "\n";
			out_file << "Average Df = " << this->Earmy->get_per_Df() << "\n";
			out_file << "Average Dd = " << this->Earmy->get_per_Dd() << "\n";
			out_file << "Average Db = " << this->Earmy->get_per_Db() << "\n";
			out_file << "Df/Db % = " << this->Earmy->get_per_Df_Db() << "%" << "\n";
			out_file << "Dd/Db % = " << this->Earmy->get_per_Dd_Db() << "%" << "\n";

			out_file << "Loser Alien Army \n";
			out_file << "===============Alien Army statistics===================== \n";
			out_file << "AS total number : " << this->Aarmy->get_total_num_AS() << " \n";
			out_file << "AM total number : " << this->Aarmy->get_total_num_AM() << "\n";
			out_file << "AD total number : " << this->Aarmy->get_total_num_AD() << "\n";
			out_file << "AS Destructed/ES total = " << this->Aarmy->get_per_AS() << "%" << "\n";
			out_file << "AM Destructed/ET total = " << this->Aarmy->get_per_AM() << "%" << "\n";
			out_file << "AD Destructed/EG total = " << this->Aarmy->get_per_AD() << "%" << "\n";
			out_file << "Total Destructed/Total Units = " << this->Aarmy->get_per_total() << "%" << "\n";
			out_file << "Average Df = " << this->Aarmy->get_per_Df() << "\n";
			out_file << "Average Dd = " << this->Aarmy->get_per_Dd() << "\n";
			out_file << "Average Db = " << this->Aarmy->get_per_Db() << "\n";
			out_file << "Df/Db % = " << this->Aarmy->get_per_Df_Db() << "%" << "\n";
			out_file << "Dd/Db % = " << this->Aarmy->get_per_Dd_Db() << "%" << "\n";

		}
		else if (flageE && !flageA)
		{
			out_file << "Loser Earth Army \n";
			out_file << "===============Earth Army statistics===================== \n";
			out_file << "ES total number : " << this->Earmy->get_total_ES_units() << " \n";
			out_file << "ET total number : " << this->Earmy->get_total_ET_units() << "\n";
			out_file << "EG total number : " << this->Earmy->get_total_EG_units() << "\n";
			out_file << "ES Destructed/ES total = " << this->Earmy->get_per_ES() << "%" << "\n";
			out_file << "ET Destructed/ET total = " << this->Earmy->get_per_ET() << "%" << "\n";
			out_file << "EG Destructed/EG total = " << this->Earmy->get_per_EG() << "%" << "\n";
			out_file << "Total Destructed/Total Units = " << this->Earmy->get_per_total() << "%" << "\n";
			out_file << "Average Df = " << this->Earmy->get_per_Df() << "\n";
			out_file << "Average Dd = " << this->Earmy->get_per_Dd() << "\n";
			out_file << "Average Db = " << this->Earmy->get_per_Db() << "\n";
			out_file << "Df/Db % = " << this->Earmy->get_per_Df_Db() << "%" << "\n";
			out_file << "Dd/Db % = " << this->Earmy->get_per_Dd_Db() << "%" << "\n";

			out_file << "Winner Alien Army \n";
			out_file << "===============Alien Army statistics===================== \n";
			out_file << "AS total number : " << this->Aarmy->get_total_num_AS() << " \n";
			out_file << "AM total number : " << this->Aarmy->get_total_num_AM() << "\n";
			out_file << "AD total number : " << this->Aarmy->get_total_num_AD() << "\n";
			out_file << "AS Destructed/ES total = " << this->Aarmy->get_per_AS() << "%" << "\n";
			out_file << "AM Destructed/ET total = " << this->Aarmy->get_per_AM() << "%" << "\n";
			out_file << "AD Destructed/EG total = " << this->Aarmy->get_per_AD() << "%" << "\n";
			out_file << "Total Destructed/Total Units = " << this->Aarmy->get_per_total() << "%" << "\n";
			out_file << "Average Df = " << this->Aarmy->get_per_Df() << "\n";
			out_file << "Average Dd = " << this->Aarmy->get_per_Dd() << "\n";
			out_file << "Average Db = " << this->Aarmy->get_per_Db() << "\n";
			out_file << "Df/Db % = " << this->Aarmy->get_per_Df_Db() << "%" << "\n";
			out_file << "Dd/Db % = " << this->Aarmy->get_per_Dd_Db() << "%" << "\n";

		}
		else
		{
			out_file << "Drawn \n";
			out_file << "===============Earth Army statistics===================== \n";
			out_file << "ES total number : " << this->Earmy->get_total_ES_units() << " \n";
			out_file << "ET total number : " << this->Earmy->get_total_ET_units() << "\n";
			out_file << "EG total number : " << this->Earmy->get_total_EG_units() << "\n";
			out_file << "ES Destructed/ES total = " << this->Earmy->get_per_ES() << "%" << "\n";
			out_file << "ET Destructed/ET total = " << this->Earmy->get_per_ET() << "%" << "\n";
			out_file << "EG Destructed/EG total = " << this->Earmy->get_per_EG() << "%" << "\n";
			out_file << "Total Destructed/Total Units = " << this->Earmy->get_per_total() << "%" << "\n";
			out_file << "Average Df = " << this->Earmy->get_per_Df() << "\n";
			out_file << "Average Dd = " << this->Earmy->get_per_Dd() << "\n";
			out_file << "Average Db = " << this->Earmy->get_per_Db() << "\n";
			out_file << "Df/Db % = " << this->Earmy->get_per_Df_Db() << "%" << "\n";
			out_file << "Dd/Db % = " << this->Earmy->get_per_Dd_Db() << "%" << "\n";

			out_file << "Drawn \n";
			out_file << "===============Alien Army statistics===================== \n";
			out_file << "AS total number : " << this->Aarmy->get_total_num_AS() << " \n";
			out_file << "AM total number : " << this->Aarmy->get_total_num_AM() << "\n";
			out_file << "AD total number : " << this->Aarmy->get_total_num_AD() << "\n";
			out_file << "AS Destructed/ES total = " << this->Aarmy->get_per_AS() << "%" << "\n";
			out_file << "AM Destructed/ET total = " << this->Aarmy->get_per_AM() << "%" << "\n";
			out_file << "AD Destructed/EG total = " << this->Aarmy->get_per_AD() << "%" << "\n";
			out_file << "Total Destructed/Total Units = " << this->Aarmy->get_per_total() << "%" << "\n";
			out_file << "Average Df = " << this->Aarmy->get_per_Df() << "\n";
			out_file << "Average Dd = " << this->Aarmy->get_per_Dd() << "\n";
			out_file << "Average Db = " << this->Aarmy->get_per_Db() << "\n";
			out_file << "Df/Db % = " << this->Aarmy->get_per_Df_Db() << "%" << "\n";
			out_file << "Dd/Db % = " << this->Aarmy->get_per_Dd_Db() << "%" << "\n";

		}
	}
	else
		cout << "Error file output is not open";

}
