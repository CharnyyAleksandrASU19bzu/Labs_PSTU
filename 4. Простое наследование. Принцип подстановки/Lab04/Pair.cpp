#include "Pair.h"

//конструктор без параметров
Pair::Pair()
{
	namber1 = 0;
	namber2 = 0;
}

//деструктор
Pair::~Pair()
{
}

//конструктор с параметрами
Pair::Pair(int A, int B)
{
	namber1 = A;
	namber2 = B;
}

//конструктор копирования
Pair::Pair(const Pair& t)
{
	namber1 = t.namber1;
	namber2 = t.namber2;
}

//селекторы
int Pair::Get_namber1()
{
	return namber1;
}
int Pair::Get_namber2()
{
	return namber2;
}

int Pair::Get_mult()
{
	return namber1*namber2;
}

//модификаторы
void Pair::Set_namber1(int A)
{
	namber1 = A;
}
void Pair::Set_namber2(int B)
{
	namber2 = B;
}


//перегрузка операции присваивания
Pair& Pair::operator=(const Pair& p)
{
	if (&p == this)return *this;
	namber1 = p.namber1;
	namber2 = p.namber2;
	return *this;
}


//глобальная функция для ввода
istream& operator>>(istream& in, Pair& p)
{
	cout <<"Первое число: " << endl;
	in >> p.namber1;
	cout <<"Второе число: " << endl;
	in >> p.namber2;
	return in;
}

//глобальная функция для вывода
ostream& operator<<(ostream& out, const Pair& p)
{
	Pair temp = p;
	out << endl<<"Ваше первое число: " << p.namber1;
	out << endl<<"Ваше второе число: " << p.namber2;
	out << endl << "Произвидение 1 и 2 числа: " << temp.Get_mult();
	out << endl;
	return out;
}
