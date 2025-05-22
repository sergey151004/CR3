// PasswordGenerator.h
#ifndef PASSWORDGENERATOR_H_
#define PASSWORDGENERATOR_H_

/**
 * @file PasswordGenerator.h
 * @brief Класс для генерации паролей разной сложности
 * @author [Ваше имя]
 */

#include <string>
#include <random>

class PasswordGenerator {
public:
    /**
     * Уровни сложности пароля
     */
    enum class Level {
        EASY = 8,
        MEDIUM = 12,
        STRONG = 16
    };

    /**
     * Генерирует случайный пароль указанной сложности
     * @param level желаемый уровень сложности
     * @return сгенерированный пароль
     * @throws std::invalid_argument если уровень сложности некорректен
     */
    static std::string generatePassword(Level level);

private:
    // Константы для длин паролей разных уровней
    static const int EASY_LENGTH;
    static const int MEDIUM_LENGTH;
    static const int STRONG_LENGTH;

    // Наборы символов для генерации
    static const std::string LOWERCASE;
    static const std::string UPPERCASE;
    static const std::string NUMBERS;
    static const std::string SPECIAL_CHARS;

    /**
     * Получает случайный символ из заданной строки
     * @param chars строка с доступными символами
     * @return случайный символ из строки
     */
    static char getRandomChar(const std::string& chars);

    /**
     * Обеспечивает наличие всех необходимых типов символов в пароле
     * @param password текущий пароль
     * @param chars набор символов для дополнения
     * @return обновленный пароль с гарантированным наличием всех типов символов
     */
    static std::string ensureCharacterTypes(std::string password, const std::string& chars);
};

#endif  // PASSWORDGENERATOR_H_