#include "vector.h"
#include "Time.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	Vector<Time>v(5);
	v.Print();
	cout << "����������� ������� : " << v.Min() << endl;
	cout << "������������ ������� : " << v.Max() << endl;
	v.Summa();
	v.Print();
};