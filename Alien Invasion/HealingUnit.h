#pragma once
#include "unit.h"
class Game;
class HealingUnit : public unit
{
private:
	Game* game;
	int num_healed=0;
public:
	HealingUnit();
	HealingUnit(int id, int jt, float h, float ap, int c,Game*g);
	virtual void dec_health(float damage);

	virtual void attack();//*******************************
	int get_num_healed();
};

