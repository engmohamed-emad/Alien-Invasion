#pragma once
#include "unit.h"


//unit for Alian solder 
class Game;
class AlianSounit :  public unit
{ 
private:
	Game* game;
public:
	 
	AlianSounit();
	AlianSounit(int id, int jt, float h, float ap, int c, Game* g);
	virtual void dec_health(float damage);
	virtual bool attack();

};

