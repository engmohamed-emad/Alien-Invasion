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

bool EarthArmy::addSo_unit(Solderunit*& s)
{
    if (solders.enqueue(s)) {
        num_sol++;
        return true;
    }
       
    return false;
}

bool EarthArmy::ReturnSo_uint(Solderunit*& SoUnit,unit*&pt)
{
    if (solders.dequeue(SoUnit)) {
        num_sol--;
        pt = dynamic_cast<unit*>(SoUnit);
        return true;
    }
    else return false;
}

bool EarthArmy::return_tank(Tank*& t,unit*&pt)
{
    if (tanks.pop(t))
    {
        num_tank--;
        pt= dynamic_cast<unit*>(t);
        return true;
    }
    else 
        return false;
}
void EarthArmy::Add_Earth_Gun(EG*& G)
{
     Earth_Gun.enqueue(G, G->get_pri());
     num_EG++;
}



bool EarthArmy::Return_Gun(EG*& G,int pri,unit*&pt)
{
    if (Earth_Gun.dequeue(G, pri))
    {
        num_EG--;
        pt = dynamic_cast<unit*>(G);
        return true;
    }
    else return false;
}
int EarthArmy::get_num_sol()
{
    return num_sol;
}
//edit
bool EarthArmy::Add_tank(Tank*& tank)
{
    if (tanks.push(tank))
    {
        num_tank++;
        return true;
    }
    else return false;
}

void EarthArmy::print()
{
    cout << "==============  Earth Army Alive Units ==============" << endl;
    cout << num_sol << " ES [";
    solders.print();
    cout << "]" << endl;

    cout << num_tank << " ET [";
    tanks.print();
    cout << "]" << endl;

    cout << num_EG << " EG [";
    Earth_Gun.print();
    cout << "]" << endl;
}

EarthArmy::~EarthArmy()
{
    int pri = 0;
    Tank* temp1;
    EG* temp2;
   Solderunit* temp3;
   while (solders.dequeue(temp3))
   {
       delete temp3;
       temp3 = nullptr;
   }

   while (Earth_Gun.dequeue(temp2,pri))
   {
       delete temp2;
       temp2 = nullptr;
   }

   while (tanks.pop(temp1))
   {
       delete temp1;
       temp1 = nullptr;
   }


}




