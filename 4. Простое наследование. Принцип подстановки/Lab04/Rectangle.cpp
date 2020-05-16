#include "Rectangle.h"

//����������� ��� ����������
Rectangle::Rectangle() :Pair()
{
}

//���������
Rectangle::~Rectangle( )
{
}

//����������� � �����������
Rectangle::Rectangle(int A, int B) :Pair(A, B)
{
}

//����������� �����������
Rectangle::Rectangle(const Rectangle& r)
{
	namber1 = r.namber1;
	namber2 = r.namber2;
}

//������������
int Rectangle::get_perimeter()
{
	return namber1*namber2;
}

int Rectangle::get_area()
{
	return namber1*2 + namber2*2;
}


//������� ������������
Rectangle& Rectangle::operator=(const Rectangle& r)
{
	if (&r == this)return *this;
	namber1 = r.namber1;
	namber2 = r.namber2;
	return *this;
}

//�������� �����
istream& operator>>(istream& in, Rectangle& r)
{
	cout <<endl<< "������� ������� � : "; 
	in >>r.namber1;
	cout <<endl<< "������� ������� b : "; 
	in >> r.namber2;
	return in;
}

//�������� ������
ostream& operator<<(ostream& out, const Rectangle& r)
{
	Rectangle temp = r;
	out << endl<< "C������ � : " << r.namber1;
	out << endl<< "������� � : " << r.namber2;
	out << endl << "������� �������������� : " << temp.get_area();
	out << endl << "�������� �������������� : " << temp.get_perimeter();
	out << endl;
	return out;
}