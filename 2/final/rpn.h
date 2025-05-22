/**
 * @file   rpn.h
 * @brief  ������������ ���� ��� ������ � �������� �������� �������� (RPN).
 */
#ifndef RPN_H
#define RPN_H

#include <iostream>
#include <stack>
#include <string>

namespace rpn {

    /**
     * @struct Node
     * @brief ���� ������ ������� RPN-���������.
     */
    struct Node {
        int val;      ///< �������� ���� ��� ��� ��������
        Node* left;   ///< ��������� �� ����� �������
        Node* right;  ///< ��������� �� ������ �������

        Node(int v);
        ~Node();
    };

    /**
     * @brief ������� ���� �����, ������ ��� ������� Node.
     */
    void cleanupStack(std::stack<Node*>& s);

    /**
     * @brief ������ ������ ������� �� ����� � RPN-����������.
     */
    Node* buildTree(const std::string& filename);

    /**
     * @brief ���������� ��������� �������� RPN-��������� � ������.
     */
    bool eval(Node* node, int& result);

    /**
     * @brief �������� ������, �������� ���� �������� '/' � '%'.
     */
    void eliminateDivisions(Node*& node);

    /**
     * @brief ������� ������ � ��������� ����� ��� �������.
     */
    void printTreeInfix(Node* node, std::ostream& out);

} // namespace rpn

#endif // RPN_H