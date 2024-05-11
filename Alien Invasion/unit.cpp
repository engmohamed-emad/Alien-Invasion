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

void unit::set_Tj(int t)
{
	Tj = t;
}

int unit::get_Tj()
{
	return Tj;
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
int unit::get_Td()
{
	return Td;
}
int unit::get_Ta()
{
	return Ta;
}
void unit::set_Ta(int t)
{
	Ta = t;
}
void unit::set_Td(int t)
{
	Td = t;
}
int unit::get_Dd()
{
	return Td - Ta;
}
void unit::set_firtAttack()
{
	first_attack = true;
}
bool unit::get_firstAttack()
{
	return first_attack;
}
int unit::get_Df()
{
	return Ta - Tj;
}
int unit::get_Db()
{
	return Td - Tj;
}