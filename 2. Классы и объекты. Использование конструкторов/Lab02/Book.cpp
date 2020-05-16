#include "Book.h"
#include <iostream>
#include <string>
using namespace std;

// ����������� ��� ����������
Book::Book()
{
	name = "";
	autor = "";
	year = 0;
}

//����������� � �����������
Book::Book(string N, string A, int Y)
{
	name = N;
	autor = A;
	year = Y;
}

// ����������� �����������
Book::Book(const Book& b)
{
	name = b.name;
	autor = b.autor;
	year = b.year;
}

//����������
Book::~Book()
{
}

//���������
string Book::get_name()
{
	return name;
}
string Book::get_autor()
{
	return autor;
}
int Book::get_year()
{
	return year;
}

//m������������
void Book::set_name(string N)
{
	name = N;
}
void Book::set_autor(string A)
{
	autor = A;
}
void Book::set_year(int Y)
{
	year = Y;
}

//�����
void Book::show()
{
	cout << "�������� ����� :" << name << endl;
	cout << "��� ������ ����� :" << autor << endl;
	cout << "��� ������� :" << year << endl<<endl;
}
