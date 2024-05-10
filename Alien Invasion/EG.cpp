#include "EG.h"
#include<cmath>
#include"Game.h"
#include <string>
#include <chrono>
#include <thread>
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
	cout << "EG " <<this->getID() << " (" <<this->getApower() << ") " << " shots [";
	for (int i = 0; i < Attack_Cap_Monster; i++)
	{
		if (game->get_Aarmy()->get_monster(pt, U))
		{
			templist1.enqueue(U);
			//cout << U->getID() << ", ";
		}
		else
			break;
	}

	for (int i = 0; i < Attack_Cap_Drone; i++)
	{
		if (game->get_Aarmy()->Get_Drones(D, U))
		{
			templist2.enqueue(U);
			//cout << U->getID() << ", ";
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
				cout << U->getID() <<" ("<<U->getcurrhealth()<<") " << ", ";
				if (!(U->get_firstAttack()))
				{
					U->set_Ta(game->get_timestep());
					U->set_firtAttack();
				}

				if (U->is_dead())
				{
					U->set_Td(game->get_timestep());
					game->get_Aarmy()->update_num_killed_monster();
					game->get_Aarmy()->ubdate_D(U);
					game->add_killedlist(U);

				}
				else
				{
					 
						pt = dynamic_cast<Monster*>(U);
						if (pt != nullptr)
							game->get_Aarmy()->Add_monster(pt);
						else
						{
							cout << "\b \b" << "\b \b";
							cout << "]\n";
							return false;
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
		while(templist2.dequeue(U))
		{
				if (templist2.dequeue(U2))
				{
					U->dec_health(this->detect_damage(U->getcurrhealth()));
					cout << U->getID() << " (" << U->getcurrhealth() << ") " << ", ";
					U2->dec_health(this->detect_damage(U2->getcurrhealth()));
					cout << U2->getID() << " (" << U2->getcurrhealth() << ") " << ", ";
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

					if (U->is_dead())
					{
						U->set_Td(game->get_timestep());
						game->get_Aarmy()->update_num_killed_drones();
						game->get_Aarmy()->ubdate_D(U);
						game->add_killedlist(U);

					}
					else
					{
						D = dynamic_cast<Drones*>(U);
						if (D != nullptr)
							game->get_Aarmy()->Add_Drones(D);
						else
						{
							cout << "\b \b" << "\b \b";
							cout << "]\n";
							return false;
						}
					}
					if (U2->is_dead())
					{
						U2->set_Td(game->get_timestep());
						game->get_Aarmy()->update_num_killed_drones();
						game->get_Aarmy()->ubdate_D(U2);
						game->add_killedlist(U2);
					}
					else
					{
						D = dynamic_cast<Drones*>(U2);
						if (D != nullptr)
							game->get_Aarmy()->Add_Drones(D);
						else
						{
							cout << "\b \b" << "\b \b";
							cout << "]\n";
							return false;
						}
					}
				}
				else
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
						U->set_Td(game->get_timestep());
						game->get_Aarmy()->update_num_killed_drones();
						game->get_Aarmy()->ubdate_D(U);
						game->add_killedlist(U);
					}
					else
					{
						D = dynamic_cast<Drones*>(U);
						if (D != nullptr)
							game->get_Aarmy()->Add_Drones(D);
						else
						{
							cout << "\b \b" << "\b \b";
							cout << "]\n";
							return false;
						}
					}
				}
				
			
		}
		flage2 = true;
	}
	cout << "\b \b" << "\b \b";
	cout << "]\n";
	return (flage1 || flage2);
}



