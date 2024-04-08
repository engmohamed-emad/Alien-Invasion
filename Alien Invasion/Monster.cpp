#include "Monster.h"
#include"unit.h"
#include<iostream>
Monster::Monster()
{}
Monster::Monster(int id, int jt, float h, float ap, int c)
{
	this->set_type("Tank");
	this->setID(id);
	this->setJtime(jt);
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