#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Phoenix.h"
#include "List.h"

using namespace std;

int make_file(const char* f_name, List& l)
{
	fstream stream(f_name, ios::out | ios::trunc); // ������� ��� ������

	if (!stream) return -1; // ������ �������� �����
	int Psize;
	string Punit;

	l.clear();

	cout << "����������� �������������" << endl;
	cout << "> ";
	cin >> Psize;
	for (int i1 = 0; i1 < Psize; i1++)
	{
		cout << "������� �������� �������������" << endl;
		cout << "> ";
		cin >> Punit;
		int Y = 5;
		for (int i2 = 0; i2 < Y; i2++)
		{
			int n = 12;
			for (int i3 = 0; i3 < n; i3++)
			{
				int t = rand() % 1000;
				Phoenix P(Punit, t, i2 + 1998);
				l.push_back(P);
				stream << P << endl; // ������ � �������� �����
			}
		}
	}
	stream.close(); // �������� ��������� ������
	return Psize; // ������� ���������� ��������� ��������
}

int save_file(const char* f_name, List& l, bool& cheange)
{
	if (!cheange)
	{
		cout << "��� ��������� ��� ����������" << endl;
		return 1;
	}
	fstream stream("temp", ios::out);
	if (!stream) return -1;
	int n = 0;
	Phoenix temp;
	for (Lit i = l.begin(); i != l.end(); i++, n++)
	{
		temp = (*i);
		stream << temp;
	}
	stream.close();
	remove(f_name);
	rename("temp", f_name);
	cheange = false;
	return n;
}

int open_file(const char* f_name, List& l)
{
	fstream stream(f_name, ios::in);
	Phoenix temp;
	int n = 0;
	if (!stream)
	{
		return -1;
	}
	if (l.size() > 0) l.clear();
	while (stream >> temp)
	{
		l.push_back(temp);
		n++;
	}
	return n;
}