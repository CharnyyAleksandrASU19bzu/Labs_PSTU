#include "Time.h"
#include <iostream>
using namespace std;

Time::Time()
{
	min = 0;
	sec = 0;
}

Time::Time(int m, int s)
{
	min = m;
	sec = s;
}

Time::Time(const Time& t)
{
	min = t.min;
	sec = t.sec;
}

Time::~Time()
{
}

int Time::get_min()
{
	return min;
}
int Time::get_sec()
{
	return sec;
}

void Time::set_min(int m)
{
	min = m;
}
void Time::set_sec(int s)
{
	sec = s;
}

Time& Time::operator=(const Time& t)
{
	if (&t == this)
		return *this;
	min = t.min;
	sec = t.sec;
	return *this;
}
Time Time::operator+(const Time& t) const
{
	int temp1 = min * 60 + sec;
	int temp2 = t.min * 60 + t.sec;
	Time p;
	p.min = (temp1 + temp2) / 60;
	p.sec = (temp1 + temp2) % 60;
	return p;
}
Time Time::operator/(const Time& t)
{
	int temp1 = min * 60 + sec;
	int temp2 = t.min * 60 + t.sec;
	Time p;
	p.min = (temp1 / temp2) / 60;
	p.sec = (temp1 / temp2) % 60;
	return p;
}
Time Time::operator/(const int& t)
{
	int temp1 = min * 60 + sec;
	Time p;
	p.min = (temp1 / t) / 60;
	p.sec = (temp1 / t) % 60;
	return p;
}
bool Time::operator>(const Time& t) const
{
	if (min > t.min)
		return 1;
	if (min == t.min && sec > t.sec)
		return 1;
	return 0;
}
bool Time::operator<(const Time& t) const
{
	if (min < t.min)
		return 1;
	if (min == t.min && sec < t.sec)
		return 1;
	return 0;
}

bool Time::operator!=(const Time& t) const
{
	if (min != t.min && sec != t.sec)
		return 1;
	return 0;
}

bool Time::operator==(Time& t)
{
	if (min == t.min && sec == t.sec)
		return 1;
	return 0;
}

istream& operator>>(istream& in, Time& t)
{
	cout << "min :";
	in >> t.min;
	cout << "sec :";
	in >> t.sec;
	return in;
}
ostream& operator<<(ostream& out, const Time& t)
{
	return (out << t.min << " : " << t.sec);
}