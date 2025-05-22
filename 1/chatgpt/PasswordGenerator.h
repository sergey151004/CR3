/* ����������� �������: ��������� ������� */

#ifndef PASSWORD_GENERATOR_H
#define PASSWORD_GENERATOR_H

#include <string>

/**
 * @brief ����� ��������� ������� �� ��� ������� ���������.
 */
class PasswordGenerator {
public:
	/**
	 * @brief ���������� ������ �� ������ ���������� ������ ���������.
	 * 
	 * @param level ������� ��������� (1 - �����, 2 - �������, 3 - �������)
	 * @param password ������ �� ������, ���� ����� ������� ���������
	 * @return true - ���� ��������� �������, false - ��� ������ ������� ������
	 */
	bool GeneratePassword(int level, std::string& password) const;

private:
	/**
	 * @brief ���������� ������ ���������� �������� ��� ��������� ������.
	 * 
	 * @param level ������� ���������
	 * @return ����� ��������, ���������� �� ���� ������
	 */
	std::string GetCharacterSet(int level) const;

	/**
	 * @brief ���������� ����� ������ ��� ��������� ������.
	 * 
	 * @param level ������� ���������
	 * @return ����� ������
	 */
	int GetPasswordLength(int level) const;
};

#endif  // PASSWORD_GENERATOR_H
