#include "AlianSounit.h"
#include "Game.h"
#include "Solderunit.h"

AlianSounit::AlianSounit()
{
	set_type("AS");
	game = nullptr;
	
}
AlianSounit::AlianSounit(int id, int jt, float h, float ap, int c, Game* g)
{
	this->set_type("AS");
	this->setID(id);
	this->set_Tj(jt);
	this->sethealth(h);
	this->setApower(ap);
	this->setAcapacity(c);
	this->game = g;

}

void AlianSounit::dec_health(float damage)
{
	this->currhealth = this->currhealth - damage;
}

bool AlianSounit::attack()
{
	Solderunit* Sptr = nullptr;//it is damy pointer to use the function that take two prametars
	unit* ptr = nullptr;
	LinkedQueue<unit*> templist;
	for (int i = 0; i < Acapacity; i++)
	{     
		if (game->get_Earmy()->ReturnSo_uint(Sptr, ptr))
		{
			templist.enqueue(ptr);
		}
	}
	if (templist.isEmpty())
	{
		return false;
	}

	for (int i = 0; i < Acapacity; i++)
	{
		if (templist.dequeue(ptr))
		{
			ptr->dec_health(this->detect_damage(ptr->getcurrhealth()));
			if (!(ptr->get_firstAttack()))
			{
				ptr->set_Ta(game->get_timestep());
				ptr->set_firtAttack();
			}
			if (ptr->is_dead())
			{
				game->add_killedlist(ptr);
			}
			else if (ptr->need_help())
			{
				Sptr = dynamic_cast<Solderunit*>(ptr);
				if(Sptr!=nullptr)
				{
					Sptr->set_numstep(0);
					game->addto_UML_ES(Sptr);

				}
				// you need to set time 
				//you need to handel 10 time step
			}
			else
			{
				Sptr = dynamic_cast<Solderunit*>(ptr);
				game->get_Earmy()->addSo_unit(Sptr);
			}
		}
	}
	return true;
}








