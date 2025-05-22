/**
 * @file   main.cpp
 * @brief  �������� ������ ���������� �������.
 * @brief  ����������� ������� ��������� �������
 */

#include "PasswordGenerator.h"
#include <iostream>
#include <limits>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "");

    int level = 0;
    int lengths[] = { 8, 12, 16 };
    string symbols[] = {
        "abcdefghijklmnopqrstuvwxyz",
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789",
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=[]{}|;:',.<>?"
    };

    cout << "�������� ������� ���������:\n"
        << "1. ������ (8 ��������, �����)\n"
        << "2. ������� (12 ��������, �����+�����)\n"
        << "3. ������� (16 ��������, ��� �������)\n";

    while (true) {
        cout << "��� ����� (1-3): ";
        if (cin >> level && level >= 1 && level <= 3) break;

        cerr << "������: ������� ����� �� 1 �� 3\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string password;
    bool success = generatePassword(password, lengths[level - 1], symbols[level - 1]);

    if (success) {
        cout << "\n��������������� ������: " << password << endl;
        return 0;
    }
    else {
        cerr << "�� ������� ������������� ������.\n";
        return 1;
    }
}