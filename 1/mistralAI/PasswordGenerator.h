#ifndef PASSWORDGENERATOR_H
#define PASSWORDGENERATOR_H

#include <string>

/**
 * @class PasswordGenerator
 * @brief Класс для генерации паролей различной сложности.
 */
class PasswordGenerator {
public:
    /**
     * @brief Генерирует пароль заданного уровня сложности.
     * @param level Уровень сложности пароля (1 - простой, 2 - средний, 3 - сложный).
     * @return Сгенерированный пароль.
     */
    std::string generatePassword(int level);
};

#endif // PASSWORDGENERATOR_H
