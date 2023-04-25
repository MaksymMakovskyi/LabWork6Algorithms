#include <iostream>
#include <fstream>
#include <queue>
#include <string>

using namespace std;

struct CityQueue {
    queue<string> cities;

    // Додавання нового міста до кінця черги
    void addCity(string city) {
        cities.push(city);
    }

    // Видалення першого міста з черги
    void removeFirstCity() {
        if (!cities.empty()) {
            cities.pop();
        }
        else {
            cout << "Queue is empty.\n";
        }
    }

    // Відображення інформації про перше місто на консоль
    void displayFirstCity() {
        if (!cities.empty()) {
            cout << cities.front() << endl;
        }
        else {
            cout << "Queue is empty.\n";
        }
    }

    // Відображення інформації про останнє місто на консоль
    void displayLastCity() {
        if (!cities.empty()) {
            queue<string> temp = cities;
            string lastCity;
            while (!temp.empty()) {
                lastCity = temp.front();
                temp.pop();
            }
            cout << lastCity << endl;
        }
        else {
            cout << "Queue is empty.\n";
        }
    }

    // Виведення всієї інформації з черги на консоль
    void displayAllCities() {
        queue<string> temp = cities;
        while (!temp.empty()) {
            cout << temp.front() << endl;
            temp.pop();
        }
    }
};

int main() {
    setlocale(LC_ALL, "ukr");
    CityQueue cityQueue;

    string fileName = "cities.txt";

    // Зчитування даних з файлу
    ifstream inputFile(fileName);
    string city;
    while (getline(inputFile, city)) {
        cityQueue.addCity(city);
    }
    inputFile.close();

    int choice = 0;
    while (choice != 6) {
        cout << "\nОберiть дiю:" << endl;
        cout << "1. Додати нове мiсто" << endl;
        cout << "2. Видалити перше мiсто" << endl;
        cout << "3. Показати перше мiсто" << endl;
        cout << "4. Показати останнє мiсто" << endl;
        cout << "5. Показати всi мiста" << endl;
        cout << "6. Завершити роботу програми" << endl;

        cin >> choice;

        switch (choice) {
        case 1: {
            string newCity;
            cout << "Введiть назву нового мiста: ";
            cin.ignore();
            getline(cin, newCity);
            cityQueue.addCity(newCity);
            break;
        }
        case 2: {
            cityQueue.removeFirstCity();
            break;
        }
        case 3: {
            cityQueue.displayFirstCity();
            break;
        }
        case 4: {
            cityQueue.displayLastCity();
            break;
        }
        case 5: {
            cityQueue.displayAllCities();
            break;
        }
        case 6: {
            break;
        }
        default: {
            cout << "Неправильний вибiр. Спробуйте ще раз." << endl;
            break;
        }
        }
    }

    // Запис даних у файл
    ofstream outputFile(fileName);
    queue<string> temp = cityQueue.cities;
    while (!temp.empty()) {
        outputFile << temp.front() << endl;
        temp.pop();
    }
    outputFile.close();

    return 0;
}