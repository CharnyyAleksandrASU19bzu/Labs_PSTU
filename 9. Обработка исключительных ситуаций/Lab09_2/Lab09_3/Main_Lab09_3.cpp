#include "Vector.h"
#include "Error.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	try
	{
		int v,s,i,n;
		cout << "������� ������ �������" << endl;
		cin >> v;
		Vector x(v);
		Vector y;
		s = x;
		cout << "������" << endl << x << endl << "������ �������: " << s << endl;
		cout << "������� ������ ��� ������" << endl;
		cin >> i;
		cout << x[i] << endl;
		cout << "������� ���������� ��������� �� ������� :" << endl;
		cin >> n;
		x - n;
		cout << x;
		cout << "�������� ���������� ��������� � ������ :" << endl;
		cin >> n;
		x + n;
		cout << x;
	}
	catch (Error & e)
	{
		e.what();
	}
}