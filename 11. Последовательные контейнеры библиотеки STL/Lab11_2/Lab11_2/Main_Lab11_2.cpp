#include <iostream>
#include <list>
#include <cstdlib>
#include "Time.h"
using namespace std;

typedef list <Time> List;
List l;
List::iterator it;

List make_vector(int n)
{
	for (int i = 0; i < n; i++)
	{
		int m = rand() % 60;
		int s = rand() % 60;
		Time a(m, s);
		l.push_back(a);
	}
	return l;
}

void print_vector(List l)
{
	it = l.begin();
	for (it; it != l.end(); ++it)
		cout << *it<<endl;
	cout << endl;
}

List Del ()
{
	Time t;
	int n = 0;
	cout << "”далить : " << endl;
	cin >> t;
	cout << endl;
	it = l.begin();
	while (*it!=t)
	{
		if (it == l.end())
			return l;
		it++;
	}
  	l.erase(it);
	return l;
}

int main()
{
	setlocale(LC_ALL, "rus");
		int n;
		cout << "¬ведите размер :";
		cin >> n;
		make_vector(n);
		print_vector(l);
		l=Del();
		print_vector(l);
}