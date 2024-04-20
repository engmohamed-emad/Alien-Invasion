#include "Drones.h"
#include<cmath>

Drones::Drones()
{
	set_type("Drone");
}
Drones::Drones(int id, int jt, float h, float ap, int c)
{
	this->set_type("Drone");
	this->setID(id);
	this->set_Tj(jt);
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


