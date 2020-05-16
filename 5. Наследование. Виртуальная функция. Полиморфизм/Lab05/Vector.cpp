#include "Vector.h"

//Конструктор без парамтеров
Vector::Vector()
{
	beg = 0;
	size = 0;
	cur = 0;
}

//Деструктор
Vector::~Vector()
{
	if (beg != 0) delete[] beg;
	beg = 0;
}

//Конструктор с параметрами
Vector::Vector(int n)
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}


Vector::Vector(const Vector&c)
{
}

//Добавление объекта, на который указывает указатель р в Векторе
void Vector::Add(Object* p)
{
	if (cur < size)
	{
		beg[cur] = p;
		cur++;
	}
}

//Глобальный вывод
ostream& operator<<(ostream& out, const Vector& v)
{
	if (v.size == 0) out << "Пусто" << endl;
	//указатель на указатель типа объект
	Object** p = v.beg;
	for (int i = 0; i < v.cur; i++)
	{
		//Вывод метода Shpw()
		(*p)->Show();
		//передвигаем указатель на следующий объект
		p++;
	}
	return out;
}