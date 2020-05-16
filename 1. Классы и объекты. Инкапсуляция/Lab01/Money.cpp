#include"Money.h"
#include <iostream>
using namespace std;

//метод дл€ инициализаци€ полей структуры
void Money::Init(int F, int S)
{
	bool flag=1;
	const int K = 9;
	int allowed[K] = { 1,2,5,10,50,100,500,1000,5000 };
		while (flag)
	{
		first=F;
		for (int i = 0; i < K; i++)
		{
			if (first == allowed[i])
			{
				second=S;
				return;
			}
		}
		cout << "Ќеправельный наминал!" << endl;
		flag = 0;
	}
}

//метод дл€ чтиение полей структуры
void Money::Read()
{
	const int K = 9;
	int allowed[K] = { 1,2,5,10,50,100,500,1000,5000 };
	while (true)
	{
		cout << "¬ведите денежный наминал:";
		cin >> first;
		for (int i = 0; i < K; i++)
		{
			if (first == allowed[i])
			{
				cout << "¬ведите количество:";
				cin >> second;
				cout << endl;
				return;
			}
		}
		cout << "Ќеправельный наминал!" << endl;
	}
}

//метод дл€ вывод полей структуры
void Money::Show()
{
	cout << endl << "ƒенежный номинал = " << first;
	cout << endl << " оличество = " << second;
	cout << endl;
}

//метод дл€ вычисление суммы
int Money::Summa()
{
	return first * second;
}