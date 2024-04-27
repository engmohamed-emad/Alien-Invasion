#pragma once
#include "unit.h"
class Game;
class Solderunit : public unit
{
private:
	
	int numstep = 0;
	Game* game;
public:
	Solderunit();
	Solderunit(int id, int jt, float h, float ap, int c, Game* g);
	virtual void dec_health(float damage);

	void set_numstep(int num);
	void inc_numstep();
	int get_numstep();
	
	virtual void inc_health(float heal);
	virtual bool attack();
	//attack2()
	/*{
	* 
	* unit* ptr;
	* for(0 to c)
	*  {
	*if( game->alienarmy->getsolder(ptr))
	* {
	* addtotemplist(ptr);
	}
	* 
	* }
	*  for(0 to c)
	* {
	* if(templist.de(ptr))
	*   ptr->dec_health(this->detect_damage(ptr->getcurrhealth()));
	* 
	* if(ptr->is_dead())
	* {
	game.killed;
	
	}

	* }
	}*/

};