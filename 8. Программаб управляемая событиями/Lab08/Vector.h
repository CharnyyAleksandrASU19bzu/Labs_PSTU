#pragma once
#include <iostream>
#include "Object.h"
using namespace std;

class Vector
{
public:
	//����������� ��� ����������
	Vector(); 
public:
	// ����������� � �����������
	Vector(int);

	// �����������
	~Vector();

	void Add();//���������� �������� � ������
	void Del();
	void Show();//����� �������� �� �������
	int operator() ();

	void HandleEvent(TEvent& e, int);

protected:
	Object** beg;
	int size;
	int cur;
};