#include "EG.h"
void EG::Modfi_pri()
{
	pri = getcurrhealth() + getApower();
}

int EG::get_pri()
{
	return pri;
}

int EG::attack(int enhealth)
{
	return 0;
}
