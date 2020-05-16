#include <iostream>
#include "Object.h"
#include "Person.h"
#include "Employee.h"
#include "Vector.h"
#include "Dialog.h"
using namespace std;

Vector::Vector()
{
}

Vector::Vector(int n)// конструктор с параметрами
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}
Vector::~Vector()// декструктор
{
	if (beg != 0)
		delete[] beg;
	beg = 0;
}
void Vector::Add()//Добавление элемента в вектор
{
	Object* p;
	// выбор из объектов двух возможных классов
	cout << "1. Человек" << endl;
	cout << "2. Сотрудник" << endl;
	int y;
	cin >> y;
	if (y == 1)//добавление класса Сar
	{
		Person* a = new (Person);
		a->Input();// ввод значения атрибутов
		p = a;
		if (cur < size)
		{
			beg[cur] = p;//добавление в вектор
			cur++;
		}
	}
	else
		if (y == 2) //добавление объекта класса Lorry
		{
			Employee* b = new Employee;
			b->Input();
			p = b;
			if (cur < size)
			{
				beg[cur] = p;
				cur++;
			}
		}
		else
			return;
}
void Vector::Del()//Удаление элементва из вектора
{
	if (cur == 0)
		return;
	cur--;
}
void Vector::Show()//Вывод элемента из вектора
{
	if (cur == 0)
		cout << "Empty" << endl;
	Object** p = beg;//указатель на указатель Object
	for (int i = 0; i < cur; i++)
	{
		(*p)->Show();//вызов метода Show() 
		p++;// передвигаем указатель на следующий объект
	}
}

int Vector::operator() ()
{
	return cur;
}


void Vector::HandleEvent(TEvent& e, int G)
{
	if (e.what = evMessage)
	{
		Object** p = beg; // Указатель на указатель типа Object
		int index = G - 1;
		for (int i = 0; i < cur; i++)
		{
			if (i == index)
				(*p)->HandleEvent(e);
			p++;
		}
	}
}