#include "Time.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	Time a;
	Time b;
	Time c;
	cin >> a;
	cin >> b;
	c = a - b;
	if (a != b)
		cout << "����� ������" << endl;
	else
		cout << "����� ����������" << endl;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "a-b=" << c << endl;
}