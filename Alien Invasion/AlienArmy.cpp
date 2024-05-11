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
        cout << monsters[i]->getID()<< "(" << monsters[i]->getcurrhealth() << ")";
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

void AlienArmy::update_num_killed_sol()
{
    num_killed_sol += 1;
}

void AlienArmy::update_num_killed_monster()
{
    num_killed_monster += 1;
}

void AlienArmy::update_num_killed_drones()
{
    num_killed_drones += 1;
}

void AlienArmy::ubdate_D(unit*& U)
{
    
        Df = Df + U->get_Df();
        Dd = Dd + U->get_Dd();
        Db = Db + U->get_Db();
    
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

void AlienArmy::print_statistics()
{
    cout << "===============Alien Army statistics===================== \n";
    cout << "AS totsl number : " << num_sol + num_killed_sol <<" \n";
    cout << "AM totsl number : " << num_monster + num_killed_monster << "\n";
    cout << "AD totsl number : " << num_drones + num_killed_drones << "\n";
    cout << "AS Destructed/AS total = " << num_killed_sol * 100 / (1+(num_sol + num_killed_sol))<<"%" << "\n";
    cout << "AM Destructed/AM total = " << num_killed_monster * 100 /(1+(num_monster + num_killed_monster))<<"%" << "\n";
    cout << "AD Destructed/AD total = " << num_killed_drones * 100 /(1+ (num_drones + num_killed_drones))<<"%" << "\n";
    cout << "Total Destructed/Tatal Units = " << (num_killed_sol + num_killed_monster + num_killed_drones) * 100 / (1+(num_sol + num_monster + num_drones + num_killed_sol + num_killed_monster + num_killed_drones))<<"%" << "\n";
    cout << "Average Df = " <<Df/(1+(num_killed_sol + num_killed_monster + num_killed_drones)) << "\n";
    cout << "Average Dd = " << Dd /(1+ (num_killed_sol + num_killed_monster + num_killed_drones) )<< "\n";
    cout << "Average Db = " << Db / (1+(num_killed_sol + num_killed_monster + num_killed_drones)) << "\n";
    cout << "Df/Db % = " << Df * 100 /(1+ Db) << "%" << "\n";
    cout << "Dd/Db % = " << Dd * 100 / (1+Db) << "%" << "\n\n";
}




int AlienArmy::get_total_num_AM()
{
    return num_monster + num_killed_monster;
}
float AlienArmy::get_per_AS()
{
    if ((num_sol + num_killed_sol))
    {
        return num_killed_sol * 100 / ((num_sol + num_killed_sol));
    }
    else
        return num_killed_sol * 100 / (1 + (num_sol + num_killed_sol));
}
int AlienArmy::get_total_num_AD()
{
    return num_drones + num_killed_drones;
}
int AlienArmy::get_total_num_AS()
{
    return num_sol + num_killed_sol;
}

float AlienArmy::get_per_AM()
{
    if ((num_monster + num_killed_monster))
    {
        return num_killed_monster * 100 / ((num_monster + num_killed_monster));
    }
    else
        return num_killed_monster * 100 / (1 + (num_monster + num_killed_monster));
}

float AlienArmy::get_per_AD()
{
    if ((num_drones + num_killed_drones))
    {
        return num_killed_drones * 100 / ((num_drones + num_killed_drones));
    }
    else
        return num_killed_drones * 100 / (1 + (num_drones + num_killed_drones));
}

float AlienArmy::get_per_total()
{
    if ((num_sol + num_monster + num_drones + num_killed_sol + num_killed_monster + num_killed_drones))
    {
        (num_killed_sol + num_killed_monster + num_killed_drones) * 100 / ( (num_sol + num_monster + num_drones + num_killed_sol + num_killed_monster + num_killed_drones));
    }
    else
        return (num_killed_sol + num_killed_monster + num_killed_drones) * 100 / (1 + (num_sol + num_monster + num_drones + num_killed_sol + num_killed_monster + num_killed_drones));
}

float AlienArmy::get_per_Df()
{
    if ((num_killed_sol + num_killed_monster + num_killed_drones))
    {
        return Df / ((num_killed_sol + num_killed_monster + num_killed_drones));
    }
    else
        return Df / (1 + (num_killed_sol + num_killed_monster + num_killed_drones));
}
float AlienArmy::get_per_Dd()
{
    if ((num_killed_sol + num_killed_monster + num_killed_drones))
    {
        return Dd / ((num_killed_sol + num_killed_monster + num_killed_drones));
    }
    else
        return Dd / (1 + (num_killed_sol + num_killed_monster + num_killed_drones));
}
float AlienArmy::get_per_Db()
{
    if ((num_killed_sol + num_killed_monster + num_killed_drones))
    {
        return Db / ((num_killed_sol + num_killed_monster + num_killed_drones));
    }
    else
        return Db / (1 + (num_killed_sol + num_killed_monster + num_killed_drones));
}
float AlienArmy::get_per_Dd_Db()
{
    if (Db)
    {
        return Dd * 100 / (Db);
    }
    return Dd * 100 / (1 + Db);
}
float AlienArmy::get_per_Df_Db()
{
    if (Db)
    {
        return Df * 100 / (Db);
    }
    return Df * 100 / (1 + Db);
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