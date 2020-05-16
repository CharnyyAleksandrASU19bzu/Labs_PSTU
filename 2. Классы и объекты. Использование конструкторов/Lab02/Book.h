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
	// ����������� ��� ����������
	Book();
	//����������� � �����������
	Book(string, string, int);
	// ����������� �����������
	Book(const Book&);
	//����������
	~Book();
	//���������
	string get_name();
	string get_autor();
	int get_year();
	
	//������������
	void set_name(string);
	void set_autor(string);
	void set_year(int);
	void show(); //prosmotr atributov
};