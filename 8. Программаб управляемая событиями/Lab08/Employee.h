#pragma once
#include "Person.h"

class Employee :
	public Person
{
public:
	//����������� ��� ����������
	Employee(); 
public:
	//����������� � �����������
	Employee(string, int, float, string);
	//����������� �����������
	Employee(const Employee&);

	//����������
	~Employee();

	//����-�����
	void Show(); 
	void Input();

	//���������
	float get_salary();

	//������������
	void set_salary(float);

	//���������� �������� ������������
	Employee& operator=(const Employee&); 
protected:
	float salary;
	string position;
};