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
	int Tj=0;  
	float Apower;
	int Acapacity;
	string type;
	int Ta=0;
	int Td=0;
	int Db;
	int Df;
	int Dd;
	bool first_attack = false;
public:
	void setID(int id);
	int getID();
	void sethealth(float h);
	float getcurrhealth();
	void set_Tj(int t);
	int get_Tj();
	void setApower(float p);
	int getApower();
	void setAcapacity(int c);
	int getAcapacity();
	void set_type(string type);
	string get_type();
	void set_Ta(int t);
	void set_Td(int t);
	int get_Db();
	int get_Df();
	int get_Dd();
	virtual void dec_health(float damage) = 0;
	virtual void inc_health(float heal) {}
	virtual bool is_dead();
	virtual bool need_help();
	virtual float detect_damage(int enhealth)
	{
		return (Apower * currhealth / 100) / sqrt(enhealth);
	}
	//virtual bool attack()=0;
	
};
#endif

