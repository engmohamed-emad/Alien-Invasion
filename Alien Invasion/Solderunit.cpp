#include "Solderunit.h"
#include <cmath>
#include "LinkedQueue.h"
#include "AlianSounit.h"
#include "Game.h"


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



void Solderunit::inc_health(float heal)
{
	this->currhealth = this->currhealth + heal;
}

bool Solderunit::attack()
{
	AlianSounit* Sptr = nullptr;//it is damy pointer to use the function that take two prametars
	unit* ptr = nullptr;
	LinkedQueue<unit*> templist;
	for (int i = 0; i < Acapacity; i++)
	{
		if (game->get_Aarmy()->ReturnSo_uint(Sptr, ptr))
		{
			templist.enqueue(ptr);
		}
	}	
	if (templist.isEmpty())
	{
		return false;
	}
	//game->get_Aarmy()->ReturnSo_uint(Sptr, ptr)
	for (int i = 0; i < Acapacity; i++)
	{
		if (templist.dequeue(ptr))
		{
			ptr->dec_health(this->detect_damage(ptr->getcurrhealth()));
			if (ptr->is_dead())
			{
				game->add_killedlist(ptr);
			}
			else
			{
				Sptr = dynamic_cast<AlianSounit*>(ptr);
				game->get_Aarmy()->addSo_unit(Sptr);
			}
		}
	}
	return true;
}
