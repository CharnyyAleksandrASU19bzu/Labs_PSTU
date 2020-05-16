#include "Money.h"
#include <iostream>
using namespace std;

Money make_money(int F, int S)
{
	Money m; //временная переменая
	m.Init(F, S);// инициализация полей переменой м
	return m;//возвращение переменной м
}

int main()
{
	setlocale(LC_ALL, "Rus");
	//определение переменных А и В
	Money A;
	Money B;
	cout << "Доступные денежные намминалы: 1,2,5,10,50,100,500,1000,5000" << endl;
	A.Init(100, 5); //инициализацйияе А
	B.Read(); //вывод полей В
	A.Show(); //вывод значение полей А
	B.Show(); //вывод значение полей В

	//vivod znachenia stepeni, vicheslennogo s pomoshu funkcii Summa()
	cout << endl<<"Вывод значения через функцию сумму" << endl;
	cout << endl<<"A.Summa(" << A.first << "," << A.second << ")=" << A.Summa() << endl;
	cout << "B.Summa(" << B.first << "," << B.second << ")=" << B.Summa() << endl;

	//ukazateli
	cout << "Вывод значения через указатели" << endl;
	Money* X = new Money;//videlenie pamati pod dinamicheskuu peremennuu
	X->Init(100, 1); //inicializacia
	X->Show(); //vivod znacheniy poley
	X->Summa(); //vivod stepeni
	cout << "X.Summa (" << X->first << "," << X->second << ")=" << X->Summa() << endl;

	//massivy
	cout <<endl<< "Вывод значения через массивы" << endl;
	Money mas[3]; //opredelenie massiva
	for (int i = 0; i < 3; i++)
	{
		mas[i].Read(); //chtenie znachenia poley
	}
	for (int i = 0; i < 3; i++)
	{
		mas[i].Show(); //vivod znachenia poley
	}
	for (int i = 0; i < 3; i++)
	{
		mas[i].Summa(); //vicheslenie stepeni
		cout << "mas[" << i << "].Power(" << mas[i].first << "," << mas[i].second << ")=" << mas[i].Summa() << endl;
	}

	//dinamicheskie massivy
	cout <<endl<< "Вывод значения через динамические массивы" << endl;
	Money* p_mas = new Money[3]; //videlenie pamati
	for (int i = 0; i < 3; i++)
	{
		p_mas[i].Read();//chtenie znachenia poley
	}
	for (int i = 0; i < 3; i++)
	{
		p_mas[i].Show(); //vivedenie znachenia poley
	}
	for (int i = 0; i < 3; i++)
	{
		p_mas[i].Summa(); //vicheslenie stepeni
		cout << "p_mas[" << i << "].Summa(" << p_mas[i].first << "," << p_mas[i].second << ")=" << p_mas[i].Summa() << endl;
	}

	//vizov funkcii make_money()
	cout << endl<<"Вызов функции make_money()" << endl;
	double y;
	int z;
	cout << "Денежный номанал = ";
	cin >> y;
	cout << "Количество = ";
	cin >> z;

	//peremennaia F formiruetsa s pomoshiu funkcii make_fraction()
	Money F = make_money(y, z);
	F.Show();
}