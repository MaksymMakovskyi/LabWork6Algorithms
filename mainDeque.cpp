#include <iostream>
#include <fstream>
#include <string>
#include <deque>

using namespace std;

int main() {
    setlocale(LC_ALL, "ukr");
    deque<string> cities; // ��������� �������� ��������� Deque
    string line;
    ifstream input("cities.txt"); // ������� ����

    // ������� ��� �� �����
    while (getline(input, line)) {
        cities.push_back(line);
    }
    input.close();

    int choice = 0;

    while (choice != 8) {
        cout << "\n����i�� 1 ��� ��������� ������ �������� �� ������� ���������" << endl;
        cout << "����i�� 2 ��� ��������� ������ �������� �� �i��� ���������" << endl;
        cout << "����i�� 3 ��� ��������� ������� �������� �i ���������" << endl;
        cout << "����i�� 4 ��� ��������� ���������� �������� �i ���������" << endl;
        cout << "����i�� 5 ��� ��������� i�������i� ��� ������ ������� �� �������" << endl;
        cout << "����i�� 6 ��� ��������� i�������i� ��� ������i� ������� �� �������" << endl;
        cout << "����i�� 7 ��� ��������� ������ ��i��� ��������� �� �������" << endl;
        cout << "����i�� 8 ��� ���������� ������ ��������" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            // ��������� ������ �������� �� ������� ���������
            cout << "����i�� ����� �i���: ";
            cin.ignore();
            getline(cin, line);
            cities.push_front(line);
            break;
        case 2:
            // ��������� ������ �������� �� ���� ���������
            cout << "����i�� ����� �i���: ";
            cin.ignore();
            getline(cin, line);
            cities.push_back(line);
            break;
        case 3:
            // ��������� ������� �������� � ���������
            if (!cities.empty()) {
                cout << "��������: " << cities.front() << endl;
                cities.pop_front();
            }
            else {
                cout << "��������� �������" << endl;
            }
            break;
        case 4:
            // ��������� ���������� �������� � ���������
            if (!cities.empty()) {
                cout << "��������: " << cities.back() << endl;
                cities.pop_back();
            }
            else {
                cout << "��������� �������" << endl;
            }
            break;
        case 5:
            // ��������� ���������� ��� ������ ������� �� �������
            if (!cities.empty()) {
                cout << "������ �������: " << cities.front() << endl;
            }
            else {
                cout << "��������� �������" << endl;
            }
            break;
        case 6:
            // ��������� ���������� ��� ������� ������� �� �������
            if (!cities.empty()) {
                cout << "������i� �������: " << cities.back() << endl;
            }
            else {
                cout << "��������� �������" << endl;
            }
            break;
        case 7:
            // ��������� ������ ����� ��������� �� �������
            cout << "���� ��i��:" << endl;
            if (!cities.empty()) {
                for (const string& city : cities) {
                    cout << city << endl;
                }
            }
            else {
                cout << "��������� �������" << endl;
            }
            break;
        case 8: {
            // ���������� ������ ��������
            break;
        }
        default: {
            cout << "������������ ���i�" << endl;
            break;
        }
        }
    }
    // �������� ��� ����� � ����
    ofstream output("cities.txt");
    for (const string& city : cities) {
        output << city << endl;
    }
    output.close();

    return 0;
}