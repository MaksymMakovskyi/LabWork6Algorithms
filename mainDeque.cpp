#include <iostream>
#include <fstream>
#include <string>
#include <deque>

using namespace std;

int main() {
    setlocale(LC_ALL, "ukr");
    deque<string> cities; // Створюємо динамічну структуру Deque
    string line;
    ifstream input("cities.txt"); // Вхідний файл

    // Зчитуємо дані із файлу
    while (getline(input, line)) {
        cities.push_back(line);
    }
    input.close();

    int choice = 0;

    while (choice != 8) {
        cout << "\nВведiть 1 для додавання нового елементу до початку структури" << endl;
        cout << "Введiть 2 для додавання нового елементу до кiнця структури" << endl;
        cout << "Введiть 3 для видалення першого елемента зi структури" << endl;
        cout << "Введiть 4 для видалення останнього елемента зi структури" << endl;
        cout << "Введiть 5 для виведення iнформацiї про перший елемент на консоль" << endl;
        cout << "Введiть 6 для виведення iнформацiї про останнiй елемент на консоль" << endl;
        cout << "Введiть 7 для виведення всього вмiсту структури на консоль" << endl;
        cout << "Введiть 8 для завершення роботи програми" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            // Додавання нового елемента до початку структури
            cout << "Введiть назву мiста: ";
            cin.ignore();
            getline(cin, line);
            cities.push_front(line);
            break;
        case 2:
            // Додавання нового елемента до кінця структури
            cout << "Введiть назву мiста: ";
            cin.ignore();
            getline(cin, line);
            cities.push_back(line);
            break;
        case 3:
            // Видалення першого елемента з структури
            if (!cities.empty()) {
                cout << "Видалено: " << cities.front() << endl;
                cities.pop_front();
            }
            else {
                cout << "Структура порожня" << endl;
            }
            break;
        case 4:
            // Видалення останнього елемента з структури
            if (!cities.empty()) {
                cout << "Видалено: " << cities.back() << endl;
                cities.pop_back();
            }
            else {
                cout << "Структура порожня" << endl;
            }
            break;
        case 5:
            // Виведення інформації про перший елемент на консоль
            if (!cities.empty()) {
                cout << "Перший елемент: " << cities.front() << endl;
            }
            else {
                cout << "Структура порожня" << endl;
            }
            break;
        case 6:
            // Виведення інформації про останній елемент на консоль
            if (!cities.empty()) {
                cout << "Останнiй елемент: " << cities.back() << endl;
            }
            else {
                cout << "Структура порожня" << endl;
            }
            break;
        case 7:
            // Виведення всього вмісту структури на консоль
            cout << "Весь вмiст:" << endl;
            if (!cities.empty()) {
                for (const string& city : cities) {
                    cout << city << endl;
                }
            }
            else {
                cout << "Структура порожня" << endl;
            }
            break;
        case 8: {
            // Завершення роботи програми
            break;
        }
        default: {
            cout << "Неправильний вибiр" << endl;
            break;
        }
        }
    }
    // Записуємо дані назад у файл
    ofstream output("cities.txt");
    for (const string& city : cities) {
        output << city << endl;
    }
    output.close();

    return 0;
}