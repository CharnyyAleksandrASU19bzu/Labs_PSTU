#include "Rectangle.h"

//конструктор без параметров
Rectangle::Rectangle() :Pair()
{
}

//дестрктор
Rectangle::~Rectangle()
{
}

//конструктор с параметрами
Rectangle::Rectangle(int A, int B) :Pair(A, B)
{
}

//конструктор копирования
Rectangle::Rectangle(const Rectangle& r)
{
	number1 = r.number1;
	number2 = r.number2;
}

//Периметр
int Rectangle::get_perimeter()
{
	return number1 * number2;
}
//Площадь
int Rectangle::get_area()
{
	return number1 * 2 + number2 * 2;
}


//оперция присваивания
Rectangle& Rectangle::operator=(const Rectangle& r)
{
	if (&r == this)return *this;
	number1 = r.number1;
	number2 = r.number2;
	return *this;
}
//операция ввода
istream& operator>>(istream& in, Rectangle& r)
{
	cout << endl << "Введите сторону а : ";
	in >> r.number1;
	cout << "Введите сторону b : ";
	in >> r.number2;
	return in;
}

//операция вывода
ostream& operator<<(ostream& out, const Rectangle& r)
{
	Rectangle temp = r;
	out << endl << "Cторона а : " << r.number1;
	out << endl << "Сторона в : " << r.number2;
	out << endl << "Площадь прямоугольника : " << temp.get_area();
	out << endl << "Периметр прямоугольника : " << temp.get_perimeter();
	out << endl;
	return out;
}

void Rectangle::Show()
{
	cout << endl << "Cторона а : " << number1;
	cout << endl << "Сторона в : " << number2;
	cout << endl << "Площадь прямоугольника : " << get_area();
	cout << endl << "Периметр прямоугольника : " <<get_perimeter();
	cout << endl;
}