#include "unit.h"

void unit::setID(int id)
{
	this->ID = id;
}

int unit::getID()
{
	return ID;
}

void unit::sethealth(float h)
{
	this->health = h;
<<<<<<< Updated upstream
	currhealth = health;
=======
	this->currhealth = h;
>>>>>>> Stashed changes
}

float unit::getcurrhealth()
{
	return currhealth;
}

void unit::setJtime(int t)
{
	Jtime = t;
}

int unit::getJtime()
{
	return Jtime;
}

void unit::setApower(float p)
{
	Apower = p;
}

float unit::getApower()
{
	return Apower;
}

void unit::setAcapacity(int c)
{
	Acapacity = c;
}

int unit::getAcapacity()
{
	return Acapacity;
}

void unit::set_type(string type)
{
	this->type = type;
}

string unit::get_type()
{
	return type;
}

void unit::dec_health(float damage)
{
	currhealth = currhealth - damage;
}

bool unit::inc_health(float heal)//take care when assign type of tank or earth solid. must be like in the cond. of if 
{
	if (get_type() == "ET" || get_type() == "ES")
	{
		currhealth = currhealth + heal;
	}
	else
		return false;

}

bool unit::is_dead()
{
	if (currhealth <= 0)
		return true;
	return false;
}

bool unit::need_help()
{
	if ((currhealth / health) < 0.2)
		return true;
	return false;
}
