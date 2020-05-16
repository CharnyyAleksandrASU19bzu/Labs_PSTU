#pragma once
#include <iostream>

using namespace std;

class Iterator
{
	//дружественный класс
	friend class Vector;
public:
	//конструктор без параметров
	Iterator()
	{
		elem = 0;
	}

	//конструктор копирования
	Iterator(const Iterator& it)
	{
		elem = it.elem;
	}

	//перегруженные операции сравнения
	bool operator==(const Iterator& it)
	{
		return elem == it.elem;
	}
	bool operator!=(const Iterator& it)
	{
		return elem != it.elem;
	};

	//перегруженная операция инкремент
	void operator++(int)
	{
		++elem;
	};

	//перегруженная операция декремент
	void operator--(int)
	{
		--elem;
	}

	void operator +(const int n) 
	{ 
		elem += n; 
	}

	//перегруженная операция разыменования
	int& operator *() const
	{
		return*elem;
	}
private:
	int* elem;//указатель на элемент типа int

};

class Vector {
public:
	//конструктор без параметров
	Vector();

	//конструктор с параметрами
	Vector(int s, int k = 0);

	//конструктор копирования
	Vector(const Vector& a);

	//деструктор
	~Vector();

	//оператор присваивания
	Vector& operator=(const Vector& a);

	//операция доступа по индексу
	int& operator[](int index);

	//операция для добавления вектора
	Vector operator+(const Vector& k);

	//операция, возвращающая длину вектора
	operator int()const;

	//перегруженные операции ввода-вывода
	friend ostream& operator<<(ostream& out, Vector& a);
	friend istream& operator>>(istream& in, Vector& a);

	Iterator first()
	{
		return beg;
	}//возвращает указатель на первый элемент
	Iterator last()
	{
		return end;
	}//возвращает указатель на элемент следующий за

private:
	int size;
	int* data;
	Iterator beg;//указатель на первый элемент вектора
	Iterator end;//указатель на элемент следующий за последним
};