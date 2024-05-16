#include "Monster.h"
#include"unit.h"
#include<iostream>
#include"Game.h"
#include"Solderunit.h"
#include"Tank.h"
#include <string>
#include <chrono>
#include <thread>
#define RESET   "\033[0m"
#define RED     "\033[31m"
using namespace std;
Monster::Monster()
{
	set_type("Monster");
}
Monster::Monster(int id, int jt, float h, float ap, int c,Game* g)
{
	this->set_type("Monster");
	this->setID(id);
	this->set_Tj(jt);
	this->sethealth(h);
	this->setApower(ap);
	this->setAcapacity(c);
	this->game = g;
}

void Monster::dec_health(float damage)
{
	this->currhealth = this->currhealth - damage;
}
bool Monster::attack()
{
	mode_inf =game->get_RandGen()->get_flag_inf();
	int counter_SU=0;
	bool flag1 = false;
	bool flag2 = false;
	bool flag3 = false;
	Solderunit* ES = nullptr;
	Tank* T = nullptr;
	unit* ES_ptr = nullptr;
	unit* T_ptr = nullptr;
	SU* S_U = nullptr;
	unit* SU_ptr = nullptr;
	LinkedQueue<Solderunit*>ES_templist;
	LinkedQueue<Tank*>T_templist;
	LinkedQueue<SU*>SU_templist;
	if (game->is_interactive())
	{
		if (mode_inf)
		{
			cout << "AM " << this->getID()/* << " (" << this->getApower() << ") " */<< " infects & shots [";
		}
		else
			cout << "AM " << this->getID() /* << " (" << this->getApower() << ") " */<< " shots [";
	}
	for (int i = 0; i < Acapacity / 2; i++)
	{
		if (game->get_Earmy()->return_tank(T, T_ptr))
		{
			T_templist.enqueue(T);
			flag1 = true;
		}
		else
		{
			counter_SU += (Acapacity / 2 - i);
			break;
		}
	}

	while (T_templist.dequeue(T))
	{
		T->dec_health(this->detect_damage(T->getcurrhealth()));
		if (game->is_interactive())
			cout << T->getID() /* << " (" << T->getcurrhealth() << ") "*/ << ", ";
		if (!(T->get_firstAttack()))
		{
			T->set_Ta(game->get_timestep());
			T->set_firtAttack();
		}
		if (T->is_dead())
		{
			
			T->set_Td(game->get_timestep());
			T_ptr = dynamic_cast<unit*>(T);
			
			game->add_killedlist(T_ptr);
		}
		else
		{
			if (T->need_help())
			{
				T->set_Heal_Time(game->get_timestep());
				game->addto_UML_ET(T);
			}
			else
				game->get_Earmy()->Add_tank(T);
		}
	}
	int cap = Acapacity - Acapacity / 2;
	for (int i = 0; i < cap; i++)
	{
		if (game->get_Earmy()->ReturnSo_uint(ES, ES_ptr))
		{
			
				ES_templist.enqueue(ES);
				flag2 = true;
		}
		else
		{
			counter_SU += (cap - i);
			break;
		}
	}
	while (ES_templist.dequeue(ES))
	{
		if (mode_inf)
		{
			if (ES->get_state() == -1)
			{
				ES->set_state(0);
				game->get_Earmy()->increment_infected();
				if (game->is_interactive())
				{
						cout << RED << "inf " << ES->getID() << /*" (" << ES->getcurrhealth() << ") " <<*/ RESET << ", ";
				}
			}
		}
		else
		{
			ES->dec_health(this->detect_damage(ES->getcurrhealth()));
			if (game->is_interactive())
			{
				if (ES->get_state() == 0)
					cout << RED << "inf " << ES->getID() /* << " (" << ES->getcurrhealth() << ") "*/ << RESET << ", ";
				else cout << ES->getID() /* << " (" << ES->getcurrhealth() << ") "*/ << ", ";
			}
		}

		if (!(ES->get_firstAttack()))
		{
			ES->set_Ta(game->get_timestep());
			ES->set_firtAttack();
		}
		if (ES->is_dead())
		{
			if (ES->get_state() == 0)
			{
				game->get_Earmy()->decrement_infected();
			}
			ES->set_Td(game->get_timestep());
			ES_ptr = dynamic_cast<unit*>(ES);
			
			game->add_killedlist(ES_ptr);
		}
		else
		{
			if (ES->need_help())
			{
				ES->set_Heal_Time(game->get_timestep());
				game->addto_UML_ES(ES);
			}
			else
				game->get_Earmy()->addSo_unit(ES);
		}
	}
	for (int i = 0; i < counter_SU; i++)
	{
		if (game->get_ally()->ReturnSU_uint(S_U, SU_ptr))
		{
			SU_templist.enqueue(S_U);
			flag3 = true;
		}
		else
		{
			break;
		}
	}
	while (SU_templist.dequeue(S_U))
	{
		S_U->dec_health(this->detect_damage(S_U->getcurrhealth()));
		if (game->is_interactive())
			cout << S_U->getID()/* << " (" << S_U->getcurrhealth() << ") "*/ << ", ";
		if (!(S_U->get_firstAttack()))
		{
			S_U->set_Ta(game->get_timestep());
			S_U->set_firtAttack();
		}
		if (S_U->is_dead())
		{
			S_U->set_Td(game->get_timestep());
			SU_ptr = dynamic_cast<unit*>(S_U);
			if(SU_ptr)
			game->add_killedlist(SU_ptr);
		}
		else
		{   
			game->get_ally()->addSU_unit(S_U);
		}
	}
	if (game->is_interactive())
	{
		if (flag1 || flag2 || flag3)
			cout << "\b \b" << "\b \b";
		cout << "]\n";
	}

	return (flag1 || flag2);
}

void Monster::set_mode_inf(bool f)
{
	mode_inf = f;
}

bool Monster::get_mode_inf()
{
	return mode_inf;
}

