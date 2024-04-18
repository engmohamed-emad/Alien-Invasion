#include"unit.h"
#ifndef EG_h
#define EG_h


class EG :public unit
{
private:
	int pri;
	int Attack_Cap_Drone;
	int Attack_Cap_Monster;
	void setAttack_Cap_Drone(); //utility func to calc Attack  cap of Drone
	void setAttack_Cap_Monster();//same
public:
	EG();
	EG(int id, int jt, float h, float ap, int c);//you have to use this constructor to activate uitlities functions
	void Modfi_pri();
	//you need after any EG attack on it to call this function and then call get_pri & before any enqueue 
	int get_pri();
	int Get_Cap_Drone();
	int Get_Cap_Monster();
	virtual float attack(int enhealth);
	virtual void dec_health(float damage);
};
#endif
