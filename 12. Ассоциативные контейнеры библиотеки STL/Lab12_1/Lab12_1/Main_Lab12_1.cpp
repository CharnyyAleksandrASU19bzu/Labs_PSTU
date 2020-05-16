#include <iostream>
#include <set>
using namespace std;

typedef set<float>Tset;
Tset::iterator it;
Tset s;

Tset make_set(int n)
{
	Tset s;
	for (int i = 0; i < n; i++)
	{
		float a = rand() % 100 - 50;
		s.insert(a/3);//добавляет а в конец
	}
	return s;//возвращаем 
}
void print_set(Tset s)
{
	it = s.begin();
	for (it; it != s.end(); ++it)
		cout << *it << endl;
}
float Min(Tset s)
{
	it = s.begin();
	int n = 0,
		k = 0;
	float m = (*it);
	while (it != s.end())
	{
		if (m > * it)
		{
			m = (*it);
			n = k;
		}
		it++;
		k++;
	}
	cout << "Минимальный элемент : " <<m<< endl;
	return m;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int n;
	cout << "Введите размер : ";
	cin >> n;
	s = make_set(n);
	print_set(s);
	float min = Min(s);
	s.insert(min);
	print_set(s);
}