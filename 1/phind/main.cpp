// main.cpp
/**
 * @file main.cpp
 * @brief ��������� ��� ��������� ������� ������ ���������
 */

#include "PasswordGenerator.h"
#include <iostream>

int main() {
    try {
        while (true) {
            std::cout << "\n�������� ������� ��������� ������:\n";
            std::cout << "1. ������ (8 ��������)\n";
            std::cout << "2. ������� (12 ��������)\n";
            std::cout << "3. ������� (16 ��������)\n";
            std::cout << "4. �����\n";

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
                    std::cerr << "������������ �����!\n";
                    continue;
            }

            std::string password = PasswordGenerator::generatePassword(level);
            std::cout << "\n��������������� ������: " << password << '\n';
        }
    } catch (const std::exception& e) {
        std::cerr << "������: " << e.what() << '\n';
        return 1;
    }

    return 0;
}