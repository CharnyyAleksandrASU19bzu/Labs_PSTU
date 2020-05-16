#include "Vector.h"
#include "Error.h"
#include <iostream>
using namespace std;

//конструктор без параметров
Vector::Vector()
{
	size = 0;
	beg = 0;
}

//конструктор с параметрами
Vector::Vector(int s)
{
	if (s > MAX_SIZE) throw MaxSizeError();
	size = s;
	beg = new int[s];
	for (int i = 0; i < size; i++)
		beg[i] = 0;
}

//конструктор с параметрми
Vector::Vector(int s, int* mas)
{
	if (s > MAX_SIZE) throw MaxSizeError();
	size = s;
	beg = new int[size];
	for (int i = 0; i < size; i++)
		beg[i] = mas[i];
}

//конструктор копирования
Vector::Vector(const Vector& v)
{
	size = v.size;
	beg = new int[size];
	for (int i = 0; i < size; i++)
		beg[i] = v.beg[i];
}

//деструктор
Vector::~Vector()
{
	if (beg != 0)
		delete[]beg;
}

//опирация присвоения
const Vector& Vector::operator=(const Vector& v)
{
	if (this == &v) return *this;
	if (beg != 0) delete beg;
	size = v.size;
	beg = new int[size];
	for (int i = 0; i < v.size; i++)
		beg[i] = v.beg[i];
	return *this;
}

//опирация доступа по индексу
int Vector::operator[](int i)
{
	if (i < 0) throw IndexError1();
	if (i >= size) throw IndexError2();
	return beg[i];
}


//операция получения длины вектора
Vector::operator int()const
{
	if (size > MAX_SIZE) throw MaxSizeError();
	return size;
}

//операция добавления n элементов
Vector Vector::operator+(const int n)
{
	if (size == 20) throw MaxSizeError();

	int t = size;
	size += n;
	Vector temp(size, beg);
	delete[]beg;
	beg = new int[size];
	for (int i = 0; i < size; i++)
		beg[i] = temp.beg[i];

	for (int i = t; i < size; i++)
		beg[i] = 1;
	return*this;
}
//операция удаление n элементов
Vector Vector::operator-(const int n)
{
	if (size == 0) throw EmptySizeError();
	if (size == 1)
	{
		size = 0;
		delete[]beg;
		beg = 0;
		return*this;
	};
	size -= n;
	Vector temp(size, beg);
	delete[]beg;
	beg = new int[size];
	for (int i = 0; i < size; i++)
		beg[i] = temp.beg[i];
	return*this;
}

//ввод-вывод
ostream& operator << (ostream& out, const Vector& v)
{
	if (v.size == 0) out << "Empty" << endl;
	else
	{
		for (int i = 0; i < v.size; i++)
			out << v.beg[i] << " ";
		out << endl;
	}
	return out;
}
istream& operator>>(istream& in, Vector& v)
{
	for (int i = 0; i < v.size; i++)
	{
		cout << ">";
		in >> v.beg[i];
	}
	return in;
}