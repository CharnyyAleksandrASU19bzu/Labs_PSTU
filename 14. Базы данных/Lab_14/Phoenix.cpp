#include "Phoenix.h"

using namespace std;

// Перегрузка операции присваивания
Phoenix& Phoenix::operator =(const Phoenix& t)
{
	// Проверка на самоприсваивание
	if (&t == this)
	{
		return *this;
	}
	unitP = t.unitP;
	profitP = t.profitP;
	yearP = t.yearP;
	del = t.del;
	return *this;
}

// Перегрузка префиксной операции инкремент
Phoenix& Phoenix::operator ++()
{
	profitP++;
	return *this;
}

// Перегрузка бинарной операции сложения
Phoenix Phoenix::operator +(const Phoenix& t)
{
	Phoenix p;
	if (!t.del) p.profitP = profitP + t.profitP;
	else p.profitP = profitP;
	return p;
}

//
Phoenix Phoenix::operator +(const int& i)
{
	Phoenix p;
	p.profitP = profitP + i;
	return p;
}

//
Phoenix Phoenix::operator /(const Phoenix& t)
{
	Phoenix p;
	p.profitP = profitP / t.profitP;
	return p;
}

Phoenix Phoenix::operator /(const int& i)
{
	Phoenix p;
	p.profitP = profitP / i;
	return p;
}

// Перегрузка бинарной операции сравнения
bool Phoenix::operator ==(const Phoenix& t)
{
	if (profitP == t.profitP && !del && !t.del) return true;
	return false;
}

bool Phoenix::operator !=(const Phoenix& t)
{
	if (profitP != t.profitP && !del && !t.del) return true;
	return false;
}

bool Phoenix::operator >(const Phoenix& t)
{
	if (profitP > t.profitP && !del && !t.del) return true;
	return false;
}

bool Phoenix::operator >(const int& i)
{
	if (profitP > i) return true;
	return false;
}

bool Phoenix::operator <(const Phoenix& t)
{
	if (profitP < t.profitP && !del && !t.del) return true;
	return false;
}

bool Phoenix::operator <(const int& i)
{
	if (profitP < i) return true;
	return false;
}

// Перегрузка глобальной функции-операции ввода
istream& operator >>(istream& in, Phoenix& t)
{
	cout << "Введите подразделение: ";
	in >> t.unitP;
	cout << "Введите год: ";
	in >> t.yearP;
	cout << "Введите доход: ";
	in >> t.profitP;
	return in;
}

// Перегрузка глобальной функции-операции вывода
ostream& operator <<(ostream& out, const Phoenix& t)
{
	if (!t.del) out << "| " << t.unitP << " | " << t.yearP << " |" << t.profitP << " |" << endl;
	return out;
}

// Файловый ввод
fstream& operator >>(fstream& fin, Phoenix& t)
{
	fin >> t.unitP;
	fin >> t.profitP;
	fin >> t.yearP;
	fin >> t.del;
	return fin;
}

// Файловый вывод
fstream& operator <<(std::fstream& fout, const Phoenix& t)
{
	fout << t.unitP << endl;
	fout << t.profitP << endl;
	fout << t.yearP << endl;
	fout << t.del << endl;
	return fout;
}