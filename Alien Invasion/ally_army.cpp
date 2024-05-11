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
