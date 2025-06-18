#include <iostream>
#include "Search.h"
#include <windows.h>

using namespace std;

void handleInvalidInput() {
    cout << "Âè ââåëè íåä³éñídваó! Ñïðîáóéòå ùå ðàç!!";
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
        cout << "1. Äîäàòè åëåìåíò" << endl;
        cout << "2. ×³ ì³ñòèòü åëåìåíò" << endl;
        cout << "3. Âçÿòè åëåìåíò" << endl;
        cout << "4. Âèäàëèòè åëåìåíò" << endl;
        cout << "5. Âèâåñòè âèñîòó äåðåâà" << endl;
        cout << "6. Âèâåñòè ãëèáèíó Âóçëà" << endl;
        cout << "7. Âñòàíîâèòè òèï îáõîäó äåðåâà" << endl;
        cout << "8. Çàâåðøåííÿ ðîáîòè" << endl;
        cout << "Âàøå äåðåâî: " << tree << endl;
        cout << "Ê³ëüê³ñòü åëåìåíò³â: " << tree.getCount() << endl;
        cout << "\nÂâåä³òü êîìàíäó: ";
        char command = 0;
        cin >> command;
        int value = 0;
        switch (command) {
        case '1':
            cout << "Ââåä³òü çíà÷åííÿ: ";
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
            cout << "Ââåä³òü çíà÷åííÿ: ";
            cin >> value;
            cout << "ðåçóëüòàò: " << tree.isContains(value) << endl;
            system("pause");
            break;
        case '3':
            cout << "Çíà÷åííÿ âóçëà: ";
            cin >> value;
            try
            {
                 cout << "Çíà÷åííÿ åëåìåíòà: " << tree.peek(value) << endl;
            }
            catch (const std::invalid_argument& e)
            {
                std::cout << e.what() << std::endl;
               
            }
            system("pause");
            break;
        case '4':
            cout << "Âèäàëèòè åëåìåíò: ";
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
            cout << "Âèñîòà äåðåâà: " << tree.getHeight() << endl;
            system("pause");
            break;
        case '6':
            cout << "Ââåä³òü êëþ÷: ";
            cin >> value;
            cout << "Ãëèáèíà " << '[' << value << ']' << " Åëåìåíòà: " << tree.getDepth(value) << endl;
            system("pause");
            break;
        case '7':
            cout << "Ðåæèìè:" << endl;
            cout << "1. Ïðÿìî" << endl;
            cout << "2. Çâîðîòíüî" << endl;
            cout << "3. Ñèìåòðè÷íî" << endl;
            cout << "Ââåä³òü çíà÷åííÿ: ";
            cin >> value;
            value--;
            if (value < 0 || value > 2) {
                cout << "Íåâ³ðíå çíà÷åííÿ - " << value << endl;
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
