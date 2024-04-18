#include "Drones.h"
#include<cmath>

Drones::Drones()
{
}

Drones::Drones(int id, int jt, float h, float ap, int c)
{
	this->set_type("Drone");
	this->setID(id);
	this->setJtime(jt);
	this->sethealth(h);
	this->setApower(ap);
	this->setAcapacity(c);
}

float Drones::attack(int enhealth)
{
	return (Apower * currhealth / 100) / sqrt(enhealth);
}

void Drones::dec_health(float damage)
{
	this->currhealth = this->currhealth - damage;
}

char Drones::kind()
{
	return 'D';
}
