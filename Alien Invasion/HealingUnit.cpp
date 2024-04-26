#include "HealingUnit.h"

HealingUnit::HealingUnit()
{
	this->set_type("HU");
}

HealingUnit::HealingUnit(int id, int jt, float h, float ap, int c)
{
	this->set_type("HU");
	this->setID(id);
	this->set_Tj(jt);
	this->sethealth(h);
	this->setApower(ap);
	this->setAcapacity(c);
}

void HealingUnit::dec_health(float damage)
{
	currhealth = -1;
}

void HealingUnit::attack(Game* g)
{
	
}
