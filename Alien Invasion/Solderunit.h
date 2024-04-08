#pragma once
#include "unit.h"
class Solderunit : public unit
{
public:
	Solderunit(int id, int jt, float h, float ap, int c);
	virtual void dec_health(float damage);
	virtual int attack(int enhealth);
	virtual void inc_health(float heal);

};

