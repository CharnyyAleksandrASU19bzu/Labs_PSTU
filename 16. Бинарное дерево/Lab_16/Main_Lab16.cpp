#include <iostream>
#include <iomanip>
#include <vector>
#include "Node.h"
using namespace std;


int main()
{
    setlocale(LC_ALL, "Rus");
    Node* root = 0;
    int k, max, count;
    int menu;
    do {
        cout << "1. Создать новое дерево" << endl;
        cout << "2. Просмотр дерева" << endl;
        cout << "3. Вывести максимальный элемент дерева" << endl;
        cout << "0. Выход" << endl;
        cout << "> ";
        cin >> menu;
        switch (menu) {
        case 1:
            cout << "Введите количество элементов : ";
            cin >> k;
            root = genirate(k);
            break;
        case 2:
            Show_tree(root);
            break;
        case 3:
            Node_Max(root, max, count);
            cout << endl << "Максимальны элемент : " << max << endl;
            break;
        }
    } while (menu != 0);
}