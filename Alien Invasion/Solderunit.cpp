#include "Solderunit.h"
#include <cmath>
#include "LinkedQueue.h"
#include "AlianSounit.h"
#include "Game.h"
#include <string>
#include <chrono>
#include <thread>
#include <iostream>
#define RESET   "\033[0m"
#define RED     "\033[31m"  
using namespace std;

Solderunit::Solderunit()
{
	set_type("ES");
	game = nullptr;
}

Solderunit::Solderunit(int id, int jt, float h, float ap, int c, Game* g)
{
	this->set_type("ES");
	this->setID(id);
	this->set_Tj(jt);
	this->sethealth(h);
	this->setApower(ap);
	this->setAcapacity(c);
	this->game = g;
}

void Solderunit::dec_health(float damage)
{
	this->currhealth = this->currhealth - damage;
}

void Solderunit::set_state(int x)
{
	state_solider = x;
}

int Solderunit::get_state()
{
	return state_solider;
}




void Solderunit::inc_health(float heal)
{
	this->currhealth = this->currhealth + heal;
}

bool Solderunit::attack()
{
	AlianSounit* Sptr = nullptr;//it is damy pointer to use the function that take two prametars
	unit* ptr = nullptr;
	LinkedQueue<unit*> templist;
	if (game->is_interactive())
		cout << "ES " << this->getID() << " (" << this->getApower() << ") " << " shots [";
	for (int i = 0; i < Acapacity; i++)
	{
		if (game->get_Aarmy()->ReturnSo_uint(Sptr, ptr))
		{
			templist.enqueue(ptr);
		//	cout << ptr->getID() << ", ";
		}
		else
			break;
	}	
	if (templist.isEmpty())
	{
		//cout << "\b \b" << "\b \b";
		if (game->is_interactive())
			cout << "]\n";
		return false;
	}
	//game->get_Aarmy()->ReturnSo_uint(Sptr, ptr)
	for (int i = 0; i < Acapacity; i++)
	{
		if (templist.dequeue(ptr))
		{
			ptr->dec_health(this->detect_damage(ptr->getcurrhealth()));
			if (game->is_interactive())
				cout << ptr->getID() << " (" << ptr->getcurrhealth() << ") " << ", ";
			if (!(ptr->get_firstAttack()))
			{
				ptr->set_Ta(game->get_timestep());
				ptr->set_firtAttack();
			}

			if (ptr->is_dead())
			{
				
				ptr->set_Td(game->get_timestep());
				
				game->add_killedlist(ptr);
			}
			else
			{
				Sptr = dynamic_cast<AlianSounit*>(ptr);
				if (Sptr != nullptr)
				{
					game->get_Aarmy()->addSo_unit(Sptr);
				}

			}
		}
	}
	if (game->is_interactive())
	{
		cout << "\b \b" << "\b \b";
		cout << "]\n";
	}
	return true;
}

bool Solderunit::attack_infected()
{
	Solderunit* Sptr = nullptr;//it is damy pointer to use the function that take two prametars
	unit* ptr = nullptr;
	LinkedQueue<unit*> templist;
	int c = game->get_Earmy()->get_num_sol();
	if (game->is_interactive())
	{		
		cout <<RED<< "ES inf " << this->getID() << " (" << this->getApower() << ") " << " shots "<<RESET<<"[";
	}
	for (int i = 0; (i < Acapacity && c>0); i++)
	{
		if (game->get_Earmy()->ReturnSo_uint(Sptr, ptr))
		{
			if (Sptr->get_state() != 0)
			{
				templist.enqueue(ptr);
				c--;
			}
			else
			{
				game->get_Earmy()->addSo_unit(Sptr);
				i--;
				c--;
			}
			//	cout << ptr->getID() << ", ";
		}
		else
			break;
	}
	if (templist.isEmpty())
	{
		//cout << "\b \b" << "\b \b";
		if (game->is_interactive())
			cout << "]\n";
		return false;
	}
	//game->get_Aarmy()->ReturnSo_uint(Sptr, ptr)
	for (int i = 0; i < Acapacity; i++)
	{
		if (templist.dequeue(ptr))
		{
			ptr->dec_health(this->detect_damage(ptr->getcurrhealth()));
			if (game->is_interactive())
				cout << ptr->getID() << " (" << ptr->getcurrhealth() << ") " << ", ";
			if (!(ptr->get_firstAttack()))
			{
				ptr->set_Ta(game->get_timestep());
				ptr->set_firtAttack();
			}

			if (ptr->is_dead())
			{
				
				ptr->set_Td(game->get_timestep());
				
				game->add_killedlist(ptr);
			}
			else if (ptr->need_help())
			{
				Sptr = dynamic_cast<Solderunit*>(ptr);
				if (Sptr != nullptr)
				{
					Sptr->set_Heal_Time(game->get_timestep());
					game->addto_UML_ES(Sptr);

				}
			}
			else
			{
				Sptr = dynamic_cast<Solderunit*>(ptr);
				if (Sptr != nullptr)
				{
					game->get_Earmy()->addSo_unit(Sptr);
				}

			}
		}
	}
	if (game->is_interactive())
	{
		cout << "\b \b" << "\b \b";
		cout << "]\n";
	}
	return true;
}


void Solderunit::set_Heal_Time(int t)
{
	Heal_Time = t;
}

int Solderunit::get_Heal_Time()
{
	return Heal_Time;
}

void Solderunit::set_second_heal()
{
	second_heal = true;
}

bool Solderunit::get_second_heal()
{
	return second_heal;
}


