#include <iostream>
#include "Person.h"

//конструктор без параметров
Person::Person() 
{
	name = "";
	age = 0;
}

//конструктор с параметрами
Person::Person(string N, int A) 
{
	name = N;
	age = A;
}

//конструктор копированаия
Person::Person(const Person& per) 
{
	name = per.name;
	age = per.age;
}

//деструктор
Person::~Person() 
{
}

//селекторы
string Person::get_name()
{
	return name;
}
int Person::get_age()
{
	return age;
}

//модификаторы
void Person::set_name(string N)
{
	name = N;
}
void Person::set_age(int A)
{
	age = A;
}

// оператор присвоения
Person& Person::operator=(const Person& p)
{
	if (&p == this) 
		return *this;
	name = p.name;
	age = p.age;
	return *this;
}

//ввод-вывод
void Person::Show()
{
	cout << endl << "Имя : " << name;
	cout << endl << "Возраст : " << age;
	cout << endl;
}
void Person::Input()
{
	cout << endl << "Имя : ";
	cin >> name;
	cout << endl << "Возраст : ";
	cin >> age;
}

void Person::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		switch (e.command)
		{
		case cmGet:cout << "Имя :" << get_name() << endl;
			break;
		}
	}
}