#include <iostream>
#include "Time.h"
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

typedef queue<Time>Qt;
typedef list<Time> List;
Qt q;
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

Qt make_queue(int n)
{
	for (int i = 0; i < n; i++)
	{
		int m = rand() % 60;
		int s = rand() % 60;
		Time a(m, s);
		q.push(a);
	}
	return q;
}

List copy_queue_to_list()
{
	while (!q.empty())
	{
		l.push_back(q.front());
		q.pop();
	}
	return l;
}

Qt copy_list_to_queue()
{
	it = l.begin();
	for (it; it != l.end(); it++)
	{
 		q.push(*it);
	}
	l.clear();
	return q;
}

void print_queue()
{ 
	while (!q.empty())
	{
		Time val = q.front();
		l.push_back(q.front());
		q.pop();
		cout << val << endl;
	}
	cout << endl;
}

Qt MinEnd()
{
	l = copy_queue_to_list();
	cout << "Добавим минимальный элемент в конец списка" << endl;
	it = min_element(l.begin(), l.end());
	l.push_back(*it);
	q = copy_list_to_queue();
	return q;
}
Qt Del()
{
	l = copy_queue_to_list();
	cout << "Удалим элемент" << endl;
	cout << "Удалить : " << endl;
	cin >> s;
	it = find_if(l.begin(), l.end(), Equal_s());
	l.erase(it);
	q = copy_list_to_queue();
	return q;
}

Time MinMaxSumm()
{
	l = copy_queue_to_list();
	cout << "Добавим минимальный и максимальный элементы ко всем элементам" << endl;
	List::iterator min;
	List::iterator max;
	min = min_element(l.begin(), l.end());
	max = max_element(l.begin(), l.end());
	s = *min + *max;
	q = copy_list_to_queue();
	return s;
}

int main()
{
	setlocale(LC_ALL, "rus");
	
	int n;
	cout << "Введите размер :";
	cin >> n;
	make_queue(n);
	print_queue();
	MinEnd();
	print_queue();
	Del();
	print_queue();
	MinMaxSumm();
	l = copy_queue_to_list();
	for_each(l.begin(), l.end(), [](Time& t) { t = t + s; });
	l.sort();
	q = copy_list_to_queue();
	print_queue();

}