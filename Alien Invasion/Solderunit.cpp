#include "Solderunit.h"
#include <cmath>
#include "LinkedQueue.h"
#include "AlianSounit.h"
#include "Game.h"
#include <string>
#include <chrono>
#include <thread>

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
	cout << "ES " << this->getID() << " shots [";
	for (int i = 0; i < Acapacity; i++)
	{
		if (game->get_Aarmy()->ReturnSo_uint(Sptr, ptr))
		{
			templist.enqueue(ptr);
			cout << ptr->getID() << ", ";
		}
		else
			break;
	}	
	if (templist.isEmpty())
	{
		//cout << "\b \b" << "\b \b";
		cout << "]\n";
		return false;
	}
	//game->get_Aarmy()->ReturnSo_uint(Sptr, ptr)
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
				game->get_Aarmy()->update_num_killed_sol();
				ptr->set_Td(game->get_timestep());
				game->get_Aarmy()->ubdate_D(ptr);
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
	cout << "\b \b" << "\b \b";
	cout << "]\n";
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
