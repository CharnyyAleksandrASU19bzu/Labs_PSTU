#include "vector.h"
#include "Time.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	Vector<Time>v(5);
	v.Print();
	cout << "Min : " << v.Min() << endl;
	cout << "Max : " << v.Max() << endl<<endl;
	v.Summa();
	v.Print();
};