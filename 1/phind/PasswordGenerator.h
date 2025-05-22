// PasswordGenerator.h
#ifndef PASSWORDGENERATOR_H_
#define PASSWORDGENERATOR_H_

/**
 * @file PasswordGenerator.h
 * @brief ����� ��� ��������� ������� ������ ���������
 * @author [���� ���]
 */

#include <string>
#include <random>

class PasswordGenerator {
public:
    /**
     * ������ ��������� ������
     */
    enum class Level {
        EASY = 8,
        MEDIUM = 12,
        STRONG = 16
    };

    /**
     * ���������� ��������� ������ ��������� ���������
     * @param level �������� ������� ���������
     * @return ��������������� ������
     * @throws std::invalid_argument ���� ������� ��������� �����������
     */
    static std::string generatePassword(Level level);

private:
    // ��������� ��� ���� ������� ������ �������
    static const int EASY_LENGTH;
    static const int MEDIUM_LENGTH;
    static const int STRONG_LENGTH;

    // ������ �������� ��� ���������
    static const std::string LOWERCASE;
    static const std::string UPPERCASE;
    static const std::string NUMBERS;
    static const std::string SPECIAL_CHARS;

    /**
     * �������� ��������� ������ �� �������� ������
     * @param chars ������ � ���������� ���������
     * @return ��������� ������ �� ������
     */
    static char getRandomChar(const std::string& chars);

    /**
     * ������������ ������� ���� ����������� ����� �������� � ������
     * @param password ������� ������
     * @param chars ����� �������� ��� ����������
     * @return ����������� ������ � ��������������� �������� ���� ����� ��������
     */
    static std::string ensureCharacterTypes(std::string password, const std::string& chars);
};

#endif  // PASSWORDGENERATOR_H_