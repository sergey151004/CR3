#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "PasswordGenerator.h"

int main() {
    int level;
    std::cout << "Выберите уровень сложности пароля (1 - простой, 2 - средний, 3 - сложный): ";
    std::cin >> level;

    if (level < 1 || level > 3) {
        std::cerr << "Ошибка: неверный уровень сложности." << std::endl;
        return 1;
    }

    PasswordGenerator generator;
    std::string password = generator.generatePassword(level);
    std::cout << "Сгенерированный пароль: " << password << std::endl;

    return 0;
}
