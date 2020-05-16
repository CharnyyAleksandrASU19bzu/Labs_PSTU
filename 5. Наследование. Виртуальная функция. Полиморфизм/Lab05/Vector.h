#pragma once
#include "Object.h"
#include <iostream>
using namespace std;

class Vector
{
public:
	//Конструктор без параметров
	Vector();
public:
	//Деструктор
	virtual ~Vector();

	//Конструктор с параметрами
	Vector(int);

	//Конструктор копирования
	Vector(const Vector&);

	//Добавление элемента в вектор 
	void Add(Object*);

	//Глобальный ввод
	friend ostream& operator<<(ostream& out, const Vector&);
private:
	//Указатель на первый элемент вектора
	Object** beg;
	//Размер
	int size;
	//Текущая позиция
	int cur;
};

