#include "HealingUnit.h"
#include "LinkedQueue.h"
#include"Game.h"
HealingUnit::HealingUnit()
{
	this->set_type("HU");
	game = nullptr;
}

HealingUnit::HealingUnit(int id, int jt, float h, float ap, int c,Game*g)
{
	this->set_type("HU");
	this->setID(id);
	this->set_Tj(jt);
	this->sethealth(h);
	this->setApower(ap);
	this->setAcapacity(c);
	this->game = g;
}

void HealingUnit::dec_health(float damage)
{
	currhealth = -1;
}

void HealingUnit::attack()
{
	int c = 0;
	int T = 0;
	LinkedQueue<Solderunit*>temp_Sol;
	LinkedQueue<Tank*>temp_tank;
	Solderunit* Sptr = nullptr;
	unit* ptr;
	Tank* Tptr = nullptr;
	for (int i = 0; i < Acapacity; i++)
	{
		if (game->get_UML_ES(Sptr))
		{
			if (game->get_timestep() - Sptr->get_Heal_Time() < 10)
			{
				c++;
				temp_Sol.enqueue(Sptr);
			}
			else
			{
				ptr = dynamic_cast<unit*>(Sptr);
				if (ptr != nullptr)
				{
					game->add_killedlist(ptr);
				}
				i--;
			}
		}
		else break;

	}
	for (int i = 0; i < Acapacity - c; i++)
	{
		if (game->get_UML_ET(Tptr))
		{
			if (game->get_timestep() - Tptr->get_Heal_Time() < 10)
			{
				temp_tank.enqueue(Tptr);
				T++;
			}
			else
			{
				ptr = dynamic_cast<unit*>(Tptr);
				if (ptr != nullptr)
				{
					game->add_killedlist(ptr);
				}
				i--;
			}
		}
		else break;
	}
	while (temp_Sol.dequeue(Sptr)&&c>0)
	{
		Sptr->inc_health(detect_damage(Sptr->getcurrhealth()));
		if (Sptr->need_help())
		{
			temp_Sol.enqueue(Sptr);
		}
		else
		{
			game->get_Earmy()->addSo_unit(Sptr);
		}
		c--;
	}
	while (temp_Sol.dequeue(Sptr))
	{
		game->addto_UML_ES(Sptr);
	}
	while (temp_tank.dequeue(Tptr)&&T>0)
	{
		Tptr->inc_health(detect_damage(Tptr->getcurrhealth()));
		if (Tptr->need_help())
		{
			temp_tank.enqueue(Tptr);
		}
		else
		{
			game->get_Earmy()->Add_tank(Tptr);
		}
		T--;

	}
	while (temp_tank.dequeue(Tptr))
	{
		game->addto_UML_ET(Tptr);
	}
	
}
