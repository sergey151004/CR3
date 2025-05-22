/* ����������� �������: ��������� ������� */

#include <iostream>
#include "PasswordGenerator.h"

int main() {
	std::cout << "�������� ������� ��������� ������:\n";
	std::cout << "1 - ˸���� (������ �������� �����)\n";
	std::cout << "2 - ������� (����� + �����)\n";
	std::cout << "3 - ������� (����� + ����� + �������)\n";
	std::cout << "������� ������� ��������� (1-3): ";

	int level = 0;
	if (!(std::cin >> level)) {
		std::cerr << "������: ������� �� �����.\n";
		return 1;
	}

	if (level < 1 || level > 3) {
		std::cerr << "������: ������� ��������� ������ ���� �� 1 �� 3.\n";
		return 1;
	}

	PasswordGenerator generator;

	std::string password;
	if (!generator.GeneratePassword(level, password)) {
		std::cerr << "������ ��� ��������� ������.\n";
		return 1;
	}

	std::cout << "��������������� ������: " << password << "\n";

	return 0;
}
