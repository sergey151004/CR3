/**
 * @file   PasswordGenerator.h
 * @brief  Заголовочный файл для генератора паролей.
 * @brief  Продолжение задания №Генератор паролей
 */

#pragma once
#include <string>

 /**
  * @brief Генерирует пароль указанной длины из заданного набора символов.
  * @param[out] password Ссылка для сохранения сгенерированного пароля.
  * @param[in] length Длина пароля (должна быть > 0).
  * @param[in] symbols Набор допустимых символов (не должен быть пустым).
  * @return true - пароль успешно сгенерирован, false - ошибка валидации.
  */
bool generatePassword(std::string& password, int length, const std::string& symbols);