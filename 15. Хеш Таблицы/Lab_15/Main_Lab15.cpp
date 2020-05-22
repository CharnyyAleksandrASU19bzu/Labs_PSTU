#include <iostream>
#include <vector>
#include <string>
#include "HashTable.h"
#include "MenuFunctions.h"

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "1. Сгенерировать таблицу" << endl
		<< "2. Добавить элемент в таблицу" << endl
		<< "3. Удалить элемент из таблицы" << endl
		<< "4. Найти элемент в таблице" << endl
		<< "5. Поменять данные элемента в таблице" << endl
		<< "6. Вывести таблицу в печать" << endl
		<< "7. Показать количество коллизий" << endl
		<< "0. Выход" << endl << endl;

	HashTable mainTable;
	int n;
	do
	{
		cout << "Выберете действие: ";
		cin >> n;
		while (cin.fail() || n < 0 || n > 7)
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Ошибка: ошибка ввода. Попробуйте снова: ";
				cin >> n;
			}
			else
			{
				cout << "Ошибка:неправельнй номер, введите: 0-7";
				cin >> n;
			}
		}
		cin.get();

		switch (n)
		{
		case 1:
			MakeTable(mainTable);
			break;
		case 2:
			Add(mainTable);
			break;
		case 3:
			Del(mainTable);
			break;
		case 4:
			Find(mainTable);
			break;
		case 5:
			ChangeElement(mainTable);
			break;
		case 6:
			mainTable.Show();
			break;
		case 7:
			CollisionsCount(mainTable);
			break;
		default:
			break;
		}
	} while (n != 0);
}