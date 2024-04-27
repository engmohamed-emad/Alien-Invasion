#include"unit.h"
#include"LinkedQueue.h"
#ifndef EG_h
#define EG_h

class Game;
class EG :public unit
{
private:
	Game* game;
	int pri;
	int Attack_Cap_Drone;
	int Attack_Cap_Monster;
	void setAttack_Cap_Drone(); //utility func to calc Attack  cap of Drone
	void setAttack_Cap_Monster();//same
public:
	EG();
	EG(int id, int jt, float h, float ap, int c,Game*g);//you have to use this constructor to activate uitlities functions
	void Modfi_pri();
	int get_pri();
	virtual void dec_health(float damage);
	virtual bool attack();

};
#endif
