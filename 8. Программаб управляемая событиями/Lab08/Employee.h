#pragma once
#include "Person.h"

class Employee :
	public Person
{
public:
	//конструктор без параметров
	Employee(); 
public:
	//конструктор с параметрами
	Employee(string, int, float, string);
	//конструктор копирования
	Employee(const Employee&);

	//деструктор
	~Employee();

	//ввод-вывод
	void Show(); 
	void Input();

	//селекторы
	float get_salary();

	//модификаторы
	void set_salary(float);

	//перегрузка операции присваивания
	Employee& operator=(const Employee&); 
protected:
	float salary;
	string position;
};