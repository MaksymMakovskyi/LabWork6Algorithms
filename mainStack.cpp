#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

int main() {
    stack<string> cities;
    int choice;
    string city;
    int position;
    string filename = "cities.txt"; // Файл
    ifstream input(filename);
    ofstream output(filename, ios::app);

    // Зчитування міст з файлу
    while (getline(input, city)) {
        cities.push(city);
    }

    while (true) {
        cout << "\nSelect an action:\n";
        cout << "1. Add city\n2. Delete city\n3. Display city\n4. Display all cities\n5. Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            // Додавання елемента в стек
            cout << "Enter city name: ";
            cin >> city;
            cities.push(city);
            output << city << endl; // Запис міст до файлу
            break;
        case 2:
            // Видалення елементу зі стеку
            if (!cities.empty()) {
                cities.pop();
                cout << "City deleted.\n";
            }
            else {
                cout << "Stack is empty.\n";
            }
            break;
        case 3:
            // Виведення в консоль інформації, яка зберігається в даному елементі стеку
            if (!cities.empty()) {
                cout << "Top city: " << cities.top() << endl;
            }
            else {
                cout << "Stack is empty.\n";
            }
            break;
        case 4:
            // Виведення в консоль інформації, яка зберігається в усіх елементах стеку
            if (!cities.empty()) {
                stack<string> temp = cities;
                while (!temp.empty()) {
                    cout << temp.top() << endl;
                    temp.pop();
                }
            }
            else {
                cout << "Stack is empty.\n";
            }
            break;
        case 5:
            // Завершення роботи програми
            input.close();
            output.close();
            return 0;
        default:
            cout << "Invalid choice.\n";
        }
    }
    return 0;
}
