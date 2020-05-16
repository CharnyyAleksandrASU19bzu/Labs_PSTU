#include <iostream>
#include <list>
#include <algorithm>
#include "Time.h"
using namespace std;

typedef list <Time> List;
List l;
Time s;
List::iterator it;

struct Equal_s
{
	bool operator() (Time t)
	{
		return t == s;
	}

};

List make_list(int n)
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

void print_list(List l)
{
	it = l.begin();
	for (it; it != l.end(); ++it)
		cout << *it << endl;
	cout << endl;
}

List MinEnd()
{
	cout << "Добавим минимальный элемент в конец списка" << endl;
	List::iterator min;
	min=min_element(l.begin(), l.end());
	l.push_back(*min);
	return l;
}

List Del()
{
	Time temp;
	cout << "Удалим элемент" << endl;
	cout << "Удалить : " << endl;
	cin >> s;
	it = find_if(l.begin(), l.end(),Equal_s());
	l.erase(it);
	return l;
}

Time MinMaxSumm()
{
	cout << "Добавим минимальный и максимальный элементы ко всем элементам" << endl;
	List::iterator min;
	List::iterator max;
	min = min_element(l.begin(), l.end());
	max = max_element(l.begin(), l.end());
	s = *min + *max;
 	return s;
}


int main()
{
	setlocale(LC_ALL, "rus");
	int n;
	cout << "Введите размер :";
	cin >> n;
	make_list(n);
	print_list(l);
	MinEnd();
	print_list(l);
	Del();
	print_list(l);
	MinMaxSumm();
	for_each(l.begin(), l.end(), [](Time& t) { t = t + s; });
	print_list(l);
	//l.sort();
	//print_list(l);
}