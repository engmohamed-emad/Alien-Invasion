#include "AlianSounit.h"

AlianSounit::AlianSounit()
{
}

AlianSounit::AlianSounit(int id, int jt, float h, float ap, int c)
{
	this->set_type("AS");
	this->setID(id);
	this->setJtime(jt);
	this->sethealth(h);
	this->setApower(ap);
	this->setAcapacity(c);
}

void AlianSounit::dec_health(float damage)
{
	this->currhealth = this->currhealth - damage;
}

float AlianSounit::attack(int enhealth)
{
	return (Apower * currhealth / 100) / sqrt(enhealth);
}


