#pragma once
#include "unit.h"
//unit for Alian solder 
class AlianSounit :  public unit
{
public:
	AlianSounit();
	AlianSounit(int id, int jt, float h, float ap, int c);
	virtual void dec_health(float damage);
	


};

