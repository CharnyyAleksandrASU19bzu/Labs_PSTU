#pragma once
#include <string>
#include <iostream>
using namespace std;
class Pair
{
public:
	//����������� ��� ����������
	Pair();
public:
	//����������
	virtual ~Pair();

	//���������� � �����������
	Pair(int, int);
	
	//����������� �����������
	Pair(const Pair&);
	
	//���������
	int Get_namber1();
	int Get_namber2();
	int Get_mult();

	//������������
	void Set_namber1(int);
	void Set_namber2(int);
	
	//���������� �������� ������������
	Pair& operator=(const Pair&);

	//���������� ���������-������� �����-������
	friend istream& operator>>(istream& in, Pair& p);
	friend ostream& operator<<(ostream& out, const Pair& p);

protected:
	int namber1;
	int namber2;
};