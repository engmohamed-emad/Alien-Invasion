#pragma once
#include "unit.h"

//unit for Alian solder 
class Game;
class AlianSounit :  public unit
{ 
public:
	 
	AlianSounit();
	AlianSounit(int id, int jt, float h, float ap, int c);
	virtual void dec_health(float damage);
	//virtual void attack(Game* g);
};

