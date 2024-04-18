#include "EarthArmy.h"

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
    if (solders.enqueue(s))
        return true;
    return false;
}

bool EarthArmy::getSo_unit(Solderunit*& SoUnit)
{
    return solders.dequeue(SoUnit);
}

bool EarthArmy::ReturnSo_uint(Solderunit* SoUnit)
{
    return solders.enqueue_front(SoUnit);
        
}

void EarthArmy::Add_Earth_Gun(EG* G)
{
     Earth_Gun.enqueue(G, G->get_pri());
}



bool EarthArmy::Return_Gun(EG* G,int pri)
{
    return Earth_Gun.dequeue(G,pri);
}




