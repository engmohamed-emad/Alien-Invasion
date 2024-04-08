#include"unit.h"
#ifndef EG_h
#define EG_h


class EG :public unit
{
private:
	int pri;
public:
	EG();
	EG(int id, int jt, float h, float ap, int c);
	void Modfi_pri();
	//you need after any EG attack on it to call this function and then call get_pri & before any enqueue 
	int get_pri();
	virtual float attack(int enhealth);
	virtual void dec_health(float damage);
};
#endif
