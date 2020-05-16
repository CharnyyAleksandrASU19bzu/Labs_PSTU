#include <iostream>
#include "Object.h"
#include "Person.h"
#include "Employee.h"
#include "Vector.h"
#include "Dialog.h"
using namespace std;

Vector::Vector()
{
}

Vector::Vector(int n)// ����������� � �����������
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}
Vector::~Vector()// �����������
{
	if (beg != 0)
		delete[] beg;
	beg = 0;
}
void Vector::Add()//���������� �������� � ������
{
	Object* p;
	// ����� �� �������� ���� ��������� �������
	cout << "1. �������" << endl;
	cout << "2. ���������" << endl;
	int y;
	cin >> y;
	if (y == 1)//���������� ������ �ar
	{
		Person* a = new (Person);
		a->Input();// ���� �������� ���������
		p = a;
		if (cur < size)
		{
			beg[cur] = p;//���������� � ������
			cur++;
		}
	}
	else
		if (y == 2) //���������� ������� ������ Lorry
		{
			Employee* b = new Employee;
			b->Input();
			p = b;
			if (cur < size)
			{
				beg[cur] = p;
				cur++;
			}
		}
		else
			return;
}
void Vector::Del()//�������� ��������� �� �������
{
	if (cur == 0)
		return;
	cur--;
}
void Vector::Show()//����� �������� �� �������
{
	if (cur == 0)
		cout << "Empty" << endl;
	Object** p = beg;//��������� �� ��������� Object
	for (int i = 0; i < cur; i++)
	{
		(*p)->Show();//����� ������ Show() 
		p++;// ����������� ��������� �� ��������� ������
	}
}

int Vector::operator() ()
{
	return cur;
}


void Vector::HandleEvent(TEvent& e, int G)
{
	if (e.what = evMessage)
	{
		Object** p = beg; // ��������� �� ��������� ���� Object
		int index = G - 1;
		for (int i = 0; i < cur; i++)
		{
			if (i == index)
				(*p)->HandleEvent(e);
			p++;
		}
	}
}