#ifndef unit_h
#define unit_h
#pragma once
#include <string>
using namespace std;
//Abstract class for all army units
class unit
{
protected:
	int ID;
	float health;
	float currhealth;
	int Jtime;
	float Apower;
	int Acapacity;
	string type;
public:
	void setID(int id);
	int getID();
	void sethealth(float h);
	float getcurrhealth();
	void setJtime(int t);
	int getJtime();
	void setApower(float p);
	float getApower();
	void setAcapacity(int c);
	int getAcapacity();
	void set_type(const string type);
	string get_type();
	void dec_health(float damage);
	bool inc_health(float heal);
	virtual bool is_dead();
	virtual bool need_help();
	virtual int attack(int enhealth) = 0;
};
#endif

