#include "EarthArmy.h"
#include <iostream>
#include<random>
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
        total_units++;
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
     total_units++;
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
void EarthArmy::increment_infected()
{
    Num_infect_solid++;
}
void EarthArmy::decrement_infected()
{
    Num_infect_solid--;
}
void EarthArmy::spread_infection()
{
    Solderunit* s = nullptr;
    int prob=0;
    {   random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dis(0, 100);
        prob = dis(gen);
    }
        if (prob <= 2)
        {
            while (solders.dequeue(s))
            {
                if (s->get_state() == -1)
                {
                    s->set_state(0);
                    increment_infected();
                    solders.enqueue(s);
                }
                
            }


        }
        else
            return;
   

}
void EarthArmy::set_num_HU(int num)
{
    num_HU = num;
}
void EarthArmy::set_num_killed_HU(int num)
{
    num_killed_HU = num;
}
//edit
bool EarthArmy::Add_tank(Tank*& tank)
{
    if (tanks.push(tank))
    {
        total_units++;
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

void EarthArmy::update_num_killed_sol()
{
    num_killed_sol += 1;
}

void EarthArmy::update_num_killed_EG()
{
    num_killed_EG += 1;
}

void EarthArmy::update_num_killed_tank()
{
    num_killed_tank += 1;
}

void EarthArmy::ubdate_D(unit*& U)
{
    Df = Df + U->get_Df();
    Dd = Dd + U->get_Dd();
    Db = Db + U->get_Db();
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

   if( solders.peek(Sptr))
       if (Sptr->get_state() == 0)
       {
           bool x;
           x=Sptr->attack_infected();
       }
       else
       {
           flage1 = Sptr->attack();
       }
    if(tanks.peek(Tptr))
    flage2 = Tptr->attack(); //edit it to return bool to chick;
    if(Earth_Gun.peek(Gptr, pri))
    flage3 = Gptr->attack();

    

    return flage1 || flage2 || flage3;
}

void EarthArmy::print_statistics()
{
        cout << "===============Earth Army statistics===================== \n";
        cout << "ES total number : " << num_sol + num_killed_sol+num_Hsol<< " \n";
        cout << "ET total number : " << num_tank + num_killed_tank+num_Htank << "\n";
        cout << "EG total number : " << num_EG + num_killed_EG << "\n";
        cout << "ES Destructed/ES total = " << num_killed_sol * 100 / (1+(num_sol + num_killed_sol)) << "%" << "\n";
        cout << "ET Destructed/ET total = " << num_killed_tank * 100 /(1+ (num_tank + num_killed_tank)) << "%" << "\n";
        cout << "EG Destructed/EG total = " << num_killed_EG * 100 /(1+ (num_EG + num_killed_EG)) << "%" << "\n";
        cout << "Total Destructed/Total Units = " << (num_killed_sol + num_killed_tank + num_killed_EG) * 100 / (1+(num_sol + num_tank + num_EG + num_killed_sol + num_killed_tank + num_killed_EG)) << "%" << "\n";
        cout << "Average Df = " << Df / (1+(num_killed_sol + num_killed_tank + num_killed_EG)) << "\n";
        cout << "Average Dd = " << Dd /(1+ (num_killed_sol + num_killed_tank + num_killed_EG)) << "\n";
        cout << "Average Db = " << Db / (1+(num_killed_sol + num_killed_tank + num_killed_EG) )<< "\n";
        cout << "Df/Db % = " << Df * 100 / (1+Db) << "%" << "\n";
        cout << "Dd/Db % = " << Dd * 100 / (1+Db) << "%" << "\n";
     
}

int EarthArmy::get_total_ES_units()
{
    return num_sol + num_killed_sol + num_Hsol;
}

int EarthArmy::get_total_EG_units()
{
    return num_EG + num_killed_EG;
}

void EarthArmy::set_num_Htank(int num)
{
    num_Htank = num;
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
int EarthArmy::get_total_ET_units()
{
    return num_tank + num_killed_tank + num_Htank;
}
int EarthArmy::get_total_HU_units()
{
    return  num_HU+num_killed_HU;
}
float EarthArmy::get_per_EG()
{
    if ((num_EG + num_killed_EG))
    {
        return num_killed_EG * 100 / ((num_EG + num_killed_EG));
    }
    else
        return num_killed_EG * 100 / (1 + (num_EG + num_killed_EG));
}
float EarthArmy::get_per_ET()
{
    if ((num_tank + num_killed_tank+num_Htank))
    {
        return num_killed_tank * 100 / ((num_tank + num_killed_tank+num_Htank));
    }
    else
        return num_killed_tank * 100 / (1 + (num_tank + num_killed_tank+num_Htank));
}
float EarthArmy::get_per_total()
{
    if ((num_HU+num_killed_HU+num_Hsol + num_Htank + num_sol + num_tank + num_EG + num_killed_sol + num_killed_tank + num_killed_EG))
    {
        return  (num_killed_sol + num_killed_tank + num_killed_EG+num_HU) * 100 / ((num_HU + num_killed_HU + num_Hsol + num_Htank + num_sol + num_tank + num_EG + num_killed_sol + num_killed_tank + num_killed_EG));
    }
    else 
        return  (num_killed_sol + num_killed_tank + num_killed_EG+num_HU) * 100 / (1+(num_HU + num_killed_HU + num_Hsol + num_Htank + num_sol + num_tank + num_EG + num_killed_sol + num_killed_tank + num_killed_EG));
}
float EarthArmy::get_per_Df()
{
    if ((num_killed_sol + num_killed_tank + num_killed_EG))
    {
        return   Df / ((num_killed_sol + num_killed_tank + num_killed_EG));
    }
    else
        return Df / (1 + (num_killed_sol + num_killed_tank + num_killed_EG));
}
float EarthArmy::get_per_Dd()
{
    if ((num_killed_sol + num_killed_tank + num_killed_EG))
    {
        return   Dd / ((num_killed_sol + num_killed_tank + num_killed_EG));
    }
    else
        return Dd / (1 + (num_killed_sol + num_killed_tank + num_killed_EG));
}
float EarthArmy::get_per_Db()
{
    if ((num_killed_sol + num_killed_tank + num_killed_EG))
    {
        return   Db / ((num_killed_sol + num_killed_tank + num_killed_EG));
    }
    else
        return Db / (1 + (num_killed_sol + num_killed_tank + num_killed_EG));
}
float EarthArmy::get_per_ES()
{
    if ((num_sol + num_killed_sol + num_Hsol))
    {
        return num_killed_sol * 100 / ((num_sol + num_killed_sol + num_Hsol));
    }
    else
        return num_killed_sol * 100 / (1 + (num_sol + num_killed_sol + num_Hsol));
}
float EarthArmy::get_per_Dd_Db()
{
    if(Db)
    {
        return Dd * 100 / (Db);
    }
    return Dd * 100 / (1 + Db);
}
float EarthArmy::get_per_Df_Db()
{
    if (Db)
    {
        return Df * 100 / (Db);
    }
    return Df * 100 / (1 + Db);
}
int EarthArmy::get_num_Army()
{
    return num_tank + num_sol + num_EG;
}

void EarthArmy::set_num_Hsol(int num)
{
    num_Hsol = num;
}




