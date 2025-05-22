/**
 * @file   rpn.h
 * @brief  Заголовочный файл для работы с обратной польской нотацией (RPN).
 */
#ifndef RPN_H
#define RPN_H

#include <iostream>
#include <stack>
#include <string>

namespace rpn {

    /**
     * @struct Node
     * @brief Узел дерева разбора RPN-выражения.
     */
    struct Node {
        int val;      ///< Значение узла или код операции
        Node* left;   ///< Указатель на левый потомок
        Node* right;  ///< Указатель на правый потомок

        Node(int v);
        ~Node();
    };

    /**
     * @brief Очищает стек узлов, удаляя все объекты Node.
     */
    void cleanupStack(std::stack<Node*>& s);

    /**
     * @brief Строит дерево разбора из файла с RPN-выражением.
     */
    Node* buildTree(const std::string& filename);

    /**
     * @brief Рекурсивно вычисляет значение RPN-выражения в дереве.
     */
    bool eval(Node* node, int& result);

    /**
     * @brief Упрощает дерево, вычисляя узлы операций '/' и '%'.
     */
    void eliminateDivisions(Node*& node);

    /**
     * @brief Выводит дерево в инфиксной форме для отладки.
     */
    void printTreeInfix(Node* node, std::ostream& out);

} // namespace rpn

#endif // RPN_H