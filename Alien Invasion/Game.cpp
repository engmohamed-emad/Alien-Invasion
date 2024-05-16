#include<iostream>
#include<string>
#include<fstream>
#include"solderunit.h"
#include"Tank.h"
#include "Game.h"
#define RESET   "\033[0m"
#define RED     "\033[31m"  

using namespace std;
Game::Game() {
	Aarmy = new AlienArmy;
	Earmy = new EarthArmy;
	ally = new ally_army;
	rand = new RandGen(this);
	num_Killed = 0;
}
void Game::set_mode(bool f)
{
	is_active = f;
}
bool Game::is_interactive()
{
	return is_active;
}
void Game::remove_allSU()
{
	SU* S_U;
	unit* SU_ptr;
	while (this->ally->ReturnSU_uint(S_U, SU_ptr))
	{
		if (!(S_U->get_firstAttack()))
		{
			S_U->set_Ta(this->get_timestep());
		}
		S_U->set_Td(this->get_timestep());
		this->add_killedlist(SU_ptr);
	}
}
AlienArmy* Game::get_Aarmy()
{
	return Aarmy;
}
EarthArmy* Game::get_Earmy()
{
	return Earmy;
}
ally_army* Game::get_ally()
{
	return ally;
}
RandGen* Game::get_RandGen()
{
	return rand;
}
void Game::set_data(int a[])
{
	for (int i = 0; i < 29; i++)
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
	this->print_healing_lists();
	cout << endl;
	this->get_ally()->print();
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
void Game::ADD_HealUint(HealingUnit*& H)
{
	if(HU.push(H))
	num_HU++;
}
bool Game::Get_HU(HealingUnit*& H)
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
	flageAll = true;
	HealingUnit* hu;
	unit* hptr;
	flageE = this->Earmy->Attack_Alien();
	flageA = this->Aarmy->Attack_Earth();
	this->Earmy->set_num_hsol(num_healed_sol);
	if(this->Earmy->get_allay_canAttack())
		flageAll = this->ally->Attack_Alien();
	else if(this->Earmy->retret_ally())
	{
		this->remove_allSU();
	}
	cout << endl;
	this->print_healing_lists();
	cout<< endl;
	if (!UML_ES.isEmpty() || !UML_ET.isEmpty())
	{
		if (HU.pop(hu))
		{
			hu->attack();
			total_num_healed += hu->get_num_healed();
			hu->set_Td(this->get_timestep());
			hu->set_Ta(this->get_timestep());
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
	//infile.open("E:\\Documents\\GitHub\\project\\test.txt");//Emad
	//infile.open("C:\\Users\\pc\\Documents\\GitHub\\project\\test.txt");//Hossam
	infile.open("C:\\Users\\LENONO\\OneDrive\\Documents\\GitHub\\project\\test.txt");//Ayman
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

		getline(infile, line, '-');
		num[21] = stoi(line.c_str());
		getline(infile, line, ' ');
		num[22] = stoi(line.c_str());
		getline(infile, line, '-');
		num[23] = stoi(line.c_str());
		getline(infile, line, ' ');
		num[24] = stoi(line.c_str());
		getline(infile, line, '-');
		num[25] = stoi(line.c_str());
		getline(infile, line);
		num[26] = stoi(line.c_str());
		getline(infile, line);
		num[27] = stoi(line.c_str());
		getline(infile, line);
		num[28] = stoi(line.c_str());
		Earmy->set_need_ally(num[27]);
	
		return true;
	}
	else
	{
		cout << "Error" << endl;
		return false;
	}
}
int Game::get_num_heal_check()
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
			
			U = dynamic_cast<unit*>(S);
			
			this->add_killedlist(U);
		}
	}
	while (tempS.dequeue(S))
	{
		this->addto_UML_ES(S);
	}

	
}

