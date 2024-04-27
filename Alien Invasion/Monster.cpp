#include "Monster.h"
#include"unit.h"
#include<iostream>
#include"Game.h"
#include"Solderunit.h"
#include"Tank.h"
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
void Monster::attack()
{
	Solderunit* ES = nullptr;
	Tank* T = nullptr;
	unit* ES_ptr = nullptr;
	unit* T_ptr = nullptr;
	LinkedQueue<Solderunit*>ES_templist;
	LinkedQueue<Tank*>T_templist;
	for (int i = 0; i < Acapacity / 2; i++)
	{
		if (game->get_Earmy()->return_tank(T, T_ptr))
		{
			T_templist.enqueue(T);
		}
		else break;
	}
	while (T_templist.dequeue(T))
	{
		T->dec_health(this->detect_damage(T->getcurrhealth()));
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
				game->addto_UML_TS(T);
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
		}
		else break;
	}
	while (ES_templist.dequeue(ES))
	{
		ES->dec_health(this->detect_damage(ES->getcurrhealth()));
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
				game->addto_UML_ES(ES);
			else
				game->get_Earmy()->addSo_unit(ES);
		}
	}

}

