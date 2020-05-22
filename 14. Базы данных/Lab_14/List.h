#pragma once
#include <iostream>
#include <list>
#include "Phoenix.h"

using namespace std;

typedef list<Phoenix> List;
typedef List::iterator Lit;

// Функция для печати контейнера
void print_list(List l) {
    string U;
    int Y = 0;
    cout << "| *** PHOENIX DATABASE *** |";
    for (Lit i = l.begin(); i != l.end(); i++)
    {
        if (!(*i).get_del())
        {
            if (U != (*i).get_unit())
            {
                U = (*i).get_unit();
                cout << endl << endl;
                cout << "| Unit: " << U << "     |" << endl;
            }
            if (Y != (*i).get_year()) {
                Y = (*i).get_year();
                cout << endl;
                cout << "| Year: " << Y << "     |" << endl;
            }
            cout << "| " << (*i).get_profit() << " |";
        }
    }
    cout << endl << endl;
}

// Резервная копия базы
void backup(List l, List& b)
{
    b.clear();
    for (Lit i = l.begin(); i != l.end(); i++)
    {
        b.push_back((*i));
    }
}

// Восстановление базы
void rewind(List& l, List b)
{
    l.clear();
    for (Lit i = b.begin(); i != b.end(); i++)
    {
        l.push_back((*i));
    }
}

// Удаление элемента из позиции pos
void del_pos(List& l, int pos, bool& cheange)
{
    if (pos > l.size())
    {
        cout << "Недопустимая позиция" << endl;
        return;
    }
    Lit i = l.begin();
    while (pos--)
    {
        i++;
    }
    (*i).set_del(true);
    if (!cheange)
    {
        cheange = true;
    }
}

// Удаление помеченых элементов перезаписью списка
void del_mark(List& l)
{
    List temp;
    for (Lit i = l.begin(); i != l.end(); i++)
    {
        if (!(*i).get_del()) temp.push_back((*i));
    }
    l = temp;
}

// Подсчет помеченых на удаление элементов
int count_mark(List l)
{
    int counter = 0;
    for (Lit i = l.begin(); i != l.end(); i++)
    {
        if ((*i).get_del()) counter++;
    }
    return counter;
}

// Операция удаления помеченых элементов
void del_operation(List& l, List& b)
{
    if (count_mark(l) > (l.size() / 2))
    {
        del_mark(l);
        cout << "Помеченые записи удалены" << endl;
    }
    b.clear();
    b = l;
}

// Удаление по ключу
void del_key(List& l, Phoenix key, bool& cheange)
{
    Lit i = l.begin();
    while ((*i) != key)
    {
        i++;
        if (i == l.end())
        {
            cout << "Ключ не найден" << endl;
            return;
        }
    }
    (*i).set_del(true);
    if (!cheange)
    {
        cheange = true;
    }
}

// Добавление элемента el в позицию pos
void add_pos(List& l, Phoenix el, int pos, bool& cheange)
{
    Lit i = l.begin();
    while (pos--)
    {
        i++;
    }
    l.emplace(i, el);
    if (!cheange)
    {
        cheange = true;
    }
}

// Изменение элемента в указаной позиции
void change_pos(List& l, Phoenix el, int pos, bool& cheange)
{
    Lit i = l.begin();
    while (pos--)
    {
        i++;
    }
    (*i) = el;
    if (!cheange)
    {
        cheange = true;
    }
}

// Изменение элемента с указанным ключем
void change_key(List& l, Phoenix el, Phoenix key, bool& cheange)
{
    for (Lit i = l.begin(); i != l.end(); i++)
    {
        if ((*i) == key) (*i) = el;
    }
    if (!cheange)
    {
        cheange = true;
    }
}

// Добавление в конец
void add_end(List& l, Phoenix el, bool& cheange)
{
    l.push_back(el);
    if (!cheange)
    {
        cheange = true;
    }
}

// Добавление элемента el в начало
void add_begin(List& l, Phoenix el, bool& cheange)
{
    l.push_front(el);
    if (!cheange) cheange = true;
}

int max_key(list<int> l)
{
    list<int>::iterator i;
    int max = 0;
    for (i = l.begin(); i != l.end(); i++)
    {
        if (max < (*i))
        {
            max = (*i);
        }
    }
    return max;
}

int max_pos(list<int> l)
{
    list<int>::iterator i = l.begin();
    int max = 0;
    int counter = 0; // Счетчик элементов
    int pos = 0; //Номер максимального элемента
    for (i = l.begin(); i != l.end(); i++, counter++)
    {
        if (max < (*i))
        {
            max = (*i);
            pos = counter;
        }
    }
    return pos + 1;
}

int year_pos(List l, int pos)
{
    Lit i = l.begin();
    int year = (*i).get_year();
    for (Lit i = l.begin(); i != l.end(); i++)
    {
        if (year != (*i).get_year())
        {
            pos--;

            if (pos == 0) return year;
        }
        year = (*i).get_year();
    }
}

//
void max_year(List l)
{
    list<int> TList;
    string U;
    int Y = 0;
    int year = 0;
    int sum = 0;
    int maxY = 0;
    for (Lit i = l.begin(); i != l.end(); i++)
    {
        U = (*i).get_unit();
        cout << "| *** " << U << " *** |" << endl;
        TList.clear();
        do {
            sum = 0;
            year = (*i).get_year();
            do {
                if (!(*i).get_del()) sum = sum + (*i).get_profit();
                i++;
                if (i == l.end())
                {
                    TList.push_back(sum);
                    maxY = max_pos(TList);
                    cout << "| *** " << year_pos(l, maxY) << " *** |" << endl;
                    return;
                }
            } while (year == (*i).get_year());
            TList.push_back(sum);
            i++;
        } while (U == (*i).get_unit());
        maxY = max_pos(TList);
        cout << "| *** " << year_pos(l, maxY) << " *** |" << endl;
    }
}

// Вычисление среднего арифметического
Phoenix average(List l)
{
    Phoenix a;
    int n = l.size() - count_mark(l);
    for (Lit i = l.begin(); i != l.end(); i++)
    {
        a = a + (*i);
    }
    return a / n;
}

// Наибольший промежуток для каждого подразделения с доходом ниже среднего
void min_range(List l)
{
    list<int> lt;
    Phoenix a = average(l);
    string U;
    int Y = 0;
    int range = 0;
    int maxrange = 0;
    for (Lit i = l.begin(); i != l.end(); i++)
    {
        U = (*i).get_unit();
        cout << "| *** " << U << " *** |" << endl;
        lt.clear();
        do
        {
            if ((*i).get_profit() < a.get_profit())
            {
                if (!(*i).get_del()) range++;
                lt.push_back(range);
            }
            else range = 0;
            maxrange = max_key(lt);
            i++;
            if (i == l.end())
            {
                cout << "| *** " << maxrange << " *** |" << endl;
                return;
            }
        } while (U == (*i).get_unit());
        cout << "| *** " << maxrange << " *** |" << endl;
    }
}