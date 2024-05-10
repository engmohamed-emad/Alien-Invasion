#include "Drones.h"
#include"Game.h"
#include"LinkedQueue.h"
#include <string>
#include <chrono>
#include <thread>
void Drones::Set_Cap_Tank()
{
	Attack_Cap_Tank = Acapacity / 2;
}

void Drones::Set_Cap_Gun()
{
	Attack_Cap_Gun = Acapacity - Attack_Cap_Tank;
}

Drones::Drones()
{
	set_type("Drone");
	game = nullptr;
}
Drones::Drones(int id, int jt, float h, float ap, int c,Game*g)
{
	this->set_type("Drone");
	this->setID(id);
	this->set_Tj(jt);
	this->sethealth(h);
	this->setApower(ap);
	this->setAcapacity(c);
	this->game = g;
		 Set_Cap_Tank();
		 Set_Cap_Gun();	
}



void Drones::dec_health(float damage)
{
	this->currhealth = this->currhealth - damage;
}

bool Drones::attack()
{
	bool flage1 = false;
	bool flage2 = false;
	int pri = 0;
	EG* Gun = nullptr;
	Tank* T = nullptr;
	unit* U = nullptr;
	LinkedQueue<unit*>templist1;
	LinkedQueue<unit*>templist2;
	cout << "AD " << this->getID()<<" ("<<this->getApower()<<") " << " shots [";
	for (int i = 0; i < Attack_Cap_Tank; i++)
	{
		if (game->get_Earmy()->return_tank(T, U))
		{
			templist1.enqueue(T);
			//cout << T->getID() << ", ";
		}
		else
			break;
	}

	for (int i = 0; i < Attack_Cap_Gun; i++)
	{
		if (game->get_Earmy()->Return_Gun(Gun, pri, U))
		{
			templist2.enqueue(Gun);
			//cout << Gun->getID() << ", ";
		}
		else
			break;
	}

	if (templist1.isEmpty() && templist2.isEmpty())
	{
		//cout << "\b \b" << "\b \b";
		cout << "]\n";
		return false;
	}
	if (templist1.isEmpty())
	{
		flage1 = false;
	}

	 if (!templist1.isEmpty())
	 {
		while (templist1.dequeue(U))
		{

			
			U->dec_health(this->detect_damage(U->getcurrhealth()));
			cout << U->getID() << " (" << U->getcurrhealth() << ") " << ", ";
			if (!(U->get_firstAttack()))
			{
				U->set_Ta(game->get_timestep());
				U->set_firtAttack();
			}
			if (U->is_dead())
			{
				game->get_Earmy()->update_num_killed_tank();
				U->set_Td(game->get_timestep());
				game->get_Earmy()->ubdate_D(U);
				game->add_killedlist(U);
			}
			else if (U->need_help())
			{
				T = dynamic_cast<Tank*>(U);
				T->set_Heal_Time(game->get_timestep());
				game->addto_UML_ET(T);
			}
			else
			

			{
				T = dynamic_cast<Tank*>(U);
				if (T != nullptr)
					game->get_Earmy()->Add_tank(T);
				else
				{
					cout << "\b \b" << "\b \b";
					cout << "]\n";
					return false;//this may lead to a logical error       ?? ?? ????? ???? 
				}
			}
		}
		flage1 = true;
	 }

	 if (templist2.isEmpty())
	{
		flage2 = false;
	}
	 if (!templist2.isEmpty())
	{
		while (templist2.dequeue(U))
		{
			U->dec_health(this->detect_damage(U->getcurrhealth()));
			cout << U->getID() << " (" << U->getcurrhealth() << ") " << ", ";
			if (!(U->get_firstAttack()))
			{
				U->set_Ta(game->get_timestep());
				U->set_firtAttack();
			}
			if (U->is_dead())
			{
				game->get_Earmy()->update_num_killed_EG();
				U->set_Td(game->get_timestep());
				game->get_Earmy()->ubdate_D(U);
				game->add_killedlist(U);
			}
			else

			{
				Gun = dynamic_cast<EG*>(U);
				if (Gun != nullptr)
				{
					Gun->Modfi_pri();
					game->get_Earmy()->Add_Earth_Gun(Gun);
				}
				else
				{
					cout << "\b \b" << "\b \b";
					cout << "]\n";
					return false;
				}
			}
		}
		flage2 = true;
	}
	cout << "\b \b" << "\b \b";
	cout << "]\n";
	return (flage1 || flage2);
}






