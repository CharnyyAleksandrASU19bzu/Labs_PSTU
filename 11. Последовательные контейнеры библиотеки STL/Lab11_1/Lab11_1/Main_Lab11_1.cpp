#include <iostream>
#include <list>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef list <float> List; //����������� ��� ��� ������

//������� ������������
List make_list(float n)
{
	List l;
	for (int i = 0; i < n; i++)
	{
		float a = rand() % 100 - 50;
		l.push_back(a);//��������� � � �����
	}
	return l;//���������� 
}

//������� ��� ������
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

float Min(List l) //����������� �������
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
	list <float> l; //������
	list <float>::iterator i;
	int n;
	cout << "������� ������ ������ : ";
	cin >> n;
	l = make_list(n); //������������ �����
	print_list(l);	//������ �����
	l.push_back(Min(l));
	print_list(l);
}