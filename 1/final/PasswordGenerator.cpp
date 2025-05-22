/**
 * @file   PasswordGenerator.cpp
 * @brief  Реализация генератора паролей.
 */

#include "PasswordGenerator.h"
#include <random>
#include <iostream>

bool generatePassword(std::string& password, int length, const std::string& symbols) {
    if (length <= 0) {
        std::cerr << "Ошибка: длина пароля должна быть положительной.\n";
        return false;
    }
    if (symbols.empty()) {
        std::cerr << "Ошибка: набор символов не может быть пустым.\n";
        return false;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, static_cast<int>(symbols.size() - 1));

    password.reserve(length);
    for (int i = 0; i < length; ++i) {
        password += symbols[distr(gen)];
    }
    return true;
}