#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "HashTable.h"

void MakeTable(HashTable& table);//функция создания
void Add(HashTable& table);//функция добавления элемента
void Del(HashTable& table);//функция удаления элемента
void Find(HashTable& table);//функция поиска элемента
void ChangeElement(HashTable& table);//функция изменения элемента
void CollisionsCount(HashTable& table);//функция подсчета коллизий