#include "EarthArmy.h"

bool EarthArmy::addSo_unit(Solderunit& s)
{
    if (solders.enqueue(s))
        return true;
    return false;
}

bool EarthArmy::getSo_unit(Node<Solderunit>*& SoUnit)
{
    if (solders.rdequeue(SoUnit))
        return true;
    return false;
}

bool EarthArmy::ReturnSo_uint(Node<Solderunit>*& SoUnit)
{
    if (solders.frontenqueue(SoUnit))
        return true;
    return false;
}
