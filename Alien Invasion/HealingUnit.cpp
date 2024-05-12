#include "HealingUnit.h"
#include "LinkedQueue.h"
#include"Game.h"
#include <string>
#include <chrono>
#include <thread>
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
	if (game->is_interactive())
		cout << "========================== Healing operation ==========================\n";
	bool flag = false;
	if (game->is_interactive())
		cout << "HU " << this->getID() << " healing [";
	int c = 0;
	int T = 0;
	LinkedQueue<Solderunit*>temp_Sol;
	LinkedQueue<Tank*>temp_tank;
	Solderunit* Sptr = nullptr;
	unit* ptr;
	Tank* Tptr = nullptr;
	for (int i = 0; i < Acapacity; i++)
	{
		if (game->get_UML_ES(Sptr))//it may result in exiption handling
		{
			if (game->get_timestep() - Sptr->get_Heal_Time() < 10)
			{
				c++;
				temp_Sol.enqueue(Sptr);
				flag = true;
			}
			else
			{
				ptr = dynamic_cast<unit*>(Sptr);
				if (ptr != nullptr)
				{
					ptr->set_Td(game->get_timestep());
					
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
				flag = true;
				T++;
			}
			else
			{
				ptr = dynamic_cast<unit*>(Tptr);
				if (ptr != nullptr)
				{
					
					ptr->set_Td(game->get_timestep());
					
					game->add_killedlist(ptr);
				}
				i--;
			}
		}
		else break;
	}
	while (c > 0&&temp_Sol.dequeue(Sptr))
	{
		if (Sptr->get_state() == 0)
		{                 
			Sptr->inc_health((detect_damage(Sptr->getcurrhealth()))/2.0);
		}

		Sptr->inc_health(detect_damage(Sptr->getcurrhealth()));
		if (game->is_interactive())
			cout << Sptr->getID() << " (" << Sptr->getcurrhealth() << ") " << ", ";
		if (Sptr->need_help())
		{
			if (Sptr->get_state() == 0)
			{
				Sptr->set_second_heal();
				temp_Sol.enqueue(Sptr);
			}
			else
				temp_Sol.enqueue(Sptr);
		}
		else
		{
			if (Sptr->get_state() == 0)
			{
				if (!(Sptr->get_second_heal()))
				{
					Sptr->set_second_heal();
					temp_Sol.enqueue(Sptr);
				}
				else
				{
					Sptr->set_state(1);
					game->get_Earmy()->addSo_unit(Sptr);
					num_healed++;
					game->get_Earmy()->decrement_infected();
					
				}
			}
			    
			else
			{
				game->get_Earmy()->addSo_unit(Sptr);
				num_healed++;
			}
		}
		c--;
	}
	while (temp_Sol.dequeue(Sptr))
	{
		game->addto_UML_ES(Sptr);
	}
	while (T > 0 && temp_tank.dequeue(Tptr))
	{   
		Tptr->inc_health(detect_damage(Tptr->getcurrhealth()));
		if (game->is_interactive())
			cout << Tptr->getID() << " (" << Tptr->getcurrhealth() << ") " << ", ";
		if (Tptr->need_help())
		{
			temp_tank.enqueue(Tptr);
		}
		else
		{
			game->get_Earmy()->Add_tank(Tptr); 
			num_healed++;
		}
		T--;
	}
	while (temp_tank.dequeue(Tptr))
	{
		game->addto_UML_ET(Tptr);
	}
	if (game->is_interactive())
	{
		if (flag)
			cout << "\b \b" << "\b \b";
		cout << "]\n\n";
	}
	
}

int HealingUnit::get_num_healed()
{
	return num_healed;
}
