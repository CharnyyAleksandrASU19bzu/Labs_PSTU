#include "Vector.h"
#include "Error.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	try
	{
		int v, s, i, n;
		cout << "Введите размер вектора" << endl;
		cin >> v;
		Vector x(v);
		Vector y;
		s = x;
		cout << "Вектор" << endl << x << endl << "Размер вектора: " << s << endl;
		cout << "Введите индекс для вывода" << endl;
		cin >> i;
		cout << x[i] << endl;
		cout << "Удалить количество элементов из вектора :" << endl;
		cin >> n;
		x - n;
		cout << x;
		cout << "Добавить количество элементов в вектор :" << endl;
		cin >> n;
		x + n;
		cout << x;
	}
	catch (Error & e)
	{
		e.what();
	}
}