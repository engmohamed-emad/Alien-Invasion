#pragma once
#include<iostream>
#include"unit.h"
class Tank :public unit
{
private:
	int numstep = 0;
public:
	Tank();
	Tank(int id, int jt, float h, float ap, int c);
	
	virtual void dec_health(float damage);
	bool help_soldier(int ES_num,int AS_num);//takes numbers of earth and alien soldiers to determine if tank will attack alien soldiers or not 
};

