#include "EG.h"
#include<cmath>
EG::EG()
{
}
EG::EG(int id, int jt, float h, float ap, int c)
{
	this->set_type("EG");
	this->setID(id);
	this->setJtime(jt);
	this->sethealth(h);
	this->setApower(ap);
	this->setAcapacity(c);
	pri = getcurrhealth() + getApower();
}
void EG::Modfi_pri()
{
	pri = getcurrhealth() + getApower();
}

int EG::get_pri()
{
	return pri;
}

float EG::attack(int enhealth)
{
	return (Apower * currhealth / 100) / sqrt(enhealth);
}

void EG::dec_health(float damage)
{
	this->currhealth = this->currhealth - damage;
}
