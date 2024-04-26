#pragma once
#include "unit.h"
#include"Game.h"
class Game;
class HealingUnit : public unit
{
public:
	HealingUnit();
	HealingUnit(int id, int jt, float h, float ap, int c);
	virtual void dec_health(float damage);

	virtual void attack(Game* g);
};

