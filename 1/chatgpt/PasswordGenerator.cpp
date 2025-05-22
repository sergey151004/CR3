/* Продолжение задания: Генератор паролей */

#include "PasswordGenerator.h"
#include <random>
#include <ctime>

/**
 * @brief Генерирует пароль на основе выбранного уровня сложности.
 */
bool PasswordGenerator::GeneratePassword(int level, std::string& password) const {
	if (level < 1 || level > 3) {
		return false;
	}

	const std::string charset = GetCharacterSet(level);
	const int length = GetPasswordLength(level);

	if (charset.empty() || length <= 0) {
		return false;
	}

	password.clear();
	std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));
	std::uniform_int_distribution<size_t> dist(0, charset.length() - 1);

	for (int i = 0; i < length; ++i) {
		// auto используется здесь для итератора - тип char из charset
		auto ch = charset[dist(rng)];  // char
		password += ch;
	}

	return true;
}

/**
 * @brief Возвращает строку допустимых символов для заданного уровня.
 */
std::string PasswordGenerator::GetCharacterSet(int level) const {
	switch (level) {
	case 1:
		return "abcdefghijklmnopqrstuvwxyz";
	case 2:
		return "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	case 3:
		return "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_=+[]{}<>?";
	default:
		return "";
	}
}

/**
 * @brief Возвращает длину пароля для заданного уровня.
 */
int PasswordGenerator::GetPasswordLength(int level) const {
	switch (level) {
	case 1:
		return 8;
	case 2:
		return 12;
	case 3:
		return 16;
	default:
		return 0;
	}
}
