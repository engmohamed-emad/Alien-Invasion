#include "ally_army.h"
#include <iostream>
using namespace std;


ally_army::~ally_army()
{
	SU* temp1;
	while (SU_unit.dequeue(temp1))
	{
		delete temp1;
		temp1 = nullptr;
	}
}
bool ally_army::is_emty()
{
	if (SU_unit.isEmpty())
		return true;
	return false;
}
bool ally_army::addSU_unit(SU*& s)
{
	if (SU_unit.enqueue(s)) 
	{
		num_su++;
		return true;
	}

	return false;
}

bool ally_army::ReturnSU_uint(SU*& SuUnit, unit*& pt)
{
	if (SU_unit.dequeue(SuUnit))
	{
		num_su--;
		pt = dynamic_cast<unit*>(SuUnit);
		return true;
	}
	else return false;
}

int ally_army::get_num_su()
{
	return num_su;
}

void ally_army::print()
{
	cout << "==============  Ally Army Alive Units ==============" << endl;
	cout << num_su << " SU [";
	SU_unit.print();
	cout << "]" << endl;
}

bool ally_army::Attack_Alien()
{
	SU* Sptr;
	bool flage1 = true;
	if (SU_unit.peek(Sptr))
		flage1 = Sptr->attack();
	return flage1;
}

