#include"unit.h"
#ifndef EG_h
#define EG_h


class EG :public unit
{
private:
	int pri;
public:
	void Modfi_pri();
	//you need after any EG attack on it to call this function and then call get_pri & before any enqueue 
	int get_pri();
	virtual int attack(int enhealth);
};
#endif