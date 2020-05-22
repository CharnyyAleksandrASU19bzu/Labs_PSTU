#include "HashTable.h"
using namespace std;

HashTable::HashTable(const int& _size) //�����������
{
	capacity = _size;
	currentSize = 0;
	table = new Hash[capacity];
	Hash tmp = { "empty","empty", 0 };
	for (int i = 0; i < capacity; i++)
		table[i] = tmp;
}

HashTable::HashTable(const HashTable& _hashTable)//����������� �����������
{
	capacity = _hashTable.capacity;
	currentSize = _hashTable.currentSize;
	table = new Hash[capacity];
	for (int i = 0; i < capacity; i++)
		table[i] = _hashTable.table[i];
}

HashTable::~HashTable()//����������
{
	if (table != 0)
	{
		delete[] table;
		table = 0;
	}
}

HashTable& HashTable::operator=(const HashTable& _hashTable)//����������
{
	if (this == &_hashTable)
		return *this;
	if (table != 0)
	{
		delete[] table;
		table = 0;
	}
	capacity = _hashTable.capacity;
	currentSize = _hashTable.currentSize;
	table = new Hash[capacity];
	for (int i = 0; i < capacity; i++)
		table[i] = _hashTable.table[i];
	return *this;
}

int HashTable::HashFunc(const string& key) //��� �������
{
	int asciiSum = 0;
	int N = 32; float A = ((sqrt(5) - 1) / 2);;
	for (int i = 0, p = 1; i < key.size(); i++, p++)
		asciiSum += key[i] * p;
	int h = N * fmod(asciiSum * A, 1);
	return h;
}

void HashTable::Add(const Hash& _Hash) //����������
{
	if (this->full()) {
		cout << "������: ������� ������\n";
		return;
	}
	int hashKey = HashFunc(_Hash.account);
	//"-1" means element is deleted
	if (table[hashKey].account == "empty" || table[hashKey].account == "-1") {
		table[hashKey] = _Hash;
		currentSize++;
		return;
	}
	while (table[hashKey].account != "empty" || table[hashKey].account != "-1")
	{
		//go to the next element
		hashKey++;
		//if end of the table reached, go to the beginning
		if (hashKey == capacity)
			hashKey = 0;
		if (table[hashKey].account == "empty" || table[hashKey].account == "-1")
		{
			table[hashKey] = _Hash;
			currentSize++;
			return;
		}
	}
}

void HashTable::Del(const string& _account)//��������
{
	if (this->empty())
	{
		cout << "������ :������� ������." << endl;
		return;
	}
	int hashKey = HashFunc(_account);
	if (table[hashKey].account == _account)
	{
		table[hashKey].account = "-1";
		table[hashKey].name = "-1";
		table[hashKey].sum = 0;
		currentSize--;
		return;
	}

	int checkedElements = 1;
	while (table[hashKey].account != "empty")
	{
		hashKey++;
		if (hashKey == capacity)
			hashKey = 0;
		if (table[hashKey].account == _account)
		{
			table[hashKey].account = "-1";
			table[hashKey].name = "-1";
			table[hashKey].sum = 0;
			currentSize--;
			return;
		}
		checkedElements++;
		if (checkedElements == capacity)
		{
			cout << "������: ������� �� ������." << endl;
			return;
		}
	}
	cout << "������: ������� �� ������." << endl;
}

Hash HashTable::Find(const std::string& _name)//����� ��������
{
	if (this->empty())
	{
		cout << "������: ������� �������." << endl;
		return { "empty", 0, 0 };
	}
	int hashKey = HashFunc(_name);
	if (table[hashKey].account == _name)
		return table[hashKey];
	int checkedElements = 1;
	while (table[hashKey].account != "empty")
	{
		hashKey++;
		if (hashKey == capacity)
			hashKey = 0;
		if (table[hashKey].account == _name)
			return table[hashKey];
		checkedElements++;
		if (checkedElements == capacity)
		{
			cout << "������: ������� �������." << endl;
			return { "empty", 0, 0 };
		}
	}
	cout << "������: ������� �������." << endl;
	return { "empty", 0, 0 };
}

void HashTable::ChangeElement(const string& _account, const string& _name, const double& _sum)	//��������� ��������
{
	if (this->empty()) {
		cout << "������: ������� �������." << endl;
		return;
	}
	int hashKey = HashFunc(_account);
	if (table[hashKey].account == _account)
	{
		table[hashKey].name = _name;
		table[hashKey].sum = _sum;
		return;
	}

	int checkedElements = 0;
	while (table[hashKey].account != "empty")
	{
		hashKey++;
		if (hashKey == capacity)
			hashKey = 0;
		if (table[hashKey].account == _account)
		{
			table[hashKey].name = _name;
			table[hashKey].sum = _sum;
			return;
		}
		checkedElements++;
		if (checkedElements == capacity)
		{
			cout << "������: ������� �� ������." << endl;
			return;
		}
	}
	cout << "������: ������� �� ������." << endl;
}

int HashTable::CollisionsCount()//������� ��������
{
	int count = 0;
	for (int i = 0; i < capacity; i++)
	{
		if (table[i].account == "empty")
			continue;
		if (HashFunc(table[i].account) != i)
			count++;
	}
	return count;
}

void HashTable::Show() //�����
{
	cout << setw(8) << "��� ����" << setw(19) << "����� �����"
		<< setw(19) << "���" << setw(28) << "�����" << endl;

	for (int i = 0; i < capacity; i++)
	{

		if (table[i].name != "empty" && table[i].name != "-1")

			cout << setw(5) << HashFunc(table[i].account) << setw(20) << table[i].account
			<< setw(30) << table[i].name << setw(20)
			<< fixed << setprecision(2) << table[i].sum << endl;
	}
}