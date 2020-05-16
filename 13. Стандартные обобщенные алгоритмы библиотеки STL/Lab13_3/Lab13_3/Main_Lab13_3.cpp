#include <iostream>
#include "Time.h"
#include <set>
#include <algorithm>
using namespace std;

typedef multiset <Time> TSet;
TSet::iterator it;
TSet S;
Time s;

struct Equal_s
{
	bool operator() (Time t)
	{
		return t == s;
	}

};

TSet make_mset(int n)
{
	for (int i = 0; i < n; i++)
	{
		int m = rand() % 60;
		int s = rand() % 60;
		Time a(m, s);
		S.insert(a);//добавляет а в конец
	}
	return S;//возвращаем 
}


void print_mset()
{ 
	it = S.begin();
	for (it; it != S.end(); ++it)
		cout << *it << endl;
	cout << endl;
}

TSet MinEnd()
{
	cout << "Добавим минимальный элемент в конец списка" << endl;
	it = min_element(S.begin(), S.end());
	S.insert(*it);
	return S;
}

TSet Del()
{
	cout << "Удалим элемент" << endl;
	cout << "Удалить : " << endl;
	cin >> s;
	it = find_if(S.begin(), S.end(), Equal_s());
	S.erase(it);
	return S;
}

TSet MinMaxSumm()
{
	cout << "Добавим минимальный и максимальный элементы ко всем элементам" << endl;
	TSet::iterator min;
	TSet::iterator max;
	min = min_element(S.begin(), S.end());
	max = max_element(S.begin(), S.end());
	s = *min + *max;
	int k = 0, n = S.size();
	it = S.begin();
	while (k != n)
	{
		Time temp = *it;
		temp = temp + s;
		S.erase(it++);
		S.insert(temp);
		k++;
	}
	return S;
}

int main()
{
	setlocale(LC_ALL, "rus");
	
	int n;
	cout << "Введите размер :";
	cin >> n;
	make_mset(n);
	print_mset();
	MinEnd();
	print_mset();
	Del();
	print_mset();
	MinMaxSumm();
	print_mset();

}