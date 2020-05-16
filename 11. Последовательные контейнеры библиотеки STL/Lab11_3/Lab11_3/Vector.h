#pragma once
#include <iostream>
#include <list>
using namespace std;

//�������� �������
template<class T>

class Vector
{
	list<T>l;
	int len;
public:
	//����������� �� ���������
	Vector();
	//����������� � �����������
	Vector(int s);
	//������
	void Print();
	
	T Min();//����������� �������
	T Max();//������������ ������
	void Summa();//�����
	//����������
	~Vector();
};



template<class T>
Vector<T>::Vector()//����������� �� ���������
{
	len = 0;
}

template<class T>
Vector<T>::Vector(int n)//����������� � �����������
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
void Vector<T>::Print()//������
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
Vector<T>::~Vector() //����������
{

}


template<class T>
T Vector<T>::Min() //����������� �������
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
T Vector<T>::Max() //������������ �������
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
void Vector<T>::Summa() //�����
{
	typename list<T>::iterator it = l.begin();
	for (it; it != l.end(); ++it)
	{
		*it = *it + Min() + Max();
	}
}