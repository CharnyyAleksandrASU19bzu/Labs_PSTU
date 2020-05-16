#include <iostream>
#include <set>
#include <cstdlib>
#include "Time.h"
using namespace std;

typedef set <Time> Tset;
Tset t;
Tset::iterator it;

Tset make_set(int n)
{
	Tset t;
	for (int i = 0; i < 5; i++)
	{
			int m = rand() % 60;
			int s = rand() % 60;
			Time a(m, s);
			t.insert(a);
	}
	return t;//возвращаем 
}

void print_set(Tset t)
{
	it = t.begin();
	for (it; it != t.end(); ++it)
		cout << *it << endl;
}


void Del ()
{
	Time k;
	cout << "”далить : " << endl;
	cin >> k;
	cout << endl;
	it = t.begin();

	while (*it != k)
	{
		it++;
		if (it == t.end()) return;
	}

	t.erase(it);	
}

int main()
{
	setlocale(LC_ALL, "rus");
	int n;
	cout << "¬ведите размер :";
	cin >> n;
	t = make_set(n);
	print_set(t);
	Del();
	print_set(t);
}