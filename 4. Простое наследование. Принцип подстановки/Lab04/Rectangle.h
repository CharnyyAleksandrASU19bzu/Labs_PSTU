#pragma once
#include "Pair.h"

class Rectangle : public Pair
{
public:
	//конструктор без параметров
	Rectangle();
public:
	//деструктор
	~Rectangle( );

	//конструктор с параметрами
	Rectangle(int, int);

	//конструктор копирования
	Rectangle(const Rectangle&);

	//Селекторы
	int get_perimeter();
	int get_area();

	//операция присваивания
	Rectangle& operator=(const Rectangle&);

	//операция ввода/вывода
	friend istream& operator>>(istream& in, Rectangle& r);
	friend ostream& operator<<(ostream& out, const Rectangle& r);
};