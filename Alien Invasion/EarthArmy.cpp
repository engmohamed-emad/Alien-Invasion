#include "EarthArmy.h"
#include <iostream>
#include<random>
using namespace std;

void EarthArmy::set_num_hsol(int n)
{
    num_hsol = n;
}

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
bool EarthArmy::get_allay_canAttack()
{
    return allay_canAttack;
}
void EarthArmy::increment_infected()
{
    Num_infect_solid++;
    Num_total_infected++;
    if (this->need_a())
        allay_canAttack = true;
}
void EarthArmy::decrement_infected()
{
    Num_infect_solid--;
    if (Num_infect_solid == 0)
        allay_canAttack = false;
}
void EarthArmy::spread_infection()
{
    LinkedQueue<Solderunit*>temp;
    Solderunit* s = nullptr;
    int prob=0;
    {   random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dis(1, 100);
        prob = dis(gen);
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    int c = 0;
        if (prob <= 2 && Num_infect_solid!=0)
        {
            int j = 0;
            {
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<int> dis(1, num_sol);
                j = dis(gen);
            }
            while (solders.dequeue(s))
            {
                c++;
                temp.enqueue(s);  
                if (j==c)
                {
                    if(s->get_state()==-1)
                    {
                        s->set_state(0);
                        increment_infected(); 
                    }
                }
            }
            while (temp.dequeue(s))
            {
                solders.enqueue(s);
            }
        }
        else
            return;
   

}

void EarthArmy::set_need_ally(int a)
{
    need_allay = a;
}

bool EarthArmy::retret_ally()
{
    return !Num_infect_solid;
}

int EarthArmy::get_total_num_infected()
{
    return Num_total_infected;
}

bool EarthArmy::need_a()
{
    if (num_sol == 0)
        return false;
    if ((float(Num_infect_solid)*100 /float( num_sol+num_hsol)) >= need_allay)
        return true;
    return false;
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




bool EarthArmy::Attack_Alien()
{
    Solderunit* Sptr;
    Tank* Tptr;
    EG* Gptr;
    bool flage1 = true;
    bool flage2 = true;
    bool flage3 = true;
    int pri = 0;


    spread_infection();//********************************
    bool x=false;
   if( solders.peek(Sptr))
       if (Sptr->get_state() == 0)
       {
           x=Sptr->attack_infected();
       }
       else
       {
           flage1 = Sptr->attack();
       }
   if (tanks.peek(Tptr))
       flage2 = Tptr->attack(); //edit it to return bool to chick;
   if (Earth_Gun.peek(Gptr, pri))
       flage3 = Gptr->attack();
   return flage1 || flage2 || flage3;
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

int EarthArmy::get_num_Army()
{
    return num_tank + num_sol + num_EG;
}






