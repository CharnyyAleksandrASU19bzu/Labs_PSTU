#include "Employee.h"

//конструктор без параметров
Employee::Employee() :Person()
{
	salary = 0.0;
	position = "";
}

//конструктор с параметрами
Employee::Employee(string N, int A, float S, string P) : Person(N, A)
{
	salary = S;
	position = P;
}

//конструктор копированаия
Employee::Employee(const Employee& e)
{
	name = e.name;
	age = e.age;
	salary = e.salary;
	position = e.position;
}

//деструктор
Employee::~Employee()
{
}

//cелекторы
float Employee::get_salary()
{
	return salary;
}

//модификаторы
void Employee::set_salary(float S)
{
	salary = S;
}

//перегрузка операции присваивания
Employee& Employee::operator=(const Employee& e)
{
	if (&e == this) 
		return *this;
	name = e.name;
	age = e.age;
	salary = e.salary;
	return *this;
}

//ввод-ввыод
void Employee::Show()
{
	cout << endl << "Имя :" << name;
	cout << endl << "возраст :" << age;
	cout << endl << "Заработная плата :" << salary;
	cout << endl;
}
void Employee::Input()
{
	cout << endl << "Имя  : ";
	cin >> name;
	cout << endl << "Возраст : ";
	cin >> age;
	cout << endl << "Заработная плата : ";
	cin >> salary;
}