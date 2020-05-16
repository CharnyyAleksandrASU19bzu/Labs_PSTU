#pragma once
#include <iostream>
using namespace std;

class Time
{
	int min, sec;

public:
	Time();
	Time(int m, int s);
	Time(const Time& t);
	~Time();
	int get_min();
	int get_sec();
	void set_min(int m);
	void set_sec(int s);

	//перегрузка
	Time operator -(const Time&);
	bool operator!=(const Time&);

	//глобальный ввод/ввывод
	friend istream& operator>>(istream& in, Time& t);
	friend ostream& operator<<(ostream& out, const Time& t);
};