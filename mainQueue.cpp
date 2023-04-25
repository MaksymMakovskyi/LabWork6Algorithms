#include <iostream>
#include <fstream>
#include <queue>
#include <string>

using namespace std;

struct CityQueue {
    queue<string> cities;

    // ��������� ������ ���� �� ���� �����
    void addCity(string city) {
        cities.push(city);
    }

    // ��������� ������� ���� � �����
    void removeFirstCity() {
        if (!cities.empty()) {
            cities.pop();
        }
        else {
            cout << "Queue is empty.\n";
        }
    }

    // ³���������� ���������� ��� ����� ���� �� �������
    void displayFirstCity() {
        if (!cities.empty()) {
            cout << cities.front() << endl;
        }
        else {
            cout << "Queue is empty.\n";
        }
    }

    // ³���������� ���������� ��� ������ ���� �� �������
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

    // ��������� �񳺿 ���������� � ����� �� �������
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

    // ���������� ����� � �����
    ifstream inputFile(fileName);
    string city;
    while (getline(inputFile, city)) {
        cityQueue.addCity(city);
    }
    inputFile.close();

    int choice = 0;
    while (choice != 6) {
        cout << "\n����i�� �i�:" << endl;
        cout << "1. ������ ���� �i���" << endl;
        cout << "2. �������� ����� �i���" << endl;
        cout << "3. �������� ����� �i���" << endl;
        cout << "4. �������� ������ �i���" << endl;
        cout << "5. �������� ��i �i���" << endl;
        cout << "6. ��������� ������ ��������" << endl;

        cin >> choice;

        switch (choice) {
        case 1: {
            string newCity;
            cout << "����i�� ����� ������ �i���: ";
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
            cout << "������������ ���i�. ��������� �� ���." << endl;
            break;
        }
        }
    }

    // ����� ����� � ����
    ofstream outputFile(fileName);
    queue<string> temp = cityQueue.cities;
    while (!temp.empty()) {
        outputFile << temp.front() << endl;
        temp.pop();
    }
    outputFile.close();

    return 0;
}