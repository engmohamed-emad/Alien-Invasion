#include "AlianSounit.h"
#include "Game.h"
#include "Solderunit.h"
#include <string>
#include <chrono>
#include <thread>
#include <iostream>
#define RESET   "\033[0m"
#define RED     "\033[31m"
using namespace std;
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
	int c = 0;
	Solderunit* Sptr = nullptr;//it is damy pointer to use the function that take two prametars
	unit* ptr = nullptr;
	SU* SUptr;
	LinkedQueue<unit*> templist;
	LinkedQueue<unit*> S_U;
	if (game->is_interactive())
		cout << "AS " << this->getID() << " (" << this->getApower() << ") " << " shots [";
	for (int i = 0; i < Acapacity  ; i++)
	{     
		if (game->get_Earmy()->ReturnSo_uint(Sptr, ptr))
		{
			templist.enqueue(ptr);
			c++;
		}
		else
			break;
	}
	for (int i = 0; i < Acapacity-c; i++)
	{
		if (game->get_ally()->ReturnSU_uint(SUptr, ptr))
		{
			S_U.enqueue(ptr);
		}
		else
			break;
	}
	if (templist.isEmpty()&&S_U.isEmpty())
	{
		
		if (game->is_interactive())
			cout << "]\n";
		return false;
	}
	
	
		while(templist.dequeue(ptr))
		{
			ptr->dec_health(this->detect_damage(ptr->getcurrhealth()));
			
			if (game->is_interactive())
			{
				Sptr = dynamic_cast<Solderunit*>(ptr);
				if (Sptr->get_state() == 0)
					cout << RED << "inf " << ptr->getID() << " (" << ptr->getcurrhealth() << ") " << RESET << ", ";
				else
					cout << ptr->getID() << " (" << ptr->getcurrhealth() << ") " << ", ";
			}
			if (!(ptr->get_firstAttack()))
			{
				ptr->set_Ta(game->get_timestep());
				ptr->set_firtAttack();
			}
			if (ptr->is_dead())
			{
				Sptr = dynamic_cast<Solderunit*>(ptr);
				if (Sptr->get_state() == 0)
				{
					game->get_Earmy()->decrement_infected();
				}
				ptr->set_Td(game->get_timestep());
				game->add_killedlist(ptr);
			}
			else if (ptr->need_help())
			{
				Sptr = dynamic_cast<Solderunit*>(ptr);
				if(Sptr!=nullptr)
				{
					Sptr->set_Heal_Time(game->get_timestep());
					game->addto_UML_ES(Sptr);

				}
				// you need to set time 
				//you need to handel 10 time step
			}
			else
			{
				Sptr = dynamic_cast<Solderunit*>(ptr);
				if(Sptr!=nullptr)
				game->get_Earmy()->addSo_unit(Sptr);
			}
		}
		while (S_U.dequeue(ptr))
		{
			ptr->dec_health(this->detect_damage(ptr->getcurrhealth()));
			if (game->is_interactive())
			{
				cout << ptr->getID() << " (" << ptr->getcurrhealth() << ") " << ", ";
			}
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
				SUptr = dynamic_cast<SU*>(ptr);
				if (SUptr != nullptr)
					game->get_ally()->addSU_unit(SUptr);
			}
		}

	if (game->is_interactive())
	{
		cout << "\b \b" << "\b \b";
		cout << "]\n";
	}
	return true;
}








