#pragma once
#include <string>
#include <iostream>
#include "Object.h"
using namespace std;

class Person :
	public Object
{
public:
	//конструктор без параметров
	Person (); 
public:
	//конструктор с параметрами
	Person (string, int); 
	//конструктор копирования
	Person (const Person&);
	
	//деструктор
	virtual ~Person();
	
	//ввод-вывод
	void Show(); 
	void Input();
		
	//селекторы
	string get_name();
	int get_age();

	//модификаторы
	void set_name(string);
	void set_age(int);
	
	//перегрузка операции присваивания
	Person& operator=(const Person&);

	void HandleEvent(const TEvent& e);
protected:
	string name;
	int age;
};
