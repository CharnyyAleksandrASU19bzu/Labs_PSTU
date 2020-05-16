#pragma once
#include <iostream>
#include <set>
#include <iterator>
using namespace std;

//параметр шаблона
template<class T>

class Vector
{
	set<T>v;
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
		v.insert(a);
	}
}

template<class T>
void Vector<T>::Print()//Печать
{
	typename set<T>::iterator it = v.begin();
	for (it; it != v.end(); ++it)
	{
		if (!v.empty())
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
	typename set<T>::iterator it = v.begin();
	int n = 0,
		k = 0;
	T m = (*it);
	while (it != v.end())
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
	typename set<T>::iterator it = v.begin();
	int n = 0,
		k = 0;
	T m = (*it);
	while (it != v.end())
	{
		if (m < *it)
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
	typename set<T>::iterator it = v.begin();
	int k=0,n = v.size();
	T temp2 = Min() + Max();
	while (k != n)
	{
		T temp =*it;
		temp = temp + temp2;
		v.erase(it++);
		v.insert(temp);
		k++;
	}
}