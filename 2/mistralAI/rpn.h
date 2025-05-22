#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H

#include <string>

/**
 * @struct Node
 * @brief ��������� ��� ���� ������ ���������.
 */
struct Node {
    int value;
    Node* left;
    Node* right;
};

/**
 * @class ExpressionTree
 * @brief ����� ��� ���������� � �������������� ������ ���������.
 */
class ExpressionTree {
public:
    /**
     * @brief ������ ������ ��������� �� ������ � �������� �������� ������.
     * @param expression ������ � �������� �������� ������.
     * @return ��������� �� ������ ������.
     */
    Node* buildTree(const std::string& expression);

    /**
     * @brief ����������� ������, ������ �������� �������.
     * @param root ��������� �� ������ ������.
     * @return ��������� �� ������ ���������������� ������.
     */
    Node* transformTree(Node* root);

private:
    /**
     * @brief ���������, �������� �� ������ ����������.
     * @param c ������ ��� ��������.
     * @return true, ���� ������ �������� ����������, ����� false.
     */
    bool isOperator(char c);

    /**
     * @brief ��������� �������� � ���� ���������.
     * @param a ������ �������.
     * @param b ������ �������.
     * @param op ��������.
     * @return ��������� ���������� ���������.
     */
    int applyOperator(int a, int b, char op);
};

#endif // EXPRESSIONTREE_H
