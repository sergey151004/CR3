#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "PasswordGenerator.h"

int main() {
    int level;
    std::cout << "�������� ������� ��������� ������ (1 - �������, 2 - �������, 3 - �������): ";
    std::cin >> level;

    if (level < 1 || level > 3) {
        std::cerr << "������: �������� ������� ���������." << std::endl;
        return 1;
    }

    PasswordGenerator generator;
    std::string password = generator.generatePassword(level);
    std::cout << "��������������� ������: " << password << std::endl;

    return 0;
}
