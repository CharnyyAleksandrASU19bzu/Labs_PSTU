#pragma once
#include <vector>
#include <iomanip>
#include <iostream>
using namespace std;

class Node
{
public:
    int Data;
    Node* Left;
    Node* Right;
    int Height;
};

int max(int a, int b) //функция сравнения
{
    return (a > b);
}

int height(Node* N) //высота дерева
{
    if (N == 0)
    {
        return 0;
    }
    return N->Height;
}

Node* newNode(int Data) //Создание узла
{
    Node* node = new Node();
    node->Data = Data;
    node->Left = 0;
    node->Right = 0;
    node->Height = 1;
    return(node);
}

Node* rightRotate(Node* y)//правый поворт дерева для балансировки
{
    Node* x = y->Left;
    Node* T2 = x->Right;
    x->Right = y;
    y->Left = T2;
    y->Height = max(height(y->Left), height(y->Right)) + 1;
    x->Height = max(height(x->Left), height(x->Right)) + 1;
    return x;
}

Node* leftRotate(Node* x)//левый поворт дерева для балансировки
{
    Node* y = x->Right;
    Node* T2 = y->Left;
    y->Left = x;
    x->Right = T2;
    x->Height = max(height(x->Left), height(x->Right)) + 1;
    y->Height = max(height(y->Left), height(y->Right)) + 1;
    return y;
}

int getBalance(Node* N) //балансировка
{
    if (N == 0)
    {
        return 0;
    }
    return height(N->Left) - height(N->Right);
}

Node* insert(Node* node, int key) //добавление
{
    if (node == 0)
    {
        return(newNode(key));
    }

    if (key < node->Data)
    {
        node->Left = insert(node->Left, key);
    }
    else if (key > node->Data)
    {
        node->Right = insert(node->Right, key);
    }
    else
    {
        return node;
    }
    node->Height = 1 + max(height(node->Left), height(node->Right));
    int balance = getBalance(node);
    if (balance > 1 && key < node->Left->Data)
    {
        return rightRotate(node);
    }
    if (balance < -1 && key > node->Right->Data)
    {
        return leftRotate(node);
    }
    if (balance > 1 && key > node->Left->Data)
    {
        node->Left = leftRotate(node->Left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->Right->Data)
    {
        node->Right = rightRotate(node->Right);
        return leftRotate(node);
    }
    return node;
}

Node* genirate(int k) //генирация случайных чисел
{
    Node* node = 0;
    int n;
    for (int i = 0; i < k; i++)
    {
        n = 1 + rand() % 10;
        node = insert(node, n);
    }
    return node;
}

void get_line(const Node* root, int depth, vector<int>& vec)
{
    int PPP = 9999;
    if (depth <= 0 && root != 0)
    {
        vec.push_back(root->Data);
        return;
    }
    if (root->Left != 0)
    {
        get_line(root->Left, depth - 1, vec);
    }
    else if (depth - 1 <= 0)
    {
        vec.push_back(PPP); // Вставка разделителя
    }
    if (root->Right != 0)
    {
        get_line(root->Right, depth - 1, vec);
    }
    else if (depth - 1 <= 0)
    {
        vec.push_back(PPP); // Вставка разделителя
    }
}

void print(const Node* node, const int height, int depth) // Функция печати дерева
{
    int PPP = 9999;
    vector<int> vec;
    get_line(node, depth, vec); // Получение строки
    cout << setw((height - depth) * 2.5); // Настройка параметров вывода относительно размера
    bool flag = true;
    if (vec.size() > 1)
    {
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i] != PPP)
            {
                if (flag)
                {
                    cout << "/" << "     ";
                }
                else
                {
                    cout << "\\" << "     ";
                }
            }
            flag = !flag;
        }
        cout << endl << setw((height - depth) * 2.5);
    }
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] != PPP)
        {
            cout << vec[i] << "     ";
        }
    }
    cout << endl;
}
void Show_tree(Node* node)
{
    int h = height(node) * 2;
    for (int i = 0; i < h; i++)
    {
        print(node, h, i);
    }
}
Node* Node_Max(const Node* n, int& max, int& count)
{
    if (n == 0) //если дерево пустое
    {
        return 0; //ничего не отображать
    }
    else
    {
        int m, c;
        max = n->Data;
        count = 1;
        if (n->Left)
        {
            Node_Max(n->Left, m, c); //поиск в левом ответвлении
            if (m > max)
            {
                max = m;
                count = c;
            }
            else if (m == max)
            {
                count = count + c;
            }
        }
        if (n->Right)
        {
            Node_Max(n->Right, m, c); //поиск в правом ответвтлении
            if (m > max)
            {
                max = m;
                count = c;
            }
            else if (m == max)
            {
                count = count + c;
            }
        }
    }
}