void Game::output_file()
{
	fstream out_file;
	out_file.open("output.txt", ios::out);
	unit* ptr = nullptr;
	int num_killed_ES = 0;
	int num_killed_ET = 0;
	int num_killed_EG = 0;
	int num_killed_HU = 0;
	int num_killed_AS = 0;
	int num_killed_AM = 0;
	int num_killed_AD = 0;
	int num_killed_SU = 0;
	int E_Df = 0;
	int E_Db = 0;
	int E_Dd = 0;
	int A_Df = 0;
	int A_Db = 0;
	int A_Dd = 0;
	int total_GEN_E = this->rand->get_num_GEN_ES() + this->rand->get_num_GEN_ET() + this->rand->get_num_GEN_EG() + this->rand->get_num_GEN_HU();
	int total_GEN_A = this->rand->get_num_GEN_AS() + this->rand->get_num_GEN_AM() + this->rand->get_num_GEN_AD();
	int num_infected = this->Earmy->get_total_num_infected();
	if (out_file.is_open())
	{
		out_file << "		Td	ID	Tj	Df	Dd	Db	\n";
		while (killedlist.dequeue(ptr))
		{
			out_file << "\t\t" << ptr->get_Td() << "\t" << ptr->getID() << "\t" << ptr->get_Tj() << "\t" << ptr->get_Df() << "\t" << ptr->get_Dd() << "\t" << ptr->get_Db() << endl;
			if (ptr->get_type() == "AS")
			{
				num_killed_AS += 1;
				A_Df += ptr->get_Df() ;
			    A_Db += ptr->get_Db();
				A_Dd += ptr->get_Dd();
			}
			else if (ptr->get_type() == "Monster")
			{
				num_killed_AM += 1;
				A_Df += ptr->get_Df();
				A_Db += ptr->get_Db();
				A_Dd += ptr->get_Dd();
			}
			else if (ptr->get_type() == "Drone")
			{
				num_killed_AD += 1;
				A_Df += ptr->get_Df();
				A_Db += ptr->get_Db();
				A_Dd += ptr->get_Dd();
			}
			else if (ptr->get_type() == "ES")
			{
				num_killed_ES += 1;
				E_Df += ptr->get_Df();
				E_Db += ptr->get_Db();
				E_Dd += ptr->get_Dd();
			}
			else if (ptr->get_type() == "Tank")
			{
				num_killed_ET += 1;
				E_Df += ptr->get_Df();
				E_Db += ptr->get_Db();
				E_Dd += ptr->get_Dd();
			}
			else if (ptr->get_type() == "EG")
			{
				num_killed_EG += 1;
				E_Df += ptr->get_Df();
				E_Db += ptr->get_Db();
				E_Dd += ptr->get_Dd();
			}
			else if (ptr->get_type() == "HU")
			{
				num_killed_HU += 1;
				E_Df += ptr->get_Df();
				E_Db += ptr->get_Db();
				E_Dd += ptr->get_Dd();
			}
		}
		int total_DES_E = num_killed_EG + num_killed_ET + num_killed_ES + num_killed_HU;
		int total_DES_A = num_killed_AM + num_killed_AS + num_killed_AD;
		if (!flageE && flageA)
		{
			out_file << "\nWinner Earth Army \n";
			out_file << "===============Earth Army statistics===================== \n";
			out_file << "ES total number : " <<this->rand->get_num_GEN_ES() << " \n";
			out_file << "ET total number : " << this->rand->get_num_GEN_ET() << "\n";
			out_file << "EG total number : " << this->rand->get_num_GEN_EG() << "\n";
			out_file << "ES Destructed/ES total = " <<float(num_killed_ES *100 )/float(this->rand->get_num_GEN_ES()) << "%\n";
			out_file << "ET Destructed/ET total = " << float(num_killed_ET * 100) / float(this->rand->get_num_GEN_ET()) << "%\n";
			out_file << "EG Destructed/EG total = " << float(num_killed_EG * 100) / float(this->rand->get_num_GEN_EG()) << "%\n";
			out_file << "Total Destructed/Total Units = " << float(total_DES_E * 100) / float(total_GEN_E) << "%\n";
			out_file << "Average Df = " << float(E_Df) / float(total_DES_E) << "\n";
			out_file << "Average Dd = " << float(E_Dd) / float(total_DES_E) << "\n";
			out_file << "Average Db = " << float(E_Db) / float(total_DES_E) << "\n";
			out_file << "Df/Db % = " << float(E_Df * 100) / float(E_Db) << "%\n";
			out_file << "Dd/Db % = " << float(E_Dd * 100) / float(E_Db) << "%\n";
			out_file << "Healed units / total units % = " << float(total_num_healed *100) / float(total_GEN_E) << "%\n";
			out_file << "Num infected / total soldier units % = " << float(num_infected) * 100 / float(this->rand->get_num_GEN_ES())<<"%\n";

			out_file << "\nLoser Alien Army \n";
			out_file << "===============Alien Army statistics===================== \n";
			out_file << "AS total number : " << this->rand->get_num_GEN_AS() << " \n";
			out_file << "AM total number : " << this->rand->get_num_GEN_AM() << "\n";
			out_file << "AD total number : " << this->rand->get_num_GEN_AD() << "\n";
			out_file << "AS Destructed/AS total : "<< float(num_killed_AS * 100) / float(this->rand->get_num_GEN_AS()) << "%\n";
			out_file << "AM Destructed/AM total = " << float(num_killed_AM * 100) / float(this->rand->get_num_GEN_AM()) << "%\n";
			out_file << "AD Destructed/AD total = " << float(num_killed_AD * 100) / float(this->rand->get_num_GEN_AD()) << "%\n";
			out_file << "Total Destructed/Total Units = " << float(total_DES_A * 100) / float(total_GEN_A) << "%\n";
			out_file << "Average Df = " << float(A_Df) / float(total_DES_A) << "\n";
			out_file << "Average Dd = " << float(A_Dd) / float(total_DES_A) << "\n";
			out_file << "Average Db = " << float(A_Db) / float(total_DES_A) << "\n";
			out_file << "Df/Db % = " << float(A_Df * 100) / float(A_Db) << "%\n";
			out_file << "Dd/Db % = " << float(A_Dd * 100) / float(A_Db) << "%\n";

		}
		else if (flageE && !flageA)
		{
			out_file << "\nLoser Earth Army \n";
			out_file << "===============Earth Army statistics===================== \n";
			out_file << "ES total number : " << this->rand->get_num_GEN_ES() << " \n";
			out_file << "ET total number : " << this->rand->get_num_GEN_ET() << "\n";
			out_file << "EG total number : " << this->rand->get_num_GEN_EG() << "\n";
			out_file << "ES Destructed/ES total = " << float(num_killed_ES * 100) / float(this->rand->get_num_GEN_ES()) << "%\n";
			out_file << "ET Destructed/ET total = " << float(num_killed_ET * 100) / float(this->rand->get_num_GEN_ET()) << "%\n";
			out_file << "EG Destructed/EG total = " << float(num_killed_EG * 100) / float(this->rand->get_num_GEN_EG()) << "%\n";
			out_file << "Total Destructed/Total Units = " << float(total_DES_E * 100) / float(total_GEN_E) << "%\n";
			out_file << "Average Df = " << float(E_Df) / float(total_DES_E) << "\n";
			out_file << "Average Dd = " << float(E_Dd) / float(total_DES_E) << "\n";
			out_file << "Average Db = " << float(E_Db) / float(total_DES_E) << "\n";
			out_file << "Df/Db % = " << float(E_Df * 100) / float(E_Db) << "%\n";
			out_file << "Dd/Db % = " << float(E_Dd * 100) / float(E_Db) << "%\n";
			out_file << "Healed units / total units % = " << float(total_num_healed * 100) / float(total_GEN_E) << "%\n";
			out_file << "Num infected / total soldier units % = " << float(num_infected) * 100 / float(this->rand->get_num_GEN_ES()) << "%\n";


			out_file << "\nWinner Alien Army \n";
			out_file << "===============Alien Army statistics===================== \n";
			out_file << "AS total number : " << this->rand->get_num_GEN_AS() << " \n";
			out_file << "AM total number : " << this->rand->get_num_GEN_AM() << "\n";
			out_file << "AD total number : " << this->rand->get_num_GEN_AD() << "\n";
			out_file << "AS Destructed/AS total : " << float(num_killed_AS * 100) / float(this->rand->get_num_GEN_AS()) << "%\n";
			out_file << "AM Destructed/AM total = " << float(num_killed_AM * 100) / float(this->rand->get_num_GEN_AM()) << "%\n";
			out_file << "AD Destructed/AD total = " << float(num_killed_AD * 100) / float(this->rand->get_num_GEN_AD()) << "%\n";
			out_file << "Total Destructed/Total Units = " << float(total_DES_A * 100) / float(total_GEN_A) << "%\n";
			out_file << "Average Df = " << float(A_Df) / float(total_DES_A) << "\n";
			out_file << "Average Dd = " << float(A_Dd) / float(total_DES_A) << "\n";
			out_file << "Average Db = " << float(A_Db) / float(total_DES_A) << "\n";
			out_file << "Df/Db % = " << float(A_Df * 100) / float(A_Db) << "%\n";
			out_file << "Dd/Db % = " << float(A_Dd * 100) / float(A_Db) << "%\n";
		}
		else
		{
			out_file << "\nDrawn \n";
			out_file << "===============Earth Army statistics===================== \n";
			out_file << "ES total number : " << this->rand->get_num_GEN_ES() << " \n";
			out_file << "ET total number : " << this->rand->get_num_GEN_ET() << "\n";
			out_file << "EG total number : " << this->rand->get_num_GEN_EG() << "\n";
			out_file << "ES Destructed/ES total = " << float(num_killed_ES * 100) / float(this->rand->get_num_GEN_ES()) << "%\n";
			out_file << "ET Destructed/ET total = " << float(num_killed_ET * 100) / float(this->rand->get_num_GEN_ET()) << "%\n";
			out_file << "EG Destructed/EG total = " << float(num_killed_EG * 100) / float(this->rand->get_num_GEN_EG()) << "%\n";
			out_file << "Total Destructed/Total Units = " << float(total_DES_E * 100) / float(total_GEN_E) << "%\n";
			out_file << "Average Df = " << float(E_Df) / float(total_DES_E) << "\n";
			out_file << "Average Dd = " << float(E_Dd) / float(total_DES_E) << "\n";
			out_file << "Average Db = " << float(E_Db) / float(total_DES_E) << "\n";
			out_file << "Df/Db % = " << float(E_Df * 100) / float(E_Db) << "%\n";
			out_file << "Dd/Db % = " << float(E_Dd * 100) / float(E_Db) << "%\n";
			out_file << "Healed units / total units % = " << float(total_num_healed * 100) / float(total_GEN_E) << "%\n";
			out_file << "Num infected / total soldier units % = " << float(num_infected) * 100 / float(this->rand->get_num_GEN_ES()) << "%\n";


			out_file << "\nDrawn \n";
			out_file << "===============Alien Army statistics===================== \n";
			out_file << "AS total number : " << this->rand->get_num_GEN_AS() << " \n";
			out_file << "AM total number : " << this->rand->get_num_GEN_AM() << "\n";
			out_file << "AD total number : " << this->rand->get_num_GEN_AD() << "\n";
			out_file << "AS Destructed/AS total : " << float(num_killed_AS * 100) / float(this->rand->get_num_GEN_AS()) << "%\n";
			out_file << "AM Destructed/AM total = " << float(num_killed_AM * 100) / float(this->rand->get_num_GEN_AM()) << "%\n";
			out_file << "AD Destructed/AD total = " << float(num_killed_AD * 100) / float(this->rand->get_num_GEN_AD()) << "%\n";
			out_file << "Total Destructed/Total Units = " << float(total_DES_A * 100) / float(total_GEN_A) << "%\n";
			out_file << "Average Df = " << float(A_Df) / float(total_DES_A) << "\n";
			out_file << "Average Dd = " << float(A_Dd) / float(total_DES_A) << "\n";
			out_file << "Average Db = " << float(A_Db) / float(total_DES_A) << "\n";
			out_file << "Df/Db % = " << float(A_Df * 100) / float(A_Db) << "%\n";
			out_file << "Dd/Db % = " << float(A_Dd * 100) / float(A_Db) << "%\n";
		}
	}
	else
		cout << "Error file output is not open";

}
