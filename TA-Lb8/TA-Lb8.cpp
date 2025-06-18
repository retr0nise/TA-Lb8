#include <iostream>
#include "Search.h"
#include <windows.h>

using namespace std;

void handleInvalidInput() {
    cout << "�� ����� ������� �������! ��������� �� ���!!";
    system("pause");
}

int main()
{
    SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
    SearchTree<int, int> tree;

    bool isContinue = true;
    while (isContinue) {
        system("cls");
        cout << "1. ������ �������" << endl;
        cout << "2. ׳ ������ �������" << endl;
        cout << "3. ����� �������" << endl;
        cout << "4. �������� �������" << endl;
        cout << "5. ������� ������ ������" << endl;
        cout << "6. ������� ������� �����" << endl;
        cout << "7. ���������� ��� ������ ������" << endl;
        cout << "8. ���������� ������" << endl;
        cout << "���� ������: " << tree << endl;
        cout << "ʳ������ ��������: " << tree.getCount() << endl;
        cout << "\n������ �������: ";
        char command = 0;
        cin >> command;
        int value = 0;
        switch (command) {
        case '1':
            cout << "������ ��������: ";
            cin >> value;
            try
            {
                                                     tree.add(value, value);
            }
			catch (const std::invalid_argument& e)
			{
                std::cout << e.what() << std::endl;
				system("pause");
			}
            break;
        case '2':
            cout << "������ ��������: ";
            cin >> value;
            cout << "���������: " << tree.isContains(value) << endl;
            system("pause");
            break;
        case '3':
            cout << "�������� �����: ";
            cin >> value;
            try
            {
                 cout << "�������� ��������: " << tree.peek(value) << endl;
            }
            catch (const std::invalid_argument& e)
            {
                std::cout << e.what() << std::endl;
               
            }
            system("pause");
            break;
        case '4':
            cout << "�������� �������: ";
            cin >> value;          
            try
            {
                 tree.remove(value);
            }
            catch (const std::invalid_argument& e)
            {
                std::cout << e.what() << std::endl;
                system("pause");
            }
            break;
        case '5':
            cout << "������ ������: " << tree.getHeight() << endl;
            system("pause");
            break;
        case '6':
            cout << "������ ����: ";
            cin >> value;
            cout << "������� " << '[' << value << ']' << " ��������: " << tree.getDepth(value) << endl;
            system("pause");
            break;
        case '7':
            cout << "������:" << endl;
            cout << "1. �����" << endl;
            cout << "2. ���������" << endl;
            cout << "3. ����������" << endl;
            cout << "������ ��������: ";
            cin >> value;
            value--;
            if (value < 0 || value > 2) {
                cout << "������ �������� - " << value << endl;
                system("pause");
            }
            else {
                tree.setAroundMode(value);
                system("pause");
            }
            break;
        case '8':
            isContinue = false;
            break;
        default: handleInvalidInput();
            break;
        }
    }

    return 0;
}