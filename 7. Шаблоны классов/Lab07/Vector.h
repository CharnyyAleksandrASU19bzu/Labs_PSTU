#pragma once
#include <iostream>
using namespace std;

//�������� �������
template<class T>

class Vector {
public:
	//����������� �� ���������
	Vector()
	{
	}

	//����������� � �����������
	Vector(int s, T k)
	{
		size = s;
		data = new T[size];
		for (int i = 0; i < size; i++)
			data[i] = k;
	}

	//����������� �����������
	Vector(const Vector<T>& a)
	{
		size = a.size;
		data = new T[size];
		for (int i = 0; i < size; i++)
			data[i] = a.data[i];
	}

	//����������
	~Vector()
	{
		delete[]data;
		data = 0;
	}

	//�������� ������������
	Vector& operator=(const Vector<T>& a)
	{
		if (this == &a)return *this;
		size = a.size;
		if (data != 0) delete[]data;
		data = new T[size];
		for (int i = 0; i < size; i++)
			data[i] = a.data[i];
		return *this;
	}

	//�������� ������� �� �������
	T& operator[](int index)
	{
		if (index < size)
			return data[index];
		else
			cout << endl << "������! ������ ������ �������";
	}

	//�������� ��� ���������� ������� � �������
	Vector operator+(const Vector& k)
	{
		T t;
		Vector<T> temp(size,t);
		for (int i = 0; i < size; ++i)
			temp.data[i]= data[i] + k.data[i];
		return temp;
	}

	//�������� ��� ���������� ��������� � �������
	Vector operator+(const T k)
	{
		Vector<T> temp1(size, k);
		for (int i = 0; i < size; ++i)
			temp1.data[i] = data[i] + k;
		return temp1;
	}

	//��������, ������������ ����� �������
	operator int()const
	{
		return size;
	}

	//������������� �������� �����-������
	friend istream& operator>>(istream& in, Vector<T>& a)
	{
		for (int i = 0; i < a.size; ++i)
			in >> a.data[i];
		return in;
	}

	friend ostream& operator<<(ostream& out, Vector<T>& a)
	{
		for (int i = 0; i < a.size; ++i)
			out << a.data[i] << " ";
		return out;
	}


private:
	int size;// ������ �������
	T* data;//��������� �� ������������ ������ �������� �������
};