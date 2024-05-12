#include "SU.h"
#include <cmath>
#include "LinkedQueue.h"
#include "AlianSounit.h"
#include "Game.h"
#include <string>
#include <chrono>
#include <thread>

SU::SU()
{
	set_type("SU");
	game = nullptr;
}

SU::SU(int id, int jt, float h, float ap, int c, Game* g)
{
	this->set_type("SU");
	this->setID(id);
	this->set_Tj(jt);
	this->sethealth(h);
	this->setApower(ap);
	this->setAcapacity(c);
	this->game = g;
}

void SU::dec_health(float damage)
{
	this->currhealth = this->currhealth - damage;
}

bool SU::attack()
{
	AlianSounit* Sptr = nullptr;//it is damy pointer to use the function that take two prametars
	unit* ptr = nullptr;
	LinkedQueue<unit*> templist;
	if (game->is_interactive())
		cout << "SU " << this->getID() << " (" << this->getApower() << ") " << " shots [";
	for (int i = 0; i < Acapacity; i++)
	{
		if (game->get_Aarmy()->ReturnSo_uint(Sptr, ptr))
		{
			templist.enqueue(ptr);
		}
		else
			break;
	}
	if (templist.isEmpty())
	{
		if (game->is_interactive())
			cout << "]\n";
		return false;
	}
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
	if(game->is_interactive())
	{
		cout << "\b \b" << "\b \b";
		cout << "]\n";
	}
	return true;
}
