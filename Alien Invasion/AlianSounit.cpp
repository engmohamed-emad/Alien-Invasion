#include "AlianSounit.h"

AlianSounit::AlianSounit()
{
	set_type("AS");
}
AlianSounit::AlianSounit(int id, int jt, float h, float ap, int c)
{
	this->set_type("AS");
	this->setID(id);
	this->set_Tj(jt);
	this->sethealth(h);
	this->setApower(ap);
	this->setAcapacity(c);
}

void AlianSounit::dec_health(float damage)
{
	this->currhealth = this->currhealth - damage;
}




