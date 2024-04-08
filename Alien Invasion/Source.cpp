#include <iostream>
#include"Tank.h"
#include"unit.h"
using namespace std;

int main()
{
	Tank t;
	Tank d(10,20,30,40,50);
	string x;
	cin >> x;
	t.set_type(x);
	cout << t.get_type();
	cout << d.getID();
	return 0;
}