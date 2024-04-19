#include "Monster.h"
#include"unit.h"
#include<iostream>
Monster::Monster()
{
	set_type("Monster");
}
Monster::Monster(int id, int jt, float h, float ap, int c)
{
	this->set_type("Monster");
	this->setID(id);
	this->set_Tj(jt);
	this->sethealth(h);
	this->setApower(ap);
	this->setAcapacity(c);
}
float Monster::attack(int enhealth)
{
	return (Apower * currhealth / 100) / sqrt(enhealth);
}
void Monster::dec_health(float damage)
{
	this->currhealth = this->currhealth - damage;
}