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
	int get_min() const;
	int get_sec() const;
	void set_min(int m);
	void set_sec(int s);

	//перегруженые операции
	Time& operator=(const Time&);
	Time operator+(const Time&);
	Time operator/(const Time&);
	Time operator/(const int&);
	bool operator>(const Time&) const;
	bool operator<(const Time&) const;
	bool operator!=(Time&) const;

	//global function IO
	friend istream& operator>>(istream& in, Time& t);
	friend ostream& operator<<(ostream& out, const Time& t);
};