#pragma once
#include <iostream>
using namespace std;

class Time
{
public:
	Time();
	Time(int, int);
	Time(const Time&);
	virtual ~Time();
	Time& operator=(const Time&);

	//операция +
	Time operator+(Time k);

	//Глобальный ввод и ввывод
	friend istream& operator>>(istream& in, Time&);
	friend ostream& operator<<(ostream& out, const Time&);
private:
	int min, sec;
};