/**
 * @file   main.cpp
 * @brief  Основной модуль генератора паролей.
 * @brief  Продолжение задания Генератор паролей
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

    cout << "Выберите уровень сложности:\n"
        << "1. Легкий (8 символов, буквы)\n"
        << "2. Средний (12 символов, буквы+цифры)\n"
        << "3. Сложный (16 символов, все символы)\n";

    while (true) {
        cout << "Ваш выбор (1-3): ";
        if (cin >> level && level >= 1 && level <= 3) break;

        cerr << "Ошибка: введите число от 1 до 3\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string password;
    bool success = generatePassword(password, lengths[level - 1], symbols[level - 1]);

    if (success) {
        cout << "\nСгенерированный пароль: " << password << endl;
        return 0;
    }
    else {
        cerr << "Не удалось сгенерировать пароль.\n";
        return 1;
    }
}