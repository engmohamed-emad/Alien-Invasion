#include "AlienArmy.h"

bool AlienArmy::addSo_unit(AlianSounit& s)
{
    if (solders.enqueue(s))
        return true;
    return false;
}

bool AlienArmy::getSo_unit(Node<AlianSounit>*& SoUnit)
{
    if (solders.rdequeue(SoUnit))
        return true;
    return false;
}

bool AlienArmy::ReturnSo_uint(Node<AlianSounit>*& SoUnit)
{
    if (solders.frontenqueue(SoUnit))
        return true;
    return false;
}
