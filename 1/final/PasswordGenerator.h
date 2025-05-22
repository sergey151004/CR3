/**
 * @file   PasswordGenerator.h
 * @brief  ������������ ���� ��� ���������� �������.
 * @brief  ����������� ������� ���������� �������
 */

#pragma once
#include <string>

 /**
  * @brief ���������� ������ ��������� ����� �� ��������� ������ ��������.
  * @param[out] password ������ ��� ���������� ���������������� ������.
  * @param[in] length ����� ������ (������ ���� > 0).
  * @param[in] symbols ����� ���������� �������� (�� ������ ���� ������).
  * @return true - ������ ������� ������������, false - ������ ���������.
  */
bool generatePassword(std::string& password, int length, const std::string& symbols);