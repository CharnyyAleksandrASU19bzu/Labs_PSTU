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
		<< "m[размер группы] - создать группу" << endl
		<< "+ - добавить элемент к группе" << endl
		<< "- - удалить элемент из группы" << endl
		<< "s - вывести информацию об элементах группы" << endl
		<< "z[позиция в группе] - вывести информацию об элементе №" << endl
		<< "q - выход" << endl;

	Dialog D;
	D.Execute();
}