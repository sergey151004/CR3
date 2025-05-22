#ifndef PASSWORDGENERATOR_H
#define PASSWORDGENERATOR_H

#include <string>

/**
 * @class PasswordGenerator
 * @brief ����� ��� ��������� ������� ��������� ���������.
 */
class PasswordGenerator {
public:
    /**
     * @brief ���������� ������ ��������� ������ ���������.
     * @param level ������� ��������� ������ (1 - �������, 2 - �������, 3 - �������).
     * @return ��������������� ������.
     */
    std::string generatePassword(int level);
};

#endif // PASSWORDGENERATOR_H
