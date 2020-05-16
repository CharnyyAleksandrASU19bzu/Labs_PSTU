#include "Pair.h"

//конструктор без параметров
Pair::Pair()
{
	number1 = 0;
	number2 = 0;
}

//деструктор
Pair::~Pair()
{
}

//конструктор с параметрами
Pair::Pair(int A, int B)
{
	number1 = A;
	number2 = B;
}

//конструктор копирования
Pair::Pair(const Pair& t)
{
	number1 = t.number1;
	number2 = t.number2;
}

//селекторы
int Pair::Get_number1()
{
	return number1;
}
int Pair::Get_number2()
{
	return number2;
}

int Pair::Get_mult()
{
	return number1 * number2;
}

//модификаторы
void Pair::Set_number1(int A)
{
	number1 = A;
}
void Pair::Set_number2(int B)
{
	number2 = B;
}


//перегрузка операции присваивания
Pair& Pair::operator=(const Pair& p)
{
	if (&p == this)return *this;
	number1 = p.number1;
	number2 = p.number2;
	return *this;
}


//глобальная функция для ввода
istream& operator>>(istream& in, Pair& p)
{
	cout << "Первое число: ";
	in >> p.number1;
	cout << "Второе число: ";
	in >> p.number2;
	return in;
}

//глобальная функция для вывода
ostream& operator<<(ostream& out, const Pair& p)
{
	Pair temp = p;
	out << endl << "Ваше первое число: " << p.number1;
	out << endl << "Ваше второе число: " << p.number2;
	out << endl << "Произвидение 1 и 2 числа: " << temp.Get_mult();
	out << endl;
	return out;
}

void Pair::Show()
{
	cout << endl << "Ваше первое число: " << number1;
	cout << endl << "Ваше второе число: " << number2;
	cout << endl << "Произвидение 1 и 2 числа: " << Get_mult();
	cout << endl;
}