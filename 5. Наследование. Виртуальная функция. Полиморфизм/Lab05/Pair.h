#pragma once
#include "Object.h"
#include <iostream>
using namespace std;

class Pair:	
	public Object
{
public:
	//����������� ��� ����������
	Pair();
public:
	//����������
	virtual ~Pair();

	//������� ��� ��������� � ������� ���������
	void Show();

	//���������� � �����������
	Pair(int, int);

	//����������� �����������
	Pair(const Pair&);

	//���������
	int Get_number1();
	int Get_number2();
	int Get_mult();

	//������������
	void Set_number1(int);
	void Set_number2(int);

	//���������� �������� ������������
	Pair& operator=(const Pair&);

	//���������� ���������-������� �����-������
	friend istream& operator>>(istream& in, Pair& p);
	friend ostream& operator<<(ostream& out, const Pair& p);

protected:
	int number1;
	int number2;
};