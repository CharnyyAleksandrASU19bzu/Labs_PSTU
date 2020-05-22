#include <iostream>
#include <locale>
#include <list>
#include "Phoenix.h"
#include "File_work.h"
#include "List.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    system("chcp 1251");
    system("cls");

    List mainL;
    List backupL;
    Phoenix key, element;
    char file_name[30];
    char answer;
    int num, k, c;
    bool cheange = false;

    do {
        cout << "1. ������� ����� ���� ������" << endl;
        cout << "2. ������� ������������ ���� ������" << endl;
        cout << "3. �������� �����������" << endl;
        cout << "4. �������� ��������" << endl;
        cout << "5. �������������� ��������" << endl;
        cout << "6. ���������� ������ ��������" << endl;
        cout << "7. ��������� ��������" << endl;
        cout << "8. ��������� ���������" << endl;
        cout << "0. �����" << endl;
        cout << "> ";
        cin >> c;

        switch (c)
        {
        case 1: // �������� ���� ������
            if (cheange)
            {
                cout << "��������� ��������� � ������� ���� ������?" << endl;
                cout << "> ";
                cin >> answer;
                if (answer == 'Y' || answer == 'y')
                {
                    k = save_file(file_name, mainL, cheange);
                    cout << " ��������� ���������" << endl;
                }
            }
            cout << "������� ��� �����: ";
            cin >> file_name;
            k = make_file(file_name, mainL);
            if (k < 0) cout << "���������� ������� ����";
            break;

        case 2: // �������� ���� ������
            if (cheange)
            {
                cout << "��������� ��������� � ������� ���� ������?" << endl;
                cout << "> ";
                cin >> answer;
                if (answer == 'Y' || answer == 'y')
                {
                    k = save_file(file_name, mainL, cheange);
                    cout << " ��������� ���������" << endl;
                }
            }
            cout << "������� ��� ������������ �����: ";
            cin >> file_name;
            k = open_file(file_name, mainL);
            if (k == 0) cout << "���� ����" << endl;
            if (k < 0) cout << "���������� ��������� ����" << endl;
            break;

        case 3: // �������� �����������
            print_list(mainL);
            break;

        case 4: // �������� ��������
            int c4;
            do {
                cout << "1. �������� �������� �� ������" << endl;
                cout << "2. �������� �������� �� �����" << endl;
                cout << "3. �������� ��������� �������� ��������" << endl;
                cout << "0. �����" << endl;
                cout << "> ";
                cin >> c4;

                switch (c4)
                {
                case 1:
                    backup(mainL, backupL);
                    cout << "������� �����" << endl;
                    cout << "> ";
                    cin >> num;
                    del_pos(mainL, num, cheange);
                    break;

                case 2:
                    backup(mainL, backupL);
                    cout << "������� ����" << endl;
                    cout << "> ";
                    cin >> key;
                    del_key(mainL, key, cheange);
                    break;

                case 3:
                    cout << "�������� ��������� �������� ��������?" << endl;
                    cout << "> ";
                    cin >> answer;
                    if (answer == 'Y' || answer == 'y')
                    {
                        rewind(mainL, backupL);
                        cout << "�������� ��������" << endl;
                        cheange = false;
                    }
                    break;
                }

            } while (c4 != 0);
            if (c4 == 0 && cheange)
            {
                del_operation(mainL, backupL);
            }
            break;

        case 5: // �������������� ��������
            int c5;
            do {
                cout << "1. �������������� �������� �� ������" << endl;
                cout << "2. �������������� �������� �� �����" << endl;
                cout << "3. �������� ��������� �������� ��������������" << endl;
                cout << "0. �����" << endl;
                cout << "> ";
                cin >> c5;

                switch (c5)
                {
                case 1:
                    backup(mainL, backupL);
                    cout << "������� �����" << endl;
                    cout << "> ";
                    cin >> num;
                    cout << "������� ����� �������" << endl;
                    cout << "> ";
                    cin >> element;
                    change_pos(mainL, element, num, cheange);
                    break;

                case 2:
                    backup(mainL, backupL);
                    cout << "������� ����" << endl;
                    cout << "> ";
                    cin >> key;
                    cout << "������� ����� �������" << endl;
                    cout << "> ";
                    cin >> element;
                    change_key(mainL, element, key, cheange);
                    break;

                case 3:
                    cout << "�������� ��������� �������� ��������������?" << endl;
                    cout << "> ";
                    cin >> answer;
                    if (answer == 'Y' || answer == 'y')
                    {
                        rewind(mainL, backupL);
                        cout << "�������������� ��������" << endl;
                        cheange = false;
                    }
                    break;
                }
            } while (c5 != 0);
            break;

        case 6: // ���������� ������ ��������
            int c6;
            do {
                cout << "1. ���������� �������� � ������" << endl;
                cout << "2. ���������� �������� � �����" << endl;
                cout << "3. ���������� �������� � ������� � ��������� �������" << endl;
                cout << "3. �������� ��������� �������� ����������" << endl;
                cout << "0. �����" << endl;
                cout << "> ";
                cin >> c6;

                switch (c6)
                {
                case 1:
                    backup(mainL, backupL);
                    cout << "������� ����� �������" << endl;
                    cout << "> ";
                    cin >> element;
                    add_begin(mainL, element, cheange);
                    break;

                case 2:
                    backup(mainL, backupL);
                    cout << "������� ����� �������" << endl;
                    cout << "> ";
                    cin >> element;
                    add_end(mainL, element, cheange);
                    break;

                case 3:
                    backup(mainL, backupL);
                    cout << "������� �����" << endl;
                    cout << "> ";
                    cin >> num;
                    cout << "������� ����� �������" << endl;
                    cout << "> ";
                    cin >> element;
                    add_pos(mainL, element, num, cheange);
                    break;

                case 4:
                    cout << "�������� ��������� �������� ����������?" << endl;
                    cout << "> ";
                    cin >> answer;
                    if (answer == 'Y' || answer == 'y')
                    {
                        rewind(mainL, backupL);
                        cout << "���������� ��������" << endl;
                        cheange = false;
                    }
                    break;
                }
            } while (c6 != 0);
            break;
        case 7: // ��������� ��������
            int c7;
            do {
                cout << "1. ����������� ����� ���������� ��� ��� ������� �������������" << endl;
                cout << "2. ����� ������� ������� ��� ������� ������������� � ������� ���� ��������" << endl;
                cout << "0. �����" << endl;
                cout << "> ";
                cin >> c7;

                switch (c7)
                {
                case 1:
                    max_year(mainL);
                    break;
                case 2:
                    min_range(mainL);
                    break;
                }
            } while (c7 != 0);
            break;

        case 8:
            k = save_file(file_name, mainL, cheange);
            break;
        }
    } while (c != 0);
    if (c == 0 && cheange)
    {
        cout << "��������� ��������� � ������� ���� ������?" << endl;
        cout << "> ";
        cin >> answer;
        if (answer == 'Y' || answer == 'y')
        {
            k = save_file(file_name, mainL, cheange);
            cout << " ��������� ���������" << endl;
        }
    }

    return 0;
}