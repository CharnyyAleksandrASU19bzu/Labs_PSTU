#include "Object.h"
#include "Vector.h"
#include "Pair.h"
#include"Rectangle.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	Vector v(5);
	Pair a;
	cin >> a;
	Rectangle b;
	cin >> b;
	Object* p = &a;
	v.Add(p);
	p = &b;
	v.Add(p);
	cout << v;
}
