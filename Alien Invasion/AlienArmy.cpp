#include "AlienArmy.h"

bool AlienArmy::ADD_unit(unit*& ptr)
{
    if (ptr->get_type() == "Drone")
    {
        Drones* derivedPtr = dynamic_cast<Drones*>(ptr);
        Add_Drones(derivedPtr);
        return true;
    }
}

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


bool AlienArmy::Add_Drones(Drones* D)
{
    if (!place1)//front
    {
        place1 = true;
        return Drone.enqueue_front(D);

    }
    else
    {
        place1 = false;
        return Drone.enqueue(D);
    }

}

bool AlienArmy::Get_Drones(Drones* D)
{
    if (!place2)//front
    {
        place2 = true;
        return Drone.dequeue(D);
    }
    else
    {
        place2 = false;
        return Drone.dequeue_rear(D);
    }
}










//bool AlienArmy::Return_Drones(Drones*& D, int Num_Drones)  // in Get Drones and Add drones we start from front then back here we put Drones in temp stack so when you renqueue you have to see number of drones in temp list if odd then start from front if even start from back
//{
//    if (Num_Drones % 2 == 0)
//        place3 = true;
//    else
//        place3 = false;
//    if (!place3) //front 
//    {
//        place3 = true;
//        return Drone.renqueue_front(D);
//    }
//    else
//    {
//        place3 = false;
//        return Drone.renqueue(D);
//    }
//
//}