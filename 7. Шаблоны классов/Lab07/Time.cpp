#include "Time.h"
#include <iostream>
using namespace std;

Time::Time()
{
	min = sec = 0;
}

Time::Time(int M, int S)
{
	min = M;
	sec = S;
}

Time::~Time()
{
}

Time::Time(const Time& t)
{
	min = t.min;
	sec = t.sec;
}

Time& Time::operator=(const Time& t)

{
	if (&t == this) return *this;
	min = t.min;
	sec = t.sec;
	return *this;
}

Time Time::operator+(Time k)
{
	int t = min * 60 + sec;
	int kt = k.min * 60 + k.sec;
	t = t + kt;
	Time temp(t / 60, t % 60);
	return temp;
}

//over global function-operation input
istream& operator>>(istream& in, Time& t)
{
	cout << "min :";
	in >> t.min;
	cout << "sec :";
	in >> t.sec;
	return in;
}

//over global function-operation output

ostream& operator<<(ostream& out, const Time& t)
{
	return (out << t.min << " : " << t.sec << endl);
}