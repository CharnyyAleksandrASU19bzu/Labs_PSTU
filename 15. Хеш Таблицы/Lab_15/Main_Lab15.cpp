#include <iostream>
#include <vector>
#include <string>
#include "HashTable.h"
#include "MenuFunctions.h"

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "1. ������������� �������" << endl
		<< "2. �������� ������� � �������" << endl
		<< "3. ������� ������� �� �������" << endl
		<< "4. ����� ������� � �������" << endl
		<< "5. �������� ������ �������� � �������" << endl
		<< "6. ������� ������� � ������" << endl
		<< "7. �������� ���������� ��������" << endl
		<< "0. �����" << endl << endl;

	HashTable mainTable;
	int n;
	do
	{
		cout << "�������� ��������: ";
		cin >> n;
		while (cin.fail() || n < 0 || n > 7)
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "������: ������ �����. ���������� �����: ";
				cin >> n;
			}
			else
			{
				cout << "������:����������� �����, �������: 0-7";
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