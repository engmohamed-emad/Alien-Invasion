#include "EarthArmy.h"
#include <iostream>
using namespace std;

bool EarthArmy::Add_unit(unit* ptr)
{
    if (ptr->get_type() == "EG")
    {
        EG* derivedPtr = dynamic_cast<EG*>(ptr);
        Add_Earth_Gun(derivedPtr);
        return true;
    }
}

bool EarthArmy::addSo_unit(Solderunit* s)
{
    if (solders.enqueue(s)) {
        num_sol++;
        return true;
    }
       
    return false;
}

bool EarthArmy::getSo_unit(Solderunit*& SoUnit)
{
    return solders.dequeue(SoUnit);
}

bool EarthArmy::ReturnSo_uint(Solderunit* SoUnit)
{
    return solders.enqueue(SoUnit);
        
}

void EarthArmy::Add_Earth_Gun(EG* G)
{
     Earth_Gun.enqueue(G, G->get_pri());
     num_EG++;
}



bool EarthArmy::Return_Gun(EG* G,int pri)
{
    return Earth_Gun.dequeue(G,pri);
}
//edit
bool EarthArmy::Add_tank(Tank* tank)
{
    if (tanks.push(tank))
    {
        num_tank++;
        return true;
    }
    else return false;
}

void EarthArmy::print(int countS, int countT, int countG)
{
    cout << "==============  Earth Army Alive Units ==============" << endl;
    cout << countS << " ES [";
    solders.print();
    cout << "]" << endl;



    cout << countG << " EG [";
    Earth_Gun.print();
    cout << "]" << endl;
}




