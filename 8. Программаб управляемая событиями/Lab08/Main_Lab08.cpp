#include <iostream>
#include "Object.h"
#include "Person.h"
#include "Employee.h"
#include "Vector.h"
#include "Dialog.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	cout
		<< "m[������ ������] - ������� ������" << endl
		<< "+ - �������� ������� � ������" << endl
		<< "- - ������� ������� �� ������" << endl
		<< "s - ������� ���������� �� ��������� ������" << endl
		<< "z[������� � ������] - ������� ���������� �� �������� �" << endl
		<< "q - �����" << endl;

	Dialog D;
	D.Execute();
}