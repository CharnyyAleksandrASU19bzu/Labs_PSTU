#pragma once
#include "Pair.h"

class Rectangle : 
	public Pair
{
public:
	//конструктор без параметров
	Rectangle();
public:
	//деструктор
	~Rectangle();

	//функция для просмотра с помощью указателя
	void Show();

	//конструктор с параметрами
	Rectangle(int, int);

	//конструктор копирования
	Rectangle(const Rectangle&);

	//модификаторы
	int get_perimeter();
	int get_area();

	//операция присваивания
	Rectangle& operator=(const Rectangle&);

	//операция ввода/вывода
	friend istream& operator>>(istream& in, Rectangle& r);
	friend ostream& operator<<(ostream& out, const Rectangle& r);
};