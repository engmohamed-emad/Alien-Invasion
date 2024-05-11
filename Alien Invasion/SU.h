#pragma once
#include "unit.h"
class Game;
class SU :  public unit
{
private:
	Game* game;
public:
	SU();
	SU(int id, int jt, float h, float ap, int c, Game* g);
	virtual void dec_health(float damage);

	virtual bool attack();
};

