#include "vector.h"
#include "Time.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	cout << "Введите Time :" << endl;
	Time t;
	cin >> t;
	cout << t;

	Vector<Time>A(3, t);
	cout << "Введите вектор А : " << endl;
	cin >> A;
	cout <<"Вектор А : "<< endl << A << endl;

	Vector <Time>B(3, t);
	cout << "Введите вектор B : " << endl;
	cin >> B;
	cout <<"Вектор B : "<< endl << B << endl;

	Vector <Time>C(3, t);
	C = A + B;
	cout << "Вектор C=A+B : " << "C"<< endl << C << endl;
	B = A;
	cout << "Вектор B=A : " << endl << B << endl;
	cout << "Вектор A с индексом 2 : " << endl << A[2] << endl;
	int s = A;
	cout << "Размер вектора = " << s << endl;

	B = A + t;
	cout << "Вектор B=A+Time : " <<endl<< B << endl;
}