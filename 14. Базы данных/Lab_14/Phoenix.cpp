#include "Phoenix.h"

using namespace std;

// ���������� �������� ������������
Phoenix& Phoenix::operator =(const Phoenix& t)
{
	// �������� �� ����������������
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

// ���������� ���������� �������� ���������
Phoenix& Phoenix::operator ++()
{
	profitP++;
	return *this;
}

// ���������� �������� �������� ��������
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

// ���������� �������� �������� ���������
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

// ���������� ���������� �������-�������� �����
istream& operator >>(istream& in, Phoenix& t)
{
	cout << "������� �������������: ";
	in >> t.unitP;
	cout << "������� ���: ";
	in >> t.yearP;
	cout << "������� �����: ";
	in >> t.profitP;
	return in;
}

// ���������� ���������� �������-�������� ������
ostream& operator <<(ostream& out, const Phoenix& t)
{
	if (!t.del) out << "| " << t.unitP << " | " << t.yearP << " |" << t.profitP << " |" << endl;
	return out;
}

// �������� ����
fstream& operator >>(fstream& fin, Phoenix& t)
{
	fin >> t.unitP;
	fin >> t.profitP;
	fin >> t.yearP;
	fin >> t.del;
	return fin;
}

// �������� �����
fstream& operator <<(std::fstream& fout, const Phoenix& t)
{
	fout << t.unitP << endl;
	fout << t.profitP << endl;
	fout << t.yearP << endl;
	fout << t.del << endl;
	return fout;
}