#include "vector.h"
#include "Time.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	cout << "������� Time :" << endl;
	Time t;
	cin >> t;
	cout << t;

	Vector<Time>A(3, t);
	cout << "������� ������ � : " << endl;
	cin >> A;
	cout <<"������ � : "<< endl << A << endl;

	Vector <Time>B(3, t);
	cout << "������� ������ B : " << endl;
	cin >> B;
	cout <<"������ B : "<< endl << B << endl;

	Vector <Time>C(3, t);
	C = A + B;
	cout << "������ C=A+B : " << "C"<< endl << C << endl;
	B = A;
	cout << "������ B=A : " << endl << B << endl;
	cout << "������ A � �������� 2 : " << endl << A[2] << endl;
	int s = A;
	cout << "������ ������� = " << s << endl;

	B = A + t;
	cout << "������ B=A+Time : " <<endl<< B << endl;
}