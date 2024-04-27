#include "HealingUnit.h"
#include"Game.h"
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

void HealingUnit::attack(Game* g)
{
	
}
