#pragma once
#include <iostream>
#include <list>
using namespace std;

//параметр шаблона
template<class T>

class Vector
{
	list<T>l;
	int len;
public:
	//Конструктор по умолчанию
	Vector();
	//конструктор с параметрами
	Vector(int s);
	//Печать
	void Print();
	
	T Min();//минимальный элемент
	T Max();//максимальный вектор
	void Summa();//сумма
	//деструктор
	~Vector();
};



template<class T>
Vector<T>::Vector()//Конструктор по умолчанию
{
	len = 0;
}

template<class T>
Vector<T>::Vector(int n)//Конструктор с параметрами
{
	
	for (int i = 0; i < n; i++)
	{
		int m = rand() % 60;
		int s = rand() % 60;
		T a(m, s);
		l.push_back(a);
	}
}

template<class T>
void Vector<T>::Print()//Печать
{
	typename list<T>::iterator it = l.begin();
	for (it; it != l.end(); ++it)
	{
		if (!l.empty())
			cout << *it << endl;
	}
	cout << endl;
}

template<class T>
Vector<T>::~Vector() //Деструктор
{

}


template<class T>
T Vector<T>::Min() //минимальный элемент
{
	typename list<T>::iterator it = l.begin();
	int n = 0,
		k = 0;
	T m = (*it);
	while (it != l.end())
	{
		if (m > * it)
		{
			m = (*it);
			n = k;
		}
		it++;
		k++;
	}
	return m;
}

template<class T>
T Vector<T>::Max() //максимальный элемент
{
	typename list<T>::iterator it = l.begin();
	int n = 0,
		k = 0;
	T m = (*it);
	while (it != l.end())
	{
		if (m < * it)
		{
			m = (*it);
			n = k;
		}
		it++;
		k++;
	}
	return m;
}

template<class T>
void Vector<T>::Summa() //сумма
{
	typename list<T>::iterator it = l.begin();
	for (it; it != l.end(); ++it)
	{
		*it = *it + Min() + Max();
	}
}