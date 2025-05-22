// main.cpp
/**
 * @file main.cpp
 * @brief Программа для генерации паролей разной сложности
 */

#include "PasswordGenerator.h"
#include <iostream>

int main() {
    try {
        while (true) {
            std::cout << "\nВыберите уровень сложности пароля:\n";
            std::cout << "1. Легкий (8 символов)\n";
            std::cout << "2. Средний (12 символов)\n";
            std::cout << "3. Сложный (16 символов)\n";
            std::cout << "4. Выход\n";

            int choice;
            std::cin >> choice;

            if (choice == 4) {
                break;
            }

            PasswordGenerator::Level level;
            switch (choice) {
                case 1:
                    level = PasswordGenerator::Level::EASY;
                    break;
                case 2:
                    level = PasswordGenerator::Level::MEDIUM;
                    break;
                case 3:
                    level = PasswordGenerator::Level::STRONG;
                    break;
                default:
                    std::cerr << "Некорректный выбор!\n";
                    continue;
            }

            std::string password = PasswordGenerator::generatePassword(level);
            std::cout << "\nСгенерированный пароль: " << password << '\n';
        }
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << '\n';
        return 1;
    }

    return 0;
}