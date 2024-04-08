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
	this->currhealth = h;
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

int unit::getApower()
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
