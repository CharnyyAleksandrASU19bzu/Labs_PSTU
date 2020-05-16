#include "Pair.h"

//����������� ��� ����������
Pair::Pair()
{
	namber1 = 0;
	namber2 = 0;
}

//����������
Pair::~Pair()
{
}

//����������� � �����������
Pair::Pair(int A, int B)
{
	namber1 = A;
	namber2 = B;
}

//����������� �����������
Pair::Pair(const Pair& t)
{
	namber1 = t.namber1;
	namber2 = t.namber2;
}

//���������
int Pair::Get_namber1()
{
	return namber1;
}
int Pair::Get_namber2()
{
	return namber2;
}

int Pair::Get_mult()
{
	return namber1*namber2;
}

//������������
void Pair::Set_namber1(int A)
{
	namber1 = A;
}
void Pair::Set_namber2(int B)
{
	namber2 = B;
}


//���������� �������� ������������
Pair& Pair::operator=(const Pair& p)
{
	if (&p == this)return *this;
	namber1 = p.namber1;
	namber2 = p.namber2;
	return *this;
}


//���������� ������� ��� �����
istream& operator>>(istream& in, Pair& p)
{
	cout <<"������ �����: " << endl;
	in >> p.namber1;
	cout <<"������ �����: " << endl;
	in >> p.namber2;
	return in;
}

//���������� ������� ��� ������
ostream& operator<<(ostream& out, const Pair& p)
{
	Pair temp = p;
	out << endl<<"���� ������ �����: " << p.namber1;
	out << endl<<"���� ������ �����: " << p.namber2;
	out << endl << "������������ 1 � 2 �����: " << temp.Get_mult();
	out << endl;
	return out;
}
