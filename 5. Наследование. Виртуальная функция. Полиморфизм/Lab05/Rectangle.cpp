#include "Rectangle.h"

//����������� ��� ����������
Rectangle::Rectangle() :Pair()
{
}

//���������
Rectangle::~Rectangle()
{
}

//����������� � �����������
Rectangle::Rectangle(int A, int B) :Pair(A, B)
{
}

//����������� �����������
Rectangle::Rectangle(const Rectangle& r)
{
	number1 = r.number1;
	number2 = r.number2;
}

//��������
int Rectangle::get_perimeter()
{
	return number1 * number2;
}
//�������
int Rectangle::get_area()
{
	return number1 * 2 + number2 * 2;
}


//������� ������������
Rectangle& Rectangle::operator=(const Rectangle& r)
{
	if (&r == this)return *this;
	number1 = r.number1;
	number2 = r.number2;
	return *this;
}
//�������� �����
istream& operator>>(istream& in, Rectangle& r)
{
	cout << endl << "������� ������� � : ";
	in >> r.number1;
	cout << "������� ������� b : ";
	in >> r.number2;
	return in;
}

//�������� ������
ostream& operator<<(ostream& out, const Rectangle& r)
{
	Rectangle temp = r;
	out << endl << "C������ � : " << r.number1;
	out << endl << "������� � : " << r.number2;
	out << endl << "������� �������������� : " << temp.get_area();
	out << endl << "�������� �������������� : " << temp.get_perimeter();
	out << endl;
	return out;
}

void Rectangle::Show()
{
	cout << endl << "C������ � : " << number1;
	cout << endl << "������� � : " << number2;
	cout << endl << "������� �������������� : " << get_area();
	cout << endl << "�������� �������������� : " <<get_perimeter();
	cout << endl;
}