#include "Pair.h"

//����������� ��� ����������
Pair::Pair()
{
	number1 = 0;
	number2 = 0;
}

//����������
Pair::~Pair()
{
}

//����������� � �����������
Pair::Pair(int A, int B)
{
	number1 = A;
	number2 = B;
}

//����������� �����������
Pair::Pair(const Pair& t)
{
	number1 = t.number1;
	number2 = t.number2;
}

//���������
int Pair::Get_number1()
{
	return number1;
}
int Pair::Get_number2()
{
	return number2;
}

int Pair::Get_mult()
{
	return number1 * number2;
}

//������������
void Pair::Set_number1(int A)
{
	number1 = A;
}
void Pair::Set_number2(int B)
{
	number2 = B;
}


//���������� �������� ������������
Pair& Pair::operator=(const Pair& p)
{
	if (&p == this)return *this;
	number1 = p.number1;
	number2 = p.number2;
	return *this;
}


//���������� ������� ��� �����
istream& operator>>(istream& in, Pair& p)
{
	cout << "������ �����: ";
	in >> p.number1;
	cout << "������ �����: ";
	in >> p.number2;
	return in;
}

//���������� ������� ��� ������
ostream& operator<<(ostream& out, const Pair& p)
{
	Pair temp = p;
	out << endl << "���� ������ �����: " << p.number1;
	out << endl << "���� ������ �����: " << p.number2;
	out << endl << "������������ 1 � 2 �����: " << temp.Get_mult();
	out << endl;
	return out;
}

void Pair::Show()
{
	cout << endl << "���� ������ �����: " << number1;
	cout << endl << "���� ������ �����: " << number2;
	cout << endl << "������������ 1 � 2 �����: " << Get_mult();
	cout << endl;
}