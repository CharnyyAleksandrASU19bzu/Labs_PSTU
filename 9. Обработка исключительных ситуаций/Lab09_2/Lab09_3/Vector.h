#pragma once
#include <iostream>
using namespace std;
const int MAX_SIZE = 20;

class Vector
{
public:
	Vector();
	Vector(int s);
	Vector(int s, int* mas);
	Vector(const Vector& v);

	~Vector();

	const Vector& operator =(const Vector& v); //операция присвоения

	int operator [](int i); //операция доступа по индексу

	operator int()const; //операция длины вектора

	Vector operator +(const int n);

	Vector operator -(const int n);

	friend ostream& operator<<(ostream& out, const Vector& v);
	friend istream& operator>>(istream& in, Vector& v);
protected:
	int size;
	int* beg;
};