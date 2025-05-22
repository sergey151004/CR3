/* Продолжение задания: Генератор паролей */

#ifndef PASSWORD_GENERATOR_H
#define PASSWORD_GENERATOR_H

#include <string>

/**
 * @brief Класс генерации паролей на трёх уровнях сложности.
 */
class PasswordGenerator {
public:
	/**
	 * @brief Генерирует пароль на основе выбранного уровня сложности.
	 * 
	 * @param level Уровень сложности (1 - лёгкий, 2 - средний, 3 - сложный)
	 * @param password Ссылка на строку, куда будет записан результат
	 * @return true - если генерация успешна, false - при ошибке входных данных
	 */
	bool GeneratePassword(int level, std::string& password) const;

private:
	/**
	 * @brief Возвращает строку допустимых символов для заданного уровня.
	 * 
	 * @param level Уровень сложности
	 * @return Набор символов, допустимых на этом уровне
	 */
	std::string GetCharacterSet(int level) const;

	/**
	 * @brief Возвращает длину пароля для заданного уровня.
	 * 
	 * @param level Уровень сложности
	 * @return Длина пароля
	 */
	int GetPasswordLength(int level) const;
};

#endif  // PASSWORD_GENERATOR_H
