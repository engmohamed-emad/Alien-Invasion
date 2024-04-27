#include "EG.h"
#include<cmath>
#include"Game.h"
void EG::setAttack_Cap_Drone()
{
	if ((Acapacity / 2) % 2 == 0)
		Attack_Cap_Drone = Acapacity / 2;
	else
		Attack_Cap_Drone = (Acapacity / 2) + 1;	
}
void EG::setAttack_Cap_Monster()
{
	Attack_Cap_Monster = Acapacity - Attack_Cap_Drone;
}
EG::EG()
{
	set_type("EG");
	game = nullptr;
}
EG::EG(int id, int jt, float h, float ap, int c,Game*g)
{
	this->set_type("EG");
	this->setID(id);
	this->set_Tj(jt);
	this->sethealth(h);
	this->setApower(ap);
	this->setAcapacity(c);
	pri = getcurrhealth() + getApower();
	setAttack_Cap_Drone();
	setAttack_Cap_Monster();
	this->game = g;
}
void EG::Modfi_pri()
{
	pri = getcurrhealth() + getApower();
}



int EG::get_pri()
{
	return pri;
}




void EG::dec_health(float damage)
{
	this->currhealth = this->currhealth - damage;
	Modfi_pri();
}

bool EG::attack()
{
	bool flage1 = false;//for monster attack
	bool flage2 = false;//for Drones Attack
	Monster* pt = nullptr;
	Drones* D = nullptr;
	unit* U = nullptr;
	unit* U2 = nullptr;
	LinkedQueue<unit*>templist1;//for monsters
	LinkedQueue<unit*>templist2;//for Drones

	for (int i = 0; i < Attack_Cap_Monster; i++)
	{
		if (game->get_Aarmy()->get_monster(pt, U))
			templist1.enqueue(U);
		else
			break;
	}

	for (int i = 0; i < Attack_Cap_Drone; i++)
	{
		if (game->get_Aarmy()->Get_Drones(D, U))
			templist2.enqueue(U);
		else
			break;
	}


	if (templist1.isEmpty() && templist2.isEmpty())
		return false;

	 if (templist1.isEmpty())
	{
		flage1 = false;
	}
	else if (!templist1.isEmpty())
	{
		while (templist1.dequeue(U))
		{
			
				U->dec_health(this->detect_damage(U->getcurrhealth()));

				if (!(U->get_firstAttack()))
				{
					U->set_Ta(game->get_timestep());
					U->set_firtAttack();
				}

				if (U->getcurrhealth() <= 0)
				{
					U->set_Td(game->get_timestep());
					game->add_killedlist(U);

				}
				else
				{
					pt = dynamic_cast<Monster*>(U);
					if (pt != nullptr)
						game->get_Aarmy()->Add_monster(pt);
					else
						return false;
				}
		}
		flage1 = true;
	}
	

	else if (templist2.isEmpty())
	{
		flage2 = false;
	}

	else if (!templist2.isEmpty())
	{
		while(templist2.dequeue(U))
		{
				if (templist2.dequeue(U2))
				{
					U->dec_health(this->detect_damage(U->getcurrhealth()));
					U2->dec_health(this->detect_damage(U2->getcurrhealth()));

					if (!(U->get_firstAttack()))
					{
						U->set_Ta(game->get_timestep());
						U->set_firtAttack();
					}

					if (!(U2->get_firstAttack()))
					{
						U2->set_Ta(game->get_timestep());
						U2->set_firtAttack();
					}

					if (U->getcurrhealth() <= 0)
					{
						U->set_Td(game->get_timestep());
						game->add_killedlist(U);
					}
					else
					{
						D = dynamic_cast<Drones*>(U);
						if (D != nullptr)
							game->get_Aarmy()->Add_Drones(D);
						else
							return false;
					}
					if (U2->getcurrhealth() <= 0)
					{
						U2->set_Td(game->get_timestep());
						game->add_killedlist(U2);
					}
					else
					{
						D = dynamic_cast<Drones*>(U2);
						if (D != nullptr)
							game->get_Aarmy()->Add_Drones(D);
						else
							return false;
					}
				}
				else
				{
					U->dec_health(this->detect_damage(U->getcurrhealth()));

					if (!(U->get_firstAttack()))
					{
						U->set_Ta(game->get_timestep());
						U->set_firtAttack();
					}

					if (U->getcurrhealth() <= 0)
					{
						U->set_Td(game->get_timestep());
						game->add_killedlist(U);
					}
					else
					{
						D = dynamic_cast<Drones*>(U);
						if (D != nullptr)
							game->get_Aarmy()->Add_Drones(D);
						else
							return false;
					}
				}
				
			
		}
		flage2 = true;
	}
	
	return (flage1 || flage2);
}



