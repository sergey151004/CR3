/* Продолжение задания: Обратная польская запись. Дерево выражения. */

#pragma once

#include <string>

struct Node {
    int value;     // число или код операции
    Node* left;
    Node* right;

    explicit Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

/**
 * @brief Строит дерево выражения по обратной польской записи.
 * @param rpn Выражение в обратной польской записи.
 * @return Указатель на корень дерева.
 */
Node* buildExpressionTree(const std::string& rpn);

/**
 * @brief Упрощает дерево, заменяя поддеревья с делением и остатком на их значения.
 * @param node Корень дерева для упрощения.
 */
void simplifyTree(Node* node);