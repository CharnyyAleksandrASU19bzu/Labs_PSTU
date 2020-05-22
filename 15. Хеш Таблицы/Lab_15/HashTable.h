#pragma once
#include <cstring>
#include <exception>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Hash
{
	string account; //����� �����-����
	string name; //���
	double sum;//�����
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

	int size() const //������
	{
		return capacity;
	}
	bool empty() const //������ ������
	{
		return currentSize == 0;
	}
	bool full() const //������� ���������
	{
		return currentSize == capacity;
	}
	int HashFunc(const string& key);//��� �������
	void Add(const Hash& _Hash);//����������
	void Del(const string& _account);//��������
	Hash Find(const string& _name);//�����
	void ChangeElement(const string& _account, const string& _name, const double& _sum);
	int CollisionsCount();//������� ��������
	void Show();//�����
};