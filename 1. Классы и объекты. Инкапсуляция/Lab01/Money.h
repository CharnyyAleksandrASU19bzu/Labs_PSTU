#pragma once
struct Money
{
	int first;
	int second;
	void Init(int, int); //инициализация
	void Read(); //чтение значения полей
	void Show(); //вывод значение полей
	int Summa(); //денежная сумма
};
