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

	//перегруженые операции
	Time& operator=(const Time&);
	Time operator+(const Time&) const;
	Time operator/(const Time&);
	Time operator/(const int&);
	bool operator>(const Time&)const;
	bool operator<(const Time&)const;
	bool operator!=(Time&);

	friend istream& operator>>(istream& in, Time& t);
	friend ostream& operator<<(ostream& out, const Time& t);
};