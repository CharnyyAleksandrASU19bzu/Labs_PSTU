#pragma once
#include "Object.h"
#include <iostream>
using namespace std;

class Vector
{
public:
	//����������� ��� ����������
	Vector();
public:
	//����������
	virtual ~Vector();

	//����������� � �����������
	Vector(int);

	//����������� �����������
	Vector(const Vector&);

	//���������� �������� � ������ 
	void Add(Object*);

	//���������� ����
	friend ostream& operator<<(ostream& out, const Vector&);
private:
	//��������� �� ������ ������� �������
	Object** beg;
	//������
	int size;
	//������� �������
	int cur;
};

