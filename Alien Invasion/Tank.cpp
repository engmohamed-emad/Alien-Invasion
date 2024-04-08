#include "Tank.h"
#include"unit.h"
#include<iostream>
#include<cmath>
Tank::Tank()
{}
Tank::Tank(int id, int jt, float h, float ap, int c)
{
	this->set_type("Tank");
	this->setID(id);
	this->setJtime(jt);
	this->sethealth(h);
	this->setApower(ap);
	this->setAcapacity(c);
}
float Tank::attack(int enhealth)
{
	return (Apower * currhealth / 100) / sqrt(enhealth);
}
void Tank::dec_health(float damage)
{
	this->currhealth = this->currhealth - damage;
}
bool Tank::help_soldier(int ES,int AS)
{
	if ((float(ES) / float(AS)) < .3)
		return true;
	else return false;
}

