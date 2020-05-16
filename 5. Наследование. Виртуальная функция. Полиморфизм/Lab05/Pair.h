#pragma once
#include "Object.h"
#include <iostream>
using namespace std;

class Pair:	
	public Object
{
public:
	//конструктор без параметров
	Pair();
public:
	//деструктор
	virtual ~Pair();

	//функция для просмотра с помощью указателя
	void Show();

	//констрктор с параметрами
	Pair(int, int);

	//конструктор копирования
	Pair(const Pair&);

	//селекторы
	int Get_number1();
	int Get_number2();
	int Get_mult();

	//модификаторы
	void Set_number1(int);
	void Set_number2(int);

	//перегрузка операции присваивания
	Pair& operator=(const Pair&);

	//глобальные операторы-функции ввода-вывода
	friend istream& operator>>(istream& in, Pair& p);
	friend ostream& operator<<(ostream& out, const Pair& p);

protected:
	int number1;
	int number2;
};