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
	int getApower();
	void setAcapacity(int c);
	int getAcapacity();
	void set_type(string type);
	string get_type();
	virtual void dec_health(float damage) = 0;
	virtual void inc_health(float heal) {}
	virtual bool is_dead();
	virtual bool need_help();
	virtual float attack(int enhealth) = 0;
};
#endif

