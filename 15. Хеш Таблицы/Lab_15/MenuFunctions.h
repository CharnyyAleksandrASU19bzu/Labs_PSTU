#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "HashTable.h"

void MakeTable(HashTable& table);//������� ��������
void Add(HashTable& table);//������� ���������� ��������
void Del(HashTable& table);//������� �������� ��������
void Find(HashTable& table);//������� ������ ��������
void ChangeElement(HashTable& table);//������� ��������� ��������
void CollisionsCount(HashTable& table);//������� �������� ��������