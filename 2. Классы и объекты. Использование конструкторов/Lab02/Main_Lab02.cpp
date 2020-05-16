#include "Book.h"
#include <iostream>
#include <string>
using namespace std;

//функция возвращающая объект как результат
Book make_book()
{
	string s;
	string i;
	int d;
	cout << "Введите название книги : ";
	getline(cin,s);
	cout << "Введите имя автора книги : ";
	getline(cin, i);
	cout << "Введите год издания книги : ";
	cin >> d;
	Book b(s, i, d);
	return b;
}

//функция возвращающая объект как параметр
void print_book(Book b)
{
	b.show();
}

int main()
{
	setlocale(LC_ALL, "Rus");
	Book b1;
	cout << "Конструктор без параметров" << endl;
	b1.show();

	cout << "Конструктор с параметрами" << endl;
	Book b2("Книга №1", "Автор №1", 1999);
	b2.show();

	cout << "Конструктор копирования" << endl;
	Book b3 = b2;
	b3.set_name("Книга №2");
	b3.set_autor("Автор №2");
	b3.set_year(1888);
	print_book(b3);
	Book b;
	b = make_book();
	cout << endl;
	b.show();
}