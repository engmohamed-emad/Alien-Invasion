#include "Solderunit.h"
#include <cmath>

Solderunit::Solderunit()
{
}

Solderunit::Solderunit(int id, int jt, float h, float ap, int c)
{
	this->set_type("ES");
	this->setID(id);
	this->setJtime(jt);
	this->sethealth(h);
	this->setApower(ap);
	this->setAcapacity(c);
}

void Solderunit::dec_health(float damage)
{
	this->currhealth = this->currhealth - damage;
}

float Solderunit::attack(int enhealth)
{
	return (Apower * currhealth / 100) / sqrt(enhealth);
}

void Solderunit::inc_health(float heal)
{
	this->currhealth = this->currhealth + heal;
}
