#pragma once
#include "Pair.h"

class Rectangle : public Pair
{
public:
	//����������� ��� ����������
	Rectangle();
public:
	//����������
	~Rectangle( );

	//����������� � �����������
	Rectangle(int, int);

	//����������� �����������
	Rectangle(const Rectangle&);

	//���������
	int get_perimeter();
	int get_area();

	//�������� ������������
	Rectangle& operator=(const Rectangle&);

	//�������� �����/������
	friend istream& operator>>(istream& in, Rectangle& r);
	friend ostream& operator<<(ostream& out, const Rectangle& r);
};