#pragma once
#include"unit.h"
#include<iostream>
class Monster:public unit
{
public:
	Monster();
	Monster(int id, int jt, float h, float ap, int c);
	virtual void dec_health(float damage);
};

