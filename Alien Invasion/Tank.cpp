#include "Tank.h"
#include"unit.h"
#include<iostream>
#include<cmath>
#include"Game.h"
#include"AlianSounit.h"
#include"Monster.h"
#include <string>
#include <chrono>
#include <thread>
using namespace std;
Tank::Tank()
{
	set_type("Tank");
}
Tank::Tank(int id, int jt, float h, float ap, int c,Game* g)
{
	this->set_type("Tank");
	this->setID(id);
	this->set_Tj(jt);
	this->sethealth(h);
	this->setApower(ap);
	this->setAcapacity(c);
	this->game = g;
}

void Tank::dec_health(float damage)
{
	this->currhealth = this->currhealth - damage;
}
bool Tank::help_soldier(int ES,int AS)
{
	if ((float(ES) / float(AS)) < .3)
		return true;
	else return false;
}

void Tank::set_Heal_Time(int t)
{
	this->Heal_Time = t;
}

void Tank::inc_health(float heal)
{
	this->currhealth = this->currhealth + heal;
}

int Tank::get_Heal_Time()
{
	return Heal_Time;
}

bool Tank::attack()
{
	bool flag1 = false;
	bool flag2 = false;
	int cap = Acapacity;
	//comments were added to see the power while iterating
	if (game->is_interactive())
		cout << "ET " << this->getID() <</**" (" << this->getApower() << ") " << */ " shots [";
	if (this->help_soldier(game->get_Earmy()->get_num_sol(), game->get_Aarmy()->get_num_sol()))
	{
		
		AlianSounit* AS = nullptr;
		unit* AS_ptr = nullptr;
		LinkedQueue<AlianSounit*>AS_templist;
		
		for (int i = 0; i < Acapacity / 2; i++)
		{
			if (game->get_Aarmy()->ReturnSo_uint(AS, AS_ptr))
			{
				AS_templist.enqueue(AS);
				flag1 = true;
			}
			else break;
		}
		while (AS_templist.dequeue(AS))
		{
			AS->dec_health(this->detect_damage(AS->getcurrhealth()));
			//comments were added to see the current health while iterating
			if (game->is_interactive())
				cout << AS->getID() /* << " (" << AS->getcurrhealth() << ") " */ << ", ";
			if (!(AS->get_firstAttack()))
			{
				AS->set_Ta(game->get_timestep());
				AS->set_firtAttack();
			}
			if (AS->is_dead())
			{
				AS->set_Td(game->get_timestep());
				
				AS_ptr = dynamic_cast<unit*>(AS);
				
				game->add_killedlist(AS_ptr);
			}
			else
				game->get_Aarmy()->addSo_unit(AS);
		}
		cap = cap - Acapacity / 2;
	}
	Monster* m = nullptr;
	unit* m_ptr = nullptr;

	LinkedQueue < Monster* > m_templist;

	for (int i = 0; i < cap; i++)
	{
		if (game->get_Aarmy()->get_monster(m, m_ptr))
		{
			m_templist.enqueue(m);
			flag2 = true;
		}
		else break;
	}
	while (m_templist.dequeue(m))
	{
		m->dec_health(this->detect_damage(m->getcurrhealth()));
		//comments were added to see the current health while iterating
		if (game->is_interactive())
			cout << m->getID()/* << " (" << m->getcurrhealth() << ") "*/ << ", ";
		if (!(m->get_firstAttack()))
		{
			m->set_Ta(game->get_timestep());
			m->set_firtAttack();
		}
		if (m->is_dead())
		{
			m->set_Td(game->get_timestep());
			 
			m_ptr = dynamic_cast<unit*>(m);
			
			game->add_killedlist(m_ptr);
		}
		else
			game->get_Aarmy()->Add_monster(m);
	}
	if (game->is_interactive())
	{
		if (flag1 || flag2)
			cout << "\b \b" << "\b \b";
		cout << "]\n";
	}
	return (flag1||flag2);
}

