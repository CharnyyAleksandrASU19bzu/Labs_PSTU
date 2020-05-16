#include "Book.h"
#include <iostream>
#include <string>
using namespace std;

//������� ������������ ������ ��� ���������
Book make_book()
{
	string s;
	string i;
	int d;
	cout << "������� �������� ����� : ";
	getline(cin,s);
	cout << "������� ��� ������ ����� : ";
	getline(cin, i);
	cout << "������� ��� ������� ����� : ";
	cin >> d;
	Book b(s, i, d);
	return b;
}

//������� ������������ ������ ��� ��������
void print_book(Book b)
{
	b.show();
}

int main()
{
	setlocale(LC_ALL, "Rus");
	Book b1;
	cout << "����������� ��� ����������" << endl;
	b1.show();

	cout << "����������� � �����������" << endl;
	Book b2("����� �1", "����� �1", 1999);
	b2.show();

	cout << "����������� �����������" << endl;
	Book b3 = b2;
	b3.set_name("����� �2");
	b3.set_autor("����� �2");
	b3.set_year(1888);
	print_book(b3);
	Book b;
	b = make_book();
	cout << endl;
	b.show();
}