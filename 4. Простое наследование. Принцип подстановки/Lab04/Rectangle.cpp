#include "Rectangle.h"

//конструктор без параметров
Rectangle::Rectangle() :Pair()
{
}

//дестрктор
Rectangle::~Rectangle( )
{
}

//конструктор с параметрами
Rectangle::Rectangle(int A, int B) :Pair(A, B)
{
}

//конструктор копирования
Rectangle::Rectangle(const Rectangle& r)
{
	namber1 = r.namber1;
	namber2 = r.namber2;
}

//модификаторы
int Rectangle::get_perimeter()
{
	return namber1*namber2;
}

int Rectangle::get_area()
{
	return namber1*2 + namber2*2;
}


//оперция присваивания
Rectangle& Rectangle::operator=(const Rectangle& r)
{
	if (&r == this)return *this;
	namber1 = r.namber1;
	namber2 = r.namber2;
	return *this;
}

//операция ввода
istream& operator>>(istream& in, Rectangle& r)
{
	cout <<endl<< "Введите сторону а : "; 
	in >>r.namber1;
	cout <<endl<< "Введите сторону b : "; 
	in >> r.namber2;
	return in;
}

//операция вывода
ostream& operator<<(ostream& out, const Rectangle& r)
{
	Rectangle temp = r;
	out << endl<< "Cторона а : " << r.namber1;
	out << endl<< "Сторона в : " << r.namber2;
	out << endl << "Площадь прямоугольника : " << temp.get_area();
	out << endl << "Периметр прямоугольника : " << temp.get_perimeter();
	out << endl;
	return out;
}