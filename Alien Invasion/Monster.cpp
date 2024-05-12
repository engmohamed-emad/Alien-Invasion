#include "Monster.h"
#include"unit.h"
#include<iostream>
#include"Game.h"
#include"Solderunit.h"
#include"Tank.h"
#include <string>
#include <chrono>
#include <thread>
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
	bool flag1 = false;
	bool flag2 = false;
	Solderunit* ES = nullptr;
	Tank* T = nullptr;
	unit* ES_ptr = nullptr;
	unit* T_ptr = nullptr;
	LinkedQueue<Solderunit*>ES_templist;
	LinkedQueue<Tank*>T_templist;
	if (game->is_interactive())
		cout << "AM " << this->getID() << " (" << this->getApower() << ") " << " shots [";
	for (int i = 0; i < Acapacity / 2; i++)
	{
		if (game->get_Earmy()->return_tank(T, T_ptr))
		{
			T_templist.enqueue(T);
			//cout << T->getID() << ", ";
			flag1 = true;
		}
		else break;
	}

	while (T_templist.dequeue(T))
	{
		T->dec_health(this->detect_damage(T->getcurrhealth()));
		if (game->is_interactive())
			cout << T->getID() << " (" << T->getcurrhealth() << ") " << ", ";
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
			//cout << ES->getID() << ", ";
			flag2 = true;
		}
		else break;
	}
	while (ES_templist.dequeue(ES))
	{
		ES->dec_health(this->detect_damage(ES->getcurrhealth()));
		if (game->is_interactive())
			cout << ES->getID() << " (" << ES->getcurrhealth() << ") " << ", ";
		/// you have to add something loaded from file to know if solider will get infected or not if he will infected you have to make its state_solider(variable in ES unit) equal 0  and you have to call function increment infected in earth army and return it to list if he didnt die after attack  if state_solider equal 1 then it is immuned cant infected
		if (!(ES->get_firstAttack()))
		{
			ES->set_Ta(game->get_timestep());
			ES->set_firtAttack();
		}
		if (ES->is_dead())
		{
			
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
	if (game->is_interactive())
	{
		if (flag1 || flag2)
			cout << "\b \b" << "\b \b";
		cout << "]\n";
	}
	return (flag1 || flag2);
}

