#include "PasswordGenerator.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

/**
 * @brief Генерирует пароль заданного уровня сложности.
 * @param level Уровень сложности пароля (1 - простой, 2 - средний, 3 - сложный).
 * @return Сгенерированный пароль.
 */
std::string PasswordGenerator::generatePassword(int level) {
    std::string lowercase = "abcdefghijklmnopqrstuvwxyz";
    std::string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string digits = "0123456789";
    std::string symbols = "!@#$%^&*()_+-=[]{}|;:,.<>?";

    std::string charset;
    int length;

    switch (level) {
        case 1:
            charset = lowercase;
            length = 8;
            break;
        case 2:
            charset = lowercase + uppercase + digits;
            length = 12;
            break;
        case 3:
            charset = lowercase + uppercase + digits + symbols;
            length = 16;
            break;
        default:
            std::cerr << "Ошибка: неверный уровень сложности." << std::endl;
            return "";
    }

    std::string password;
    std::srand(std::time(0));

    for (int i = 0; i < length; ++i) {
        int index = std::rand() % charset.length();
        password += charset[index];
    }

    return password;
}
