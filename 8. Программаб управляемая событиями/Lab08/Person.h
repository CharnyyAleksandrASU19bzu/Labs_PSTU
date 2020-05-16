#pragma once
#include <string>
#include <iostream>
#include "Object.h"
using namespace std;

class Person :
	public Object
{
public:
	//����������� ��� ����������
	Person (); 
public:
	//����������� � �����������
	Person (string, int); 
	//����������� �����������
	Person (const Person&);
	
	//����������
	virtual ~Person();
	
	//����-�����
	void Show(); 
	void Input();
		
	//���������
	string get_name();
	int get_age();

	//������������
	void set_name(string);
	void set_age(int);
	
	//���������� �������� ������������
	Person& operator=(const Person&);

	void HandleEvent(const TEvent& e);
protected:
	string name;
	int age;
};
