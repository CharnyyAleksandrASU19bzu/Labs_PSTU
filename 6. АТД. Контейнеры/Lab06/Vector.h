#pragma once
#include <iostream>

using namespace std;

class Iterator
{
	//������������� �����
	friend class Vector;
public:
	//����������� ��� ����������
	Iterator()
	{
		elem = 0;
	}

	//����������� �����������
	Iterator(const Iterator& it)
	{
		elem = it.elem;
	}

	//������������� �������� ���������
	bool operator==(const Iterator& it)
	{
		return elem == it.elem;
	}
	bool operator!=(const Iterator& it)
	{
		return elem != it.elem;
	};

	//������������� �������� ���������
	void operator++(int)
	{
		++elem;
	};

	//������������� �������� ���������
	void operator--(int)
	{
		--elem;
	}

	void operator +(const int n) 
	{ 
		elem += n; 
	}

	//������������� �������� �������������
	int& operator *() const
	{
		return*elem;
	}
private:
	int* elem;//��������� �� ������� ���� int

};

class Vector {
public:
	//����������� ��� ����������
	Vector();

	//����������� � �����������
	Vector(int s, int k = 0);

	//����������� �����������
	Vector(const Vector& a);

	//����������
	~Vector();

	//�������� ������������
	Vector& operator=(const Vector& a);

	//�������� ������� �� �������
	int& operator[](int index);

	//�������� ��� ���������� �������
	Vector operator+(const Vector& k);

	//��������, ������������ ����� �������
	operator int()const;

	//������������� �������� �����-������
	friend ostream& operator<<(ostream& out, Vector& a);
	friend istream& operator>>(istream& in, Vector& a);

	Iterator first()
	{
		return beg;
	}//���������� ��������� �� ������ �������
	Iterator last()
	{
		return end;
	}//���������� ��������� �� ������� ��������� ��

private:
	int size;
	int* data;
	Iterator beg;//��������� �� ������ ������� �������
	Iterator end;//��������� �� ������� ��������� �� ���������
};