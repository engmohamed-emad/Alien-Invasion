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
bool AlienArmy::addSo_unit(AlianSounit* s)
{
    if (solders.enqueue(s))
    {
        num_sol++;
        return true;
    }
    return false;
}
bool AlienArmy::ReturnSo_uint(AlianSounit*& SoUnit)
{
    if (solders.dequeue(SoUnit))
    {
        num_sol--;
        return true;
    }
    else return false;
}

bool AlienArmy::get_monster(Monster* M)
{
    if (num_monster)
    {
        M = monsters[(--num_monster)];
        return true;
    }
    else return false;
}
bool AlienArmy::Add_Drones(Drones* D)
{
    if (!place1)//front
    {
        place1 = true;
        num_drones++;
        return Drone.enqueue_front(D);
       
    }
    else
    {
        place1 = false;
        num_drones++;
        return Drone.enqueue(D);
    }

}

bool AlienArmy::Get_Drones(Drones* D)
{
    if (!place2)//front
    {
        place2 = true;
        if (Drone.dequeue(D))
        {
            num_drones--;
            return true;
        }
        else return false;
    }
    else
    {
        place2 = false;
        if (Drone.dequeue_rear(D))
        {
            num_drones--;
            return true;
        }
        else return false;
    }
}

bool AlienArmy::Add_monster(Monster* M)
{
    if (num_monster < 1000)
    {
        monsters[num_monster] = M;
        num_monster++;
        return true;
    }
    else return false;
}

void AlienArmy::print()
{
    cout << "==============  Alien Army Alive Units ==============" << endl;
    cout << num_sol<< " AS [";
    solders.print();
    cout << "]" << endl;

    cout << num_monster << " AM [";
    for (int i = 0; i < num_monster; i++)
        cout << monsters[i]->getID() << " ,";
    cout << "]" << endl;

    cout << num_drones << " AD [";
    Drone.print();
    cout << "]" << endl;


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