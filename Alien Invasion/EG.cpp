#include "EG.h"
#include<cmath>
void EG::setAttack_Cap_Drone()
{
	Attack_Cap_Drone = ceil(Acapacity / 2.0);
	if (Attack_Cap_Drone % 2 != 0)
		Attack_Cap_Drone = floor(Acapacity / 2.0);
}
void EG::setAttack_Cap_Monster()
{
	Attack_Cap_Monster = Acapacity - Attack_Cap_Drone;
}
EG::EG()
{
	set_type("EG");
}
EG::EG(int id, int jt, float h, float ap, int c)
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
}
void EG::Modfi_pri()
{
	pri = getcurrhealth() + getApower();
}



int EG::get_pri()
{
	return pri;
}

int EG::Get_Cap_Drone()
{
	return Attack_Cap_Drone;
}

int EG::Get_Cap_Monster()
{
	return Attack_Cap_Monster;
}

float EG::attack(int enhealth)
{
	return (Apower * currhealth / 100) / sqrt(enhealth);
}

void EG::dec_health(float damage)
{
	this->currhealth = this->currhealth - damage;
}



