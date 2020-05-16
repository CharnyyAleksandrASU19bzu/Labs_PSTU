#pragma once
#include <string>
#include <iostream>
using namespace std;
class Pair
{
public:
	//конструктор без параметров
	Pair();
public:
	//деструктор
	virtual ~Pair();

	//констрктор с параметрами
	Pair(int, int);
	
	//конструктор копирования
	Pair(const Pair&);
	
	//селекторы
	int Get_namber1();
	int Get_namber2();
	int Get_mult();

	//модификаторы
	void Set_namber1(int);
	void Set_namber2(int);
	
	//перегрузка операции присваивания
	Pair& operator=(const Pair&);

	//глобальные операторы-функции ввода-вывода
	friend istream& operator>>(istream& in, Pair& p);
	friend ostream& operator<<(ostream& out, const Pair& p);

protected:
	int namber1;
	int namber2;
};