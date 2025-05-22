/* ����������� �������: �������� �������� ������. ������ ���������. */

#pragma once

#include <string>

struct Node {
    int value;     // ����� ��� ��� ��������
    Node* left;
    Node* right;

    explicit Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

/**
 * @brief ������ ������ ��������� �� �������� �������� ������.
 * @param rpn ��������� � �������� �������� ������.
 * @return ��������� �� ������ ������.
 */
Node* buildExpressionTree(const std::string& rpn);

/**
 * @brief �������� ������, ������� ���������� � �������� � �������� �� �� ��������.
 * @param node ������ ������ ��� ���������.
 */
void simplifyTree(Node* node);