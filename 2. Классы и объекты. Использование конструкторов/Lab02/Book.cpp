#include "Book.h"
#include <iostream>
#include <string>
using namespace std;

// конструктор без параметров
Book::Book()
{
	name = "";
	autor = "";
	year = 0;
}

//конструктор с параметрами
Book::Book(string N, string A, int Y)
{
	name = N;
	autor = A;
	year = Y;
}

// конструктор копирования
Book::Book(const Book& b)
{
	name = b.name;
	autor = b.autor;
	year = b.year;
}

//дестректор
Book::~Book()
{
}

//селекторы
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

//mмодификаторы
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

//Вывод
void Book::show()
{
	cout << "Название книги :" << name << endl;
	cout << "Имя автора книги :" << autor << endl;
	cout << "Год издания :" << year << endl<<endl;
}
