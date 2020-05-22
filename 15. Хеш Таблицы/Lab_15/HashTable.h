#pragma once
#include <cstring>
#include <exception>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Hash
{
	string account; //Номер счета-ключ
	string name; //ФИО
	double sum;//Сумма
};

class HashTable
{
private:
	Hash* table;
	int capacity;
	int currentSize;
public:
	HashTable(const int& _size = 100);
	HashTable(const HashTable& _hashTable);
	~HashTable();

	HashTable& operator=(const HashTable& _hashTable);

	int size() const //размер
	{
		return capacity;
	}
	bool empty() const //тблица пустая
	{
		return currentSize == 0;
	}
	bool full() const //таблица заполнена
	{
		return currentSize == capacity;
	}
	int HashFunc(const string& key);//Хеш функция
	void Add(const Hash& _Hash);//добавление
	void Del(const string& _account);//удаление
	Hash Find(const string& _name);//поиск
	void ChangeElement(const string& _account, const string& _name, const double& _sum);
	int CollisionsCount();//Подсчет коллизий
	void Show();//Вывод
};