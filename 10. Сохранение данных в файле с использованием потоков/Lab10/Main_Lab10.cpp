#include "Time.h"
#include "file_work.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	setlocale (LC_ALL, "Rus");
	Time t1;
	int k, c;
	char file_name[30];
	do
	{
		cout << "1. ������� ����" << endl;
		cout << "2. ������� ���������� �����" << endl;
		cout << "3. ������� ��� ������ �� ������ ��������" << endl;
		cout << "4. ��������� ��� ������ � ������� ��������� �� 1:30" << endl;
		cout << "5. �������� ������ � ������ �����" << endl;
		cout << "0. Exit" << endl;
		cin >> c;
		switch (c)
		{
		case 1: 
			cout << "������� ��� �����"<<endl;
			cin >> file_name;
			k = make_file(file_name);
			if (k < 0)
				cout << "���������� ������� ����";
			break;
		case 2: 
			cout << "������� ��� �����" << endl;
			cin >> file_name;
			k = print_file(file_name);
			if (k == 0)
				cout << "���� ����" << endl;
			if (k < 0)
				cout << "���������� ��������� ����" << endl;
			break;
		case 3: 
			cout << "������� ��� �����"<<endl;
			cin >> file_name;
			cin >> t1;
			k = del_file(file_name, t1);
			if (k < 0)
				cout << "���������� ��������� ����" << endl;
			break;
		case 4: 
			cout << "������� ��� �����"<<endl;
			cin >> file_name;
			cout << "������� �������� ������"<<endl;
			cin >> t1;
			k = change_file(file_name,t1);
			if (k < 0)
				cout << "���������� ��������� ����" << endl;
			if (k == 0)
				cout << "��������� �� ��������" << endl;
			break;
		case 5: 
			cout << "������� ��� �����"<<endl;
			cin >> file_name;
			k = add_file(file_name);
			if (k < 0)
				cout << "���������� ��������� ����" << endl;
			break;
		}
	} while (c != 0);
}

