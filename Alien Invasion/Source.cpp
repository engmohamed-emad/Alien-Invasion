#include <iostream>
#include<random>
#include"EarthArmy.h"
#include"AlienArmy.h"
using namespace std;
double generate_ran(int num1, int num2)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(num1, num2); 
	
		int random_num = dis(gen);
		return  random_num;
	
}
// function for files 
int main()
{
	int n1, n2;
	while (1)
	{
		cin >> n1>> n2;
		cout << generate_ran(n1, n2) << endl;
	}
	return 0;
}