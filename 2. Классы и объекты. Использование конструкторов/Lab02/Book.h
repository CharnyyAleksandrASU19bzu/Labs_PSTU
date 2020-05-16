#pragma once
#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
	string name;
	string autor;
	int year;
public:
	// конструктор без параметров
	Book();
	//конструктор с параметрами
	Book(string, string, int);
	// конструктор копирования
	Book(const Book&);
	//дестректор
	~Book();
	//селекторы
	string get_name();
	string get_autor();
	int get_year();
	
	//модификаторы
	void set_name(string);
	void set_autor(string);
	void set_year(int);
	void show(); //prosmotr atributov
};