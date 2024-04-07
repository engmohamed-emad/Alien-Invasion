#ifndef unit_h
#define unit_h
#pragma once
#include <string>
using namespace std;
//Abstract class for all army units
class unit
{
private:
	int ID;
	float health;
	float currhealth;
	int Jtime;
	float Apower;
	int Acapacity;
	string type;
public:
	void setID(int id)
	{
		this->ID = id;
	}
	int getID()
	{
		return ID;
	}
	void sethealth(float h)
	{
		this->health = h;
	}
	int getcurrhealth()
	{
		return currhealth;
	}
	void setJtime(int t)
	{
		Jtime = t;
	}
	int getJtime()
	{
		return Jtime;
	}
	void setApower(float p)
	{
		Apower = p;
	}
	int getApower()
	{
		return Apower;
	}
	void setAcapacity(int c)
	{
		Acapacity = c;
	}
	int getAcapacity()
	{
		return Acapacity;
	}
	void set_type(string type)
	{
		this->type = type;
	}
	string get_type()
	{
		return type;
	}
	virtual void dec_health(float damage) = 0;
	virtual void inc_health(float heal) {}
	virtual bool is_dead()
	{
		if (currhealth <= 0)
			return true;
		return false;
	}
	virtual bool need_help()
	{
		if ((currhealth / health) < 0.2)
			return true;
		return false;
	}
	virtual int attack(int enhealth) = 0;
};
#endif

