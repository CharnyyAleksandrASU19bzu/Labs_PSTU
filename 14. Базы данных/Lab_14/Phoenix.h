#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Phoenix
{
	int dayW;
	int tempW;
	bool del;

	string unitP;
	int profitP;
	int monthP;
	int yearP;

public:
	Phoenix()
	{
		unitP = ""; profitP = 0; yearP = 0; del = false;
	}
	Phoenix(string uP, int pP, int yP)
	{
		unitP = uP; profitP = pP; yearP = yP; del = false;
	}
	Phoenix(const Phoenix& t)
	{
		unitP = t.unitP; profitP = t.profitP; yearP = t.yearP; del = t.del;
	}

	~Phoenix()
	{
	}
	string get_unit()
	{
		return unitP;
	}
	int get_profit()
	{
		return profitP;
	}
	int get_year()
	{
		return yearP;
	}
	int get_del()
	{
		return del;
	}
	void set_unit(string uP)
	{
		unitP = uP;
	}
	void set_profit(int pP)
	{
		profitP = pP;
	}
	void set_year(int yP)
	{
		yearP = yP;
	}
	void set_del(bool dP)
	{
		del = dP;
	}

	// Перегруженные операции
	// Префиксные операции
	Phoenix& operator =(const Phoenix&);
	Phoenix& operator ++();

	// Постфиксные операции
	Phoenix operator +(const Phoenix&);
	Phoenix operator +(const int&);
	Phoenix operator /(const Phoenix&);
	Phoenix operator /(const int&);

	// Операция сравнения
	bool operator ==(const Phoenix&);
	bool operator !=(const Phoenix&);
	bool operator >(const Phoenix&);
	bool operator >(const int&);
	bool operator <(const Phoenix&);
	bool operator <(const int&);

	// Глобальные функции ввода-вывода
	friend istream& operator >>(istream& in, Phoenix& t);
	friend ostream& operator <<(ostream& out, const Phoenix& t);

	friend fstream& operator >>(fstream& fin, Phoenix& t);
	friend fstream& operator <<(fstream& fout, const Phoenix& t);
};