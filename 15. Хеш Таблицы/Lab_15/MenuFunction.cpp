#pragma once
#include "MenuFunctions.h"
#include "HashTable.h"
using namespace std;

void MakeTable(HashTable& table)  //Создание таблицы
{
	cout << "Введите размер таблицы для генирации: ";
	int size;
	cin >> size;
	while (cin.fail() || size <= 0)
	{
		if (cin.fail()) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Ошибка: некорректный ввод. Повторите попытку: ";
			cin >> size;
		}
		else {
			cout << "Ошибки: неккоректный размер таблицы. Повторите попытку: ";
			cin >> size;
		}
	}
	cin.get();
	vector<string> names = { "Oliver", "Jack", "Harry", "Jacob", "Charlie",
							"Thomas", "George", "Oscar", "James", "William"
	};

	vector<string> surnames = { "Smith", "Jones", "Taylor", "Davies", "Evans",
							   "Johnson", "Roberts", "Robinson", "Thompson", "Green"
	};

	vector<string> patronymics = { "Adamson", "Barson", "Hobson", "Wilson", "Fennel",
								  "Coleson", "Jackson", "Iveson", "Tennyson", "Garrison"
	};

	vector<string> account = { "11111110", "11111111", "11111112", "11111113", "11111114",
								"11111115", "11111116", "11111117", "11111118", "11111119",
								"11111120", "11111121", "11111121", "11111123", "11111124",
								"11111125", "11111126", "11111127", "11111128", "11111129",
								"11111130", "11111131", "11111132", "11111133", "11111134",
								"11111135", "11111136", "11111137", "11111138", "11111139",
								"11111140", "11111141", "11111142", "11111143", "11111144",
								"11111145", "11111146", "11111147", "11111148", "11111149",
								"11111150", "11111151", "11111152", "11111153", "11111154",
								"11111155", "11111156", "11111157", "11111158", "11111159",
								"11111160", "11111161", "11111162", "11111163", "11111164",
								"11111165", "11111166", "11111167", "11111168", "11111169",
								"11111170", "11111171", "11111172", "11111173", "11111174",
								"11111175", "11111176", "11111177", "11111178", "11111179"
	};
	srand(time(0));
	for (int i = 0; i < size; i++)// заполнение случайно сгенерироваными ФИО и Номером счета
	{
		table.Add({ account[rand() % account.size()],
					names[rand() % patronymics.size()]
					+ ' ' + patronymics[rand() % patronymics.size()]
					+ ' ' + surnames[rand() % surnames.size()],
				   (double)rand() / 1.315 });
	}
}

void Add(HashTable& table) //Добавить элемент в таблицу
{
	Hash tmp;
	cout << "Введите номер счета: ";
	getline(cin, tmp.account);
	cout << "Введите ФИО: ";
	getline(cin, tmp.name);
	while (cin.fail() < 0)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			cerr << "Ошибка: неккоректный ввод. Попробуйте снова: ";
			cin >> tmp.name;
		}
		else
		{
			cout << "Ошибка: неправельный номер счета. Попробуйте снова: ";
			cin >> tmp.name;
		}
	}
	cout << "Введите сумму: ";
	cin >> tmp.sum;
	while (cin.fail())
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			cerr << "Ошибка: неправельный ввод. Попробуйте снова: ";
			cin >> tmp.sum;
		}
	}
	cin.get();
	table.Add(tmp);
}

void Del(HashTable& table)//Удалить элемент из таблицы

{
	cout << "Введите номер счета: ";
	string account;
	getline(cin, account);
	table.Del(account);
}

void Find(HashTable& table)//Найти элемент в таблице
{
	cout << "Введите номер счета: ";
	string name;
	getline(cin, name);
	Hash tmp = table.Find(name);
	if (tmp.account != "empty")
		cout << "Номер счета: " << tmp.account
		<< endl << "ФИО: " << tmp.name
		<< endl << "Сумма: " << tmp.sum << endl;
	else
		cout << "Счет не найден" << endl;
	return;
}

void ChangeElement(HashTable& table)//изменить элемент в таблице
{
	cout << "Введите номер счета для изменения: ";
	string account;
	getline(cin, account);
	Hash tmp = table.Find(account);
	if (tmp.account != "empty")
	{
		cout << "Введите новое ФИО: ";
		string newName;
		cin >> newName;
		while (cin.fail())
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Ошибка: неккоректный ввод. Попробуйте снов: ";
				cin >> newName;
			}
			else
			{
				cout << "Ошибка: неккоректный ввод. Попробуйте снов: ";
				cin >> newName;
			}
		}
		cin.get();
		cout << "Введите новую сумму: ";
		double newSum;
		cin >> newSum;
		while (cin.fail())
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(100, '\n');
				cerr << "Ошибка: неккоректный ввод. Попробуйте снов: ";
				cin >> newSum;
			}
		}
		cin.get();
		table.ChangeElement(account, newName, newSum);
	}
	else
		return;
}

void CollisionsCount(HashTable& table)//Подсчет коллизий
{
	int count = table.CollisionsCount();
	cout << "Количество коллизий в таблице = " << count << endl;

}