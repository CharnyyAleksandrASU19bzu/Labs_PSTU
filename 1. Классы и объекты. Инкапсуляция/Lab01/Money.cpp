#include"Money.h"
#include <iostream>
using namespace std;

//����� ��� ������������� ����� ���������
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
		cout << "������������ �������!" << endl;
		flag = 0;
	}
}

//����� ��� ������� ����� ���������
void Money::Read()
{
	const int K = 9;
	int allowed[K] = { 1,2,5,10,50,100,500,1000,5000 };
	while (true)
	{
		cout << "������� �������� �������:";
		cin >> first;
		for (int i = 0; i < K; i++)
		{
			if (first == allowed[i])
			{
				cout << "������� ����������:";
				cin >> second;
				cout << endl;
				return;
			}
		}
		cout << "������������ �������!" << endl;
	}
}

//����� ��� ����� ����� ���������
void Money::Show()
{
	cout << endl << "�������� ������� = " << first;
	cout << endl << "���������� = " << second;
	cout << endl;
}

//����� ��� ���������� �����
int Money::Summa()
{
	return first * second;
}