#pragma once
#include <iostream>
using namespace std;

//параметр шаблона
template<class T>

class Vector {
public:
	//Конструктор по умолчанию
	Vector()
	{
	}

	//конструктор с параметрами
	Vector(int s, T k)
	{
		size = s;
		data = new T[size];
		for (int i = 0; i < size; i++)
			data[i] = k;
	}

	//конструктор копирования
	Vector(const Vector<T>& a)
	{
		size = a.size;
		data = new T[size];
		for (int i = 0; i < size; i++)
			data[i] = a.data[i];
	}

	//деструктор
	~Vector()
	{
		delete[]data;
		data = 0;
	}

	//оператор присваивания
	Vector& operator=(const Vector<T>& a)
	{
		if (this == &a)return *this;
		size = a.size;
		if (data != 0) delete[]data;
		data = new T[size];
		for (int i = 0; i < size; i++)
			data[i] = a.data[i];
		return *this;
	}

	//операция доступа по индексу
	T& operator[](int index)
	{
		if (index < size)
			return data[index];
		else
			cout << endl << "Ошибка! индекс больше размера";
	}

	//операция для добавления вектора к вектору
	Vector operator+(const Vector& k)
	{
		T t;
		Vector<T> temp(size,t);
		for (int i = 0; i < size; ++i)
			temp.data[i]= data[i] + k.data[i];
		return temp;
	}

	//операция для добавления константы к вектору
	Vector operator+(const T k)
	{
		Vector<T> temp1(size, k);
		for (int i = 0; i < size; ++i)
			temp1.data[i] = data[i] + k;
		return temp1;
	}

	//операция, возвращающая длину вектора
	operator int()const
	{
		return size;
	}

	//перегруженные операции ввода-вывода
	friend istream& operator>>(istream& in, Vector<T>& a)
	{
		for (int i = 0; i < a.size; ++i)
			in >> a.data[i];
		return in;
	}

	friend ostream& operator<<(ostream& out, Vector<T>& a)
	{
		for (int i = 0; i < a.size; ++i)
			out << a.data[i] << " ";
		return out;
	}


private:
	int size;// размер вектора
	T* data;//указатель на динамический массив значений вектора
};