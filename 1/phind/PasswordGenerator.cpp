// PasswordGenerator.cpp
#include "PasswordGenerator.h"
#include <random>
#include <ctime>

// Инициализация констант
const int PasswordGenerator::EASY_LENGTH = 8;
const int PasswordGenerator::MEDIUM_LENGTH = 12;
const int PasswordGenerator::STRONG_LENGTH = 16;

const std::string PasswordGenerator::LOWERCASE = "abcdefghijklmnopqrstuvwxyz";
const std::string PasswordGenerator::UPPERCASE = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string PasswordGenerator::NUMBERS = "0123456789";
const std::string PasswordGenerator::SPECIAL_CHARS = "!@#$%^&*()_+-=[]{}|;:,.<>?";

std::mt19937 PasswordGenerator::rng_;  // Статический генератор случайных чисел

char PasswordGenerator::getRandomChar(const std::string& chars) {
    std::uniform_int_distribution<int> distribution(0, chars.length() - 1);
    return chars[distribution(rng_)];
}

std::string PasswordGenerator::ensureCharacterTypes(std::string password, const std::string& chars) {
    for (char c : chars) {
        if (password.find(c) == std::string::npos) {
            size_t pos = std::uniform_int_distribution<size_t>(0, password.length())(rng_);
            password.insert(pos, 1, c);
        }
    }
    return password;
}

std::string PasswordGenerator::generatePassword(Level level) {
    // Инициализация генератора при первом использовании
    static bool firstTime = true;
    if (firstTime) {
        rng_.seed(static_cast<unsigned int>(time(nullptr)));
        firstTime = false;
    }

    int length;
    std::string availableChars;

    switch (level) {
        case Level::EASY:
            length = EASY_LENGTH;
            availableChars = LOWERCASE + UPPERCASE;
            break;
        case Level::MEDIUM:
            length = MEDIUM_LENGTH;
            availableChars = LOWERCASE + UPPERCASE + NUMBERS;
            break;
        case Level::STRONG:
            length = STRONG_LENGTH;
            availableChars = LOWERCASE + UPPERCASE + NUMBERS + SPECIAL_CHARS;
            break;
        default:
            throw std::invalid_argument("Некорректный уровень сложности пароля");
    }

    std::string password;
    password.reserve(length);

    // Генерация базового пароля
    std::uniform_int_distribution<int> distribution(0, availableChars.length() - 1);
    for (int i = 0; i < length; ++i) {
        password += availableChars[distribution(rng_)];
    }

    // Обеспечение наличия всех типов символов
    std::string charsToEnsure;
    switch (level) {
        case Level::EASY:
            charsToEnsure = LOWERCASE.substr(0, 1) + UPPERCASE.substr(0, 1);
            break;
        case Level::MEDIUM:
            charsToEnsure = LOWERCASE.substr(0, 1) + UPPERCASE.substr(0, 1) + NUMBERS.substr(0, 1);
            break;
        case Level::STRONG:
            charsToEnsure = LOWERCASE.substr(0, 1) + UPPERCASE.substr(0, 1) +
                          NUMBERS.substr(0, 1) + SPECIAL_CHARS.substr(0, 1);
            break;
    }

    return ensureCharacterTypes(password, charsToEnsure);
}