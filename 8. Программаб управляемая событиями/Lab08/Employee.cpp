#include "Employee.h"

//����������� ��� ����������
Employee::Employee() :Person()
{
	salary = 0.0;
	position = "";
}

//����������� � �����������
Employee::Employee(string N, int A, float S, string P) : Person(N, A)
{
	salary = S;
	position = P;
}

//����������� ������������
Employee::Employee(const Employee& e)
{
	name = e.name;
	age = e.age;
	salary = e.salary;
	position = e.position;
}

//����������
Employee::~Employee()
{
}

//c��������
float Employee::get_salary()
{
	return salary;
}

//������������
void Employee::set_salary(float S)
{
	salary = S;
}

//���������� �������� ������������
Employee& Employee::operator=(const Employee& e)
{
	if (&e == this) 
		return *this;
	name = e.name;
	age = e.age;
	salary = e.salary;
	return *this;
}

//����-�����
void Employee::Show()
{
	cout << endl << "��� :" << name;
	cout << endl << "������� :" << age;
	cout << endl << "���������� ����� :" << salary;
	cout << endl;
}
void Employee::Input()
{
	cout << endl << "���  : ";
	cin >> name;
	cout << endl << "������� : ";
	cin >> age;
	cout << endl << "���������� ����� : ";
	cin >> salary;
}