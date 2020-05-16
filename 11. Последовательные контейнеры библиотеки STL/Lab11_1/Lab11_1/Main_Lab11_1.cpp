#include <iostream>
#include <list>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef list <float> List; //опеределяем тип для работы

//функция формирования
List make_list(float n)
{
	List l;
	for (int i = 0; i < n; i++)
	{
		float a = rand() % 100 - 50;
		l.push_back(a);//добавляет а в конец
	}
	return l;//возвращаем 
}

//функция для печати
void print_list(List l)
{
	List::iterator i = l.begin();
	for (i; i != l.end(); ++i)
	{
		if (!l.empty())
			cout << *i << ' ';
	}
	cout << endl;
}

float Min(List l) //минимальный элемент
{
	List::iterator i = l.begin();
	int n = 0,
		k = 0;
	int m = (*i);
	while (i != l.end())
	{
		if (m > * i)
		{
			m = (*i);
			n = k;
		}
		i++;
		k++;
	}
	return m;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	list <float> l; //список
	list <float>::iterator i;
	int n;
	cout << "Введите размер списка : ";
	cin >> n;
	l = make_list(n); //формирование листа
	print_list(l);	//печать листа
	l.push_back(Min(l));
	print_list(l);
}