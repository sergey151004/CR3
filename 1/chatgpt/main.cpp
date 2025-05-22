/* Продолжение задания: Генератор паролей */

#include <iostream>
#include "PasswordGenerator.h"

int main() {
	std::cout << "Выберите уровень сложности пароля:\n";
	std::cout << "1 - Лёгкий (только строчные буквы)\n";
	std::cout << "2 - Средний (буквы + цифры)\n";
	std::cout << "3 - Сложный (буквы + цифры + символы)\n";
	std::cout << "Введите уровень сложности (1-3): ";

	int level = 0;
	if (!(std::cin >> level)) {
		std::cerr << "Ошибка: введено не число.\n";
		return 1;
	}

	if (level < 1 || level > 3) {
		std::cerr << "Ошибка: уровень сложности должен быть от 1 до 3.\n";
		return 1;
	}

	PasswordGenerator generator;

	std::string password;
	if (!generator.GeneratePassword(level, password)) {
		std::cerr << "Ошибка при генерации пароля.\n";
		return 1;
	}

	std::cout << "Сгенерированный пароль: " << password << "\n";

	return 0;
}
