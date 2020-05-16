#pragma once
#include <iostream>
#include "Object.h"
using namespace std;

class Vector
{
public:
	//конструктор без параметров
	Vector(); 
public:
	// конструктор с параметрами
	Vector(int);

	// декструктор
	~Vector();

	void Add();//Добавление элемента в вектор
	void Del();
	void Show();//Вывод элемента из вектора
	int operator() ();

	void HandleEvent(TEvent& e, int);

protected:
	Object** beg;
	int size;
	int cur;
};