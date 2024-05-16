#include "AlienArmy.h"

int generate_ran(int num1, int num2)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(num1, num2);

    int random_num = dis(gen);
    return  random_num;

}
bool AlienArmy::ADD_unit(unit*& ptr)
{
    if (ptr->get_type() == "Drone")
    {
        Drones* derivedPtr = dynamic_cast<Drones*>(ptr);
        Add_Drones(derivedPtr);
        return true;
    }
}
bool AlienArmy::addSo_unit(AlianSounit*& s)
{
    if (solders.enqueue(s))
    {
        num_sol++;
        return true;
    }
    return false;
}
bool AlienArmy::ReturnSo_uint(AlianSounit*& SoUnit, unit*& pt)
{
    if (solders.dequeue(SoUnit))
    {
        num_sol--;
        pt = dynamic_cast<unit*>(SoUnit);
        return true;
    }
    else return false;
}

bool AlienArmy::get_monster(Monster*& M, unit*& pt)
{    
    
    if (num_monster)
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dis(0, num_monster-1);
        int index = dis(gen);
        M = monsters[index];
        monsters[index] = monsters[(--num_monster)];
        pt = dynamic_cast<unit*>(M);
        return true;
    }
    else return false;
}
bool AlienArmy::Add_Drones(Drones*& D)
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

bool AlienArmy::Get_Drones(Drones*& D, unit*& pt)
{
    if (!place2)//front
    {
        place2 = true;
        if (Drone.dequeue(D))
        {
            num_drones--;
           pt= dynamic_cast<unit*>(D);
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
            pt = dynamic_cast<unit*>(D);
            return true;
        }
        else return false;
    }
}

int AlienArmy::get_num_sol()
{
    return num_sol;
}

AlienArmy::~AlienArmy()
{ 
    AlianSounit* temp1;
    Drones* temp2;
    while (solders.dequeue(temp1))
    {
        delete temp1;
        temp1 = nullptr;
    }
    
    while (Drone.dequeue(temp2))
    {
        delete temp2;
        temp2 = nullptr;
    }
    for (int i = 0; i < num_monster; i++)
    {     
        delete monsters[i];
        monsters[i] = nullptr;
    }


}

bool AlienArmy::Add_monster(Monster*& M)
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
    {
        //comments were added to see the current health while iterating
        cout << monsters[i]->getID()/* << "(" << monsters[i]->getcurrhealth() << ")"*/;
        if (i < num_monster - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    cout << num_drones << " AD [";
    Drone.print();
    cout << "]" << endl;


}



bool AlienArmy::Attack_Earth()
{
    AlianSounit* Sptr;
    Monster* Mptr;
    Drones* Dptr;
    Drones* D;
    bool flage1 = true;
    bool flage2 = true;
    bool flage3 = true;

    if (solders.peek(Sptr))
        flage1 = Sptr->attack();
    if (num_monster > 0)
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dis(0, num_monster - 1);
        int index = dis(gen);
        flage2 = monsters[index]->attack();
    }
    if (Drone.can_attacks())
    {
        // handling one from first and one from last
        if (Drone.peek(Dptr))
            if (Drone.peek_rear(D))
                flage3 = Dptr->attack() && D->attack();
    }
    return flage1 || flage2 || flage3;
}








int AlienArmy::get_num_Army()
{
    return num_sol + num_monster + num_drones;
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