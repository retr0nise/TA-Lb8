#include <iostream>
#include "Search.h"
#include <windows.h>

using namespace std;

void handleInvalidInput() {
    cout << "Ви ввели недійсну команду! Спробуйте ще раз!!";
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
        cout << "1. Додати елемент" << endl;
        cout << "2. Чі містить елемент" << endl;
        cout << "3. Взяти елемент" << endl;
        cout << "4. Видалити елемент" << endl;
        cout << "5. Вивести висоту дерева" << endl;
        cout << "6. Вивести глибину Вузла" << endl;
        cout << "7. Встановити тип обходу дерева" << endl;
        cout << "8. Завершення роботи" << endl;
        cout << "Ваше дерево: " << tree << endl;
        cout << "Кількість елементів: " << tree.getCount() << endl;
        cout << "\nВведіть команду: ";
        char command = 0;
        cin >> command;
        int value = 0;
        switch (command) {
        case '1':
            cout << "Введіть значення: ";
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
            cout << "Введіть значення: ";
            cin >> value;
            cout << "результат: " << tree.isContains(value) << endl;
            system("pause");
            break;
        case '3':
            cout << "Значення вузла: ";
            cin >> value;
            try
            {
                 cout << "Значення елемента: " << tree.peek(value) << endl;
            }
            catch (const std::invalid_argument& e)
            {
                std::cout << e.what() << std::endl;
               
            }
            system("pause");
            break;
        case '4':
            cout << "Видалити елемент: ";
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
            cout << "Висота дерева: " << tree.getHeight() << endl;
            system("pause");
            break;
        case '6':
            cout << "Введіть ключ: ";
            cin >> value;
            cout << "Глибина " << '[' << value << ']' << " Елемента: " << tree.getDepth(value) << endl;
            system("pause");
            break;
        case '7':
            cout << "Режими:" << endl;
            cout << "1. Прямо" << endl;
            cout << "2. Зворотньо" << endl;
            cout << "3. Симетрично" << endl;
            cout << "Введіть значення: ";
            cin >> value;
            value--;
            if (value < 0 || value > 2) {
                cout << "Невірне значення - " << value << endl;
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